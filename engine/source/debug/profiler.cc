//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#include "platform/platform.h"
#include "debug/profiler.h"
#include "string/stringTable.h"
#include <stdlib.h> // gotta use malloc and free directly
#include <string.h>
#include "console/console.h"
#include "collection/vector.h"
#include "io/fileStream.h"
#include "platform/threads/thread.h"

#include "profiler_Binding.h"

#ifdef TORQUE_ENABLE_PROFILER
ProfilerRootData *ProfilerRootData::sRootList = NULL;
Profiler *gProfiler = NULL;

#ifdef TORQUE_MULTITHREAD
ThreadIdent gMainThread = 0;
#endif

#if defined(TORQUE_SUPPORTS_VC_INLINE_X86_ASM)
// platform specific get hires times...
void startHighResolutionTimer(U32 time[2])
{
   //time[0] = Platform::getRealMilliseconds();

   __asm
   {
      push eax
      push edx
      push ecx
      rdtsc
      mov ecx, time
      mov DWORD PTR [ecx], eax
      mov DWORD PTR [ecx + 4], edx
      pop ecx
      pop edx
      pop eax
   }
}

U32 endHighResolutionTimer(U32 time[2])
{
   U32 ticks;
   //ticks = Platform::getRealMilliseconds() - time[0];
   //return ticks;

   __asm
   {
      push  eax
      push  edx
      push  ecx
      //db    0fh, 31h
      rdtsc
      mov   ecx, time
      sub   edx, DWORD PTR [ecx+4]
      sbb   eax, DWORD PTR [ecx]
      mov   DWORD PTR ticks, eax
      pop   ecx
      pop   edx
      pop   eax
   }
   return ticks;
}

#elif defined(TORQUE_SUPPORTS_GCC_INLINE_X86_ASM)

// platform specific get hires times...
void startHighResolutionTimer(U32 time[2])
{
   __asm__ __volatile__(
      "rdtsc\n"
      : "=a" (time[0]), "=d" (time[1])
      );
}

U32 endHighResolutionTimer(U32 time[2])
{
   U32 ticks;
   __asm__ __volatile__(
      "rdtsc\n"
      "sub  0x4(%%ecx),  %%edx\n"
      "sbb  (%%ecx),  %%eax\n"
      : "=a" (ticks) : "c" (time)
      );
   return ticks;
}

#elif defined(TORQUE_OS_MAC_CARB)

#include <Timer.h>
#include <Math64.h>

void startHighResolutionTimer(U32 time[2]) {
    UnsignedWide t;
    Microseconds(&t);
    time[0] = t.lo;
    time[1] = t.hi;
}

U32 endHighResolutionTimer(U32 time[2])  {
   UnsignedWide t;
   Microseconds(&t);
   return t.lo - time[0]; 
   // given that we're returning a 32 bit integer, and this is unsigned subtraction... 
   // it will just wrap around, we don't need the upper word of the time.
   // NOTE: the code assumes that more than 3 hrs will not go by between calls to startHighResolutionTimer() and endHighResolutionTimer().
   // I mean... that damn well better not happen anyway.
}

#elif defined(TORQUE_OS_IOS)

//-Mat added high resolution iPhone timer 
#import <mach/mach_time.h>
#include <Math64.h>

void startHighResolutionTimer(U32 time[2]) {
    time[0] = mach_absolute_time();
}

U32 endHighResolutionTimer(U32 time[2])  {
    return mach_absolute_time() - time[0];
}


#else

void startHighResolutionTimer(U32 time[2])
{
}

U32 endHighResolutionTimer(U32 time[2])
{
   return 1;
}

#endif

