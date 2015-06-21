#include "../../stdafx.h"
#include "../Headers/Engine.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "platform/platform.h"
#include "console/console.h"
#include "console/consoleObject.h"

// #pragma unmanaged
#pragma managed(pop)

namespace EngineCon = Con;

using namespace System::Runtime::InteropServices;
typedef Platform EnginePlatform;

extern S32 QSORT_CALLBACK ACRCompare(const void *aptr, const void *bptr);

void IJWLayer::Engine::Platform::setMainDotCsDir(String^ Dir)
{
   char* _Dir = (char*)Marshal::StringToHGlobalAnsi(Dir).ToPointer();
   EnginePlatform::setMainDotCsDir(_Dir);
}

bool IJWLayer::Engine::Platform::setCurrentDirectory(String^ Dir)
{
   char* _Dir = (char*)Marshal::StringToHGlobalAnsi(Dir).ToPointer();
   return EnginePlatform::setCurrentDirectory(_Dir);
}

String^ IJWLayer::Engine::Platform::expandPath(String^ path)
{
   char* _path = (char*)Marshal::StringToHGlobalAnsi(path).ToPointer();

   char* ret = EngineCon::getReturnBuffer(1024);
   EngineCon::expandPath(ret, 1024, _path);
   Marshal::FreeHGlobal(System::IntPtr(_path));
   return gcnew String(ret);
}

String^ IJWLayer::Engine::Platform::collapsePath(String^ path)
{
   char* _path = (char*)Marshal::StringToHGlobalAnsi(path).ToPointer();

   char* ret = EngineCon::getReturnBuffer(1024);
   EngineCon::collapsePath(ret, 1024, _path);
   Marshal::FreeHGlobal(System::IntPtr(_path));
   return gcnew String(ret);
}

void IJWLayer::Engine::Platform::addPathExpando(String^ expando, String^ path)
{
   char* _path = (char*)Marshal::StringToHGlobalAnsi(path).ToPointer();
   char* _expando = (char*)Marshal::StringToHGlobalAnsi(expando).ToPointer();

   EngineCon::addPathExpando(_expando, _path);
   Marshal::FreeHGlobal(System::IntPtr(_path));
   Marshal::FreeHGlobal(System::IntPtr(_expando));
}

void IJWLayer::Engine::Platform::removePathExpando(String^ path)
{
   char* _path = (char*)Marshal::StringToHGlobalAnsi(path).ToPointer();

   EngineCon::removePathExpando(_path);
   Marshal::FreeHGlobal(System::IntPtr(_path));
}

bool IJWLayer::Engine::Platform::isPathExpando(String^ expando)
{
   char* _expando = (char*)Marshal::StringToHGlobalAnsi(expando).ToPointer();

   bool res = EngineCon::isPathExpando(_expando);
   Marshal::FreeHGlobal(System::IntPtr(_expando));
   return res;
}

int IJWLayer::Engine::Platform::getPathExpandoCount()
{
   return EngineCon::getPathExpandoCount();
}

String^ IJWLayer::Engine::Platform::getPathExpandoKey(int expandoIndex)
{
   // Is the expando index in range?
   if (expandoIndex < 0 || expandoIndex >= (S32)EngineCon::getPathExpandoCount())
   {
      // No, so warn.
      EngineCon::warnf("getPathExpandoKey() - Expando index of '%d' is out of bounds.  Current expando count is '%d'.",
         expandoIndex,
         EngineCon::getPathExpandoCount());
      return nullptr;
   }

   // Fetch path expando key.
   return gcnew String(EngineCon::getPathExpandoKey(expandoIndex));
}

String^ IJWLayer::Engine::Platform::getPathExpandoValue(int expandoIndex)
{
   // Is the expando index in range?
   if (expandoIndex < 0 || expandoIndex >= (S32)EngineCon::getPathExpandoCount())
   {
      // No, so warn.
      EngineCon::warnf("getPathExpandoKey() - Expando index of '%d' is out of bounds.  Current expando count is '%d'.",
         expandoIndex,
         EngineCon::getPathExpandoCount());
      return nullptr;
   }

   // Fetch path expando key.
   return gcnew String(EngineCon::getPathExpandoValue(expandoIndex));
}

bool IJWLayer::Engine::Platform::isiPhoneBuild()
{
#ifdef	TORQUE_OS_IOS
   return true;
#else
   return false;
#endif	//TORQUE_OS_IOS
}

String^ IJWLayer::Engine::Platform::enumerateConsoleClasses(String^ baseClass)
{
   char* _baseClass = (char*)Marshal::StringToHGlobalAnsi(baseClass).ToPointer();
   
   AbstractClassRep *base = NULL;
   if (baseClass != nullptr)
   {
      base = AbstractClassRep::findClassRep(_baseClass);
      if (!base)
         return "";
   }

   Vector<AbstractClassRep*> classes;
   U32 bufSize = 0;
   for (AbstractClassRep *rep = AbstractClassRep::getClassList(); rep; rep = rep->getNextClass())
   {
      if (!base || rep->isClass(base))
      {
         classes.push_back(rep);
         bufSize += dStrlen(rep->getClassName()) + 1;
      }
   }

   if (!classes.size())
      return "";

   dQsort(classes.address(), classes.size(), sizeof(AbstractClassRep*), ACRCompare);

   char* ret = EngineCon::getReturnBuffer(bufSize);
   dStrcpy(ret, classes[0]->getClassName());
   for (U32 i = 0; i< (U32)classes.size(); i++)
   {
      dStrcat(ret, "\t");
      dStrcat(ret, classes[i]->getClassName());
   }

   return gcnew String(ret);
}