Profiler::Profiler()
{
   mMaxStackDepth = MaxStackDepth;
   mCurrentHash = 0;

   mCurrentProfilerData = (ProfilerData *) malloc(sizeof(ProfilerData));
   mCurrentProfilerData->mRoot = NULL;
   mCurrentProfilerData->mNextForRoot = NULL;
   mCurrentProfilerData->mNextProfilerData = NULL;
   mCurrentProfilerData->mNextHash = NULL;
   mCurrentProfilerData->mParent = NULL;
   mCurrentProfilerData->mNextSibling = NULL;
   mCurrentProfilerData->mFirstChild = NULL;
   mCurrentProfilerData->mLastSeenProfiler = NULL;
   mCurrentProfilerData->mHash = 0;
   mCurrentProfilerData->mSubDepth = 0;
   mCurrentProfilerData->mInvokeCount = 0;
   mCurrentProfilerData->mTotalTime = 0;
   mCurrentProfilerData->mSubTime = 0;
   mRootProfilerData = mCurrentProfilerData;

   for(U32 i = 0; i < ProfilerData::HashTableSize; i++)
      mCurrentProfilerData->mChildHash[i] = 0;

   mProfileList = NULL;

   mEnabled = false;
   mStackDepth = 0;
   mNextEnable = false;
   gProfiler = this;
   mDumpToConsole   = false;
   mDumpToFile      = false;
   mDumpFileName[0] = '\0';

#ifdef TORQUE_MULTITHREAD
   gMainThread = ThreadManager::getCurrentThreadId();
#endif
}

Profiler::~Profiler()
{
   reset();
   free(mRootProfilerData);
   gProfiler = NULL;
}

void Profiler::reset()
{
   mEnabled = false; // in case we're in a profiler call.
   while(mProfileList)
   {
      free(mProfileList);
      mProfileList = NULL;
   }
   for(ProfilerRootData *walk = ProfilerRootData::sRootList; walk; walk = walk->mNextRoot)
   {
      walk->mFirstProfilerData = 0;
      walk->mTotalTime = 0;
      walk->mSubTime = 0;
      walk->mTotalInvokeCount = 0;
   }
   mCurrentProfilerData = mRootProfilerData;
   mCurrentProfilerData->mNextForRoot = 0;
   mCurrentProfilerData->mFirstChild = 0;
   for(U32 i = 0; i < ProfilerData::HashTableSize; i++)
      mCurrentProfilerData->mChildHash[i] = 0;
   mCurrentProfilerData->mInvokeCount = 0;
   mCurrentProfilerData->mTotalTime = 0;
   mCurrentProfilerData->mSubTime = 0;
   mCurrentProfilerData->mSubDepth = 0;
   mCurrentProfilerData->mLastSeenProfiler = 0;
}

static Profiler aProfiler; // allocate the global profiler

ProfilerRootData::ProfilerRootData(const char *name)
{
   for(ProfilerRootData *walk = sRootList; walk; walk = walk->mNextRoot)
      if(!dStrcmp(walk->mName, name))
         Platform::debugBreak();

   mName = name;
   mNameHash = _StringTable::hashString(name);
   mNextRoot = sRootList;
   sRootList = this;
   mTotalTime = 0;
   mTotalInvokeCount = 0;
   mFirstProfilerData = NULL;
   mEnabled = true;
}

void Profiler::validate()
{
   for(ProfilerRootData *walk = ProfilerRootData::sRootList; walk; walk = walk->mNextRoot)
   {
      for(ProfilerData *dp = walk->mFirstProfilerData; dp; dp = dp->mNextForRoot)
      {
         if(dp->mRoot != walk)
            Platform::debugBreak();
         // check if it's in the parent's list...
         ProfilerData *wk;
         for(wk = dp->mParent->mFirstChild; wk; wk = wk->mNextSibling)
            if(wk == dp)
               break;
         if(!wk)
            Platform::debugBreak();
         for(wk = dp->mParent->mChildHash[walk->mNameHash & (ProfilerData::HashTableSize - 1)] ;
               wk; wk = wk->mNextHash)
            if(wk == dp)
               break;
         if(!wk)
            Platform::debugBreak();
      }
   }
}

void Profiler::hashPush(ProfilerRootData *root)
{
#ifdef TORQUE_MULTITHREAD
   // Ignore non-main-thread profiler activity.
   if(! ThreadManager::isCurrentThread(gMainThread) )
      return;
#endif

   mStackDepth++;
   AssertFatal(mStackDepth <= (S32)mMaxStackDepth,
                  "Stack overflow in profiler.  You may have mismatched PROFILE_START and PROFILE_ENDs");
   if(!mEnabled)
      return;

   ProfilerData *nextProfiler = NULL;
   if(!root->mEnabled || mCurrentProfilerData->mRoot == root)
   {
      mCurrentProfilerData->mSubDepth++;
      return;
   }

   if(mCurrentProfilerData->mLastSeenProfiler &&
            mCurrentProfilerData->mLastSeenProfiler->mRoot == root)
      nextProfiler = mCurrentProfilerData->mLastSeenProfiler;

   if(!nextProfiler)
   {
      // first see if it's in the hash table...
      U32 index = root->mNameHash & (ProfilerData::HashTableSize - 1);
      nextProfiler = mCurrentProfilerData->mChildHash[index];
      while(nextProfiler)
      {
         if(nextProfiler->mRoot == root)
            break;
         nextProfiler = nextProfiler->mNextHash;
      }
      if(!nextProfiler)
      {
         nextProfiler = (ProfilerData *) malloc(sizeof(ProfilerData));
         for(U32 i = 0; i < ProfilerData::HashTableSize; i++)
            nextProfiler->mChildHash[i] = 0;

         nextProfiler->mRoot = root;
         nextProfiler->mNextForRoot = root->mFirstProfilerData;
         root->mFirstProfilerData = nextProfiler;

         nextProfiler->mNextProfilerData = mProfileList;
         mProfileList = nextProfiler;

         nextProfiler->mNextHash = mCurrentProfilerData->mChildHash[index];
         mCurrentProfilerData->mChildHash[index] = nextProfiler;

         nextProfiler->mParent = mCurrentProfilerData;
         nextProfiler->mNextSibling = mCurrentProfilerData->mFirstChild;
         mCurrentProfilerData->mFirstChild = nextProfiler;
         nextProfiler->mFirstChild = NULL;
         nextProfiler->mLastSeenProfiler = NULL;
         nextProfiler->mHash = root->mNameHash;
         nextProfiler->mInvokeCount = 0;
         nextProfiler->mTotalTime = 0;
         nextProfiler->mSubTime = 0;
         nextProfiler->mSubDepth = 0;
      }
   }
   root->mTotalInvokeCount++;
   nextProfiler->mInvokeCount++;
   startHighResolutionTimer(nextProfiler->mStartTime);
   mCurrentProfilerData->mLastSeenProfiler = nextProfiler;
   mCurrentProfilerData = nextProfiler;
}

void Profiler::enable(bool enabled)
{
   mNextEnable = enabled;

   if ( enabled )
       Con::printf( "Profiler is on." );
   else
       Con::printf("Profiler is off." );
}

void Profiler::dumpToConsole()
{
   mDumpToConsole = true;
   mDumpToFile = false;
   mDumpFileName[0] = '\0';
}

void Profiler::dumpToFile(const char* fileName)
{
   AssertFatal(dStrlen(fileName) < DumpFileNameLength, "Error, dump filename too long");
   mDumpToFile = true;
   mDumpToConsole = false;
   dStrcpy(mDumpFileName, fileName);
}

void Profiler::hashPop()
{
#ifdef TORQUE_MULTITHREAD
   // Ignore non-main-thread profiler activity.
   if(! ThreadManager::isCurrentThread(gMainThread) )
      return;
#endif

   mStackDepth--;
   AssertFatal(mStackDepth >= 0, "Stack underflow in profiler.  You may have mismatched PROFILE_START and PROFILE_ENDs");
   if(mEnabled)
   {
      if(mCurrentProfilerData->mSubDepth)
      {
         mCurrentProfilerData->mSubDepth--;
         return;
      }
      F64 fElapsed = endHighResolutionTimer(mCurrentProfilerData->mStartTime);
      mCurrentProfilerData->mTotalTime += fElapsed;
      mCurrentProfilerData->mParent->mSubTime += fElapsed; // mark it in the parent as well...
      mCurrentProfilerData->mRoot->mTotalTime += fElapsed;
      if(mCurrentProfilerData->mParent->mRoot)
         mCurrentProfilerData->mParent->mRoot->mSubTime += fElapsed; // mark it in the parent as well...
      mCurrentProfilerData = mCurrentProfilerData->mParent;
   }
   if(mStackDepth == 0)
   {
      // apply the next enable...
      if(mDumpToConsole || mDumpToFile)
      {
         dump();
         startHighResolutionTimer(mCurrentProfilerData->mStartTime);
      }
      if(!mEnabled && mNextEnable)
         startHighResolutionTimer(mCurrentProfilerData->mStartTime);
      mEnabled = mNextEnable;
   }
}

static S32 QSORT_CALLBACK rootDataCompare(const void *s1, const void *s2)
{
   const ProfilerRootData *r1 = *((ProfilerRootData **) s1);
   const ProfilerRootData *r2 = *((ProfilerRootData **) s2);
   return (S32)((r2->mTotalTime - r2->mSubTime) - (r1->mTotalTime - r1->mSubTime));
}

static void profilerDataDumpRecurse(ProfilerData *data, char *buffer, U32 bufferLen, F64 totalTime)
{
   // dump out this one:
   Con::printf("%7.3f %7.3f %8d %s%s",
         100 * data->mTotalTime / totalTime,
         100 * (data->mTotalTime - data->mSubTime) / totalTime,
         data->mInvokeCount,
         buffer,
         data->mRoot ? data->mRoot->mName : "ROOT" );
   data->mTotalTime = 0;
   data->mSubTime = 0;
   data->mInvokeCount = 0;

   buffer[bufferLen] = ' ';
   buffer[bufferLen+1] = ' ';
   buffer[bufferLen+2] = 0;
   // sort data's children...
   ProfilerData *list = NULL;
   while(data->mFirstChild)
   {
      ProfilerData *ins = data->mFirstChild;
      data->mFirstChild = ins->mNextSibling;
      ProfilerData **walk = &list;
      while(*walk && (*walk)->mTotalTime > ins->mTotalTime)
         walk = &(*walk)->mNextSibling;
      ins->mNextSibling = *walk;
      *walk = ins;
   }
   data->mFirstChild = list;
   while(list)
   {
      if(list->mInvokeCount)
         profilerDataDumpRecurse(list, buffer, bufferLen + 2, totalTime);
      list = list->mNextSibling;
   }
   buffer[bufferLen] = 0;
}

static void profilerDataDumpRecurseFile(ProfilerData *data, char *buffer, U32 bufferLen, F64 totalTime, FileStream& fws)
{
   char pbuffer[256];
   dSprintf(pbuffer, 255, "%7.3f %7.3f %8d %s%s\n",
         100 * data->mTotalTime / totalTime,
         100 * (data->mTotalTime - data->mSubTime) / totalTime,
         data->mInvokeCount,
         buffer,
         data->mRoot ? data->mRoot->mName : "ROOT" );
   fws.write(dStrlen(pbuffer), pbuffer);
   data->mTotalTime = 0;
   data->mSubTime = 0;
   data->mInvokeCount = 0;

   buffer[bufferLen] = ' ';
   buffer[bufferLen+1] = ' ';
   buffer[bufferLen+2] = 0;
   // sort data's children...
   ProfilerData *list = NULL;
   while(data->mFirstChild)
   {
      ProfilerData *ins = data->mFirstChild;
      data->mFirstChild = ins->mNextSibling;
      ProfilerData **walk = &list;
      while(*walk && (*walk)->mTotalTime > ins->mTotalTime)
         walk = &(*walk)->mNextSibling;
      ins->mNextSibling = *walk;
      *walk = ins;
   }
   data->mFirstChild = list;
   while(list)
   {
      if(list->mInvokeCount)
         profilerDataDumpRecurseFile(list, buffer, bufferLen + 2, totalTime, fws);
      list = list->mNextSibling;
   }
   buffer[bufferLen] = 0;
}


void Profiler::dump()
{
   bool enableSave = mEnabled;
   mEnabled = false;
   mStackDepth++;
   // may have some profiled calls... gotta turn em off.

   Vector<ProfilerRootData *> rootVector;
   F64 totalTime = 0;
   for(ProfilerRootData *walk = ProfilerRootData::sRootList; walk; walk = walk->mNextRoot)
   {
      totalTime += walk->mTotalTime - walk->mSubTime;
      rootVector.push_back(walk);
   }
//-Mat no sort, makes it easier to compare
   dQsort((void *)rootVector.address(), rootVector.size(), sizeof(ProfilerRootData *), rootDataCompare);


   if (mDumpToConsole == true)
   {
      Con::printf("Profiler Data Dump:");
      Con::printf("Ordered by non-sub total time -");
      Con::printf("%%NSTime  %% Time  Invoke #  Name");
      for(U32 i = 0; i < (U32)rootVector.size(); i++)
      {
         Con::printf("%7.3f %7.3f %8d %s",
                     100 * (rootVector[i]->mTotalTime - rootVector[i]->mSubTime) / totalTime,
                     100 * rootVector[i]->mTotalTime / totalTime,
                     rootVector[i]->mTotalInvokeCount,
                     rootVector[i]->mName);
         rootVector[i]->mTotalInvokeCount = 0;
         rootVector[i]->mTotalTime = 0;
         rootVector[i]->mSubTime = 0;
      }
      Con::printf("");
      Con::printf("Ordered by stack trace total time -");
      Con::printf("%% Time  %% NSTime  Invoke #  Name");

      mCurrentProfilerData->mTotalTime = endHighResolutionTimer(mCurrentProfilerData->mStartTime);

      char depthBuffer[MaxStackDepth * 2 + 1];
      depthBuffer[0] = 0;
      profilerDataDumpRecurse(mCurrentProfilerData, depthBuffer, 0, totalTime);
      mEnabled = enableSave;
      mStackDepth--;
   }
   else if (mDumpToFile == true && mDumpFileName[0] != '\0')
   {
      FileStream fws;
      bool success = fws.open(mDumpFileName, FileStream::Write);
      AssertFatal(success, "Nuts! Cannot write profile dump to specified file!");
         char buffer[1024];

         dStrcpy(buffer, "Profiler Data Dump:\n");
         fws.write(dStrlen(buffer), buffer);
         dStrcpy(buffer, "Ordered by non-sub total time -\n");
         fws.write(dStrlen(buffer), buffer);
         dStrcpy(buffer, "%%NSTime  %% Time  Invoke #  Name\n");
         fws.write(dStrlen(buffer), buffer);

         for(U32 i = 0; i < (U32)rootVector.size(); i++)
         {
            dSprintf(buffer, 1023, "%7.3f %7.3f %8d %s\n",
                     100 * (rootVector[i]->mTotalTime - rootVector[i]->mSubTime) / totalTime,
                     100 * rootVector[i]->mTotalTime / totalTime,
                     rootVector[i]->mTotalInvokeCount,
                     rootVector[i]->mName);
            fws.write(dStrlen(buffer), buffer);

            rootVector[i]->mTotalInvokeCount = 0;
            rootVector[i]->mTotalTime = 0;
            rootVector[i]->mSubTime = 0;
         }
         dStrcpy(buffer, "\nOrdered by non-sub total time -\n");
         fws.write(dStrlen(buffer), buffer);
         dStrcpy(buffer, "%%NSTime  %% Time  Invoke #  Name\n");
         fws.write(dStrlen(buffer), buffer);

      mCurrentProfilerData->mTotalTime = endHighResolutionTimer(mCurrentProfilerData->mStartTime);

      char depthBuffer[MaxStackDepth * 2 + 1];
      depthBuffer[0] = 0;
      profilerDataDumpRecurseFile(mCurrentProfilerData, depthBuffer, 0, totalTime, fws);
      mEnabled = enableSave;
      mStackDepth--;

      fws.close();
   }

   mDumpToConsole = false;
   mDumpToFile    = false;
   mDumpFileName[0] = '\0';
    
}

void Profiler::enableMarker(const char *marker, bool enable)
{
   reset();
   U32 markerLen = dStrlen(marker);
   if(markerLen == 0)
      return;
   bool sn = marker[markerLen - 1] == '*';
   for(ProfilerRootData *data = ProfilerRootData::sRootList; data; data = data->mNextRoot)
   {
      if(sn)
      {
         if(!dStrncmp(marker, data->mName, markerLen - 1))
            data->mEnabled = enable;
      }
      else
      {
         if(!dStrcmp(marker, data->mName))
            data->mEnabled = enable;
      }
   }
}

#endif
