#include "Stdafx.h"
#include "MessageWrappers.h"
#include "MarshalHelper.h"

using namespace System::Runtime::InteropServices;

String^ IJWLayer::MessageWrapper::getType()
{
   if (!IsAlive())
      return nullptr;

   GetObjectPtr()->getType();
}

void IJWLayer::MessageWrapper::addReference()
{
   if (IsAlive())
      GetObjectPtr()->addReference();
}

void IJWLayer::MessageWrapper::freeReference()
{
   if (IsAlive())
      GetObjectPtr()->freeReference();
}

void IJWLayer::MessageVectorWrapper::clear()
{
   if (IsAlive())
      GetObjectPtr()->clear();
}

void IJWLayer::MessageVectorWrapper::pushBackLine(String^ msg, int tag)
{
   if (!IsAlive())
      return;
   char* _msg = (char*)Marshal::StringToHGlobalAnsi(msg).ToPointer();
   GetObjectPtr()->pushBackLine(_msg, tag);
}

void IJWLayer::MessageVectorWrapper::pushBackLine(String^ msg)
{
   pushBackLine(msg, 0);
}

bool IJWLayer::MessageVectorWrapper::popBackLine()
{
   if (!IsAlive())
      return false;

   if (GetObjectPtr()->getNumLines() <= 0) {
      Con::errorf(ConsoleLogEntry::General, "MessageVector::popBackLine(): underflow");
      return false;
   }

   GetObjectPtr()->popBackLine();
   return true;
}

void IJWLayer::MessageVectorWrapper::pushFrontLine(String^ msg, int tag)
{
   if (!IsAlive())
      return;
   char* _msg = (char*)Marshal::StringToHGlobalAnsi(msg).ToPointer();
   GetObjectPtr()->pushFrontLine(_msg, tag);
}

void IJWLayer::MessageVectorWrapper::pushFrontLine(String^ msg)
{
   pushFrontLine(msg, 0);
}

bool IJWLayer::MessageVectorWrapper::popFrontLine()
{
   if (!IsAlive())
      return false;

   if (GetObjectPtr()->getNumLines() <= 0) {
      Con::errorf(ConsoleLogEntry::General, "MessageVector::popFrontLine(): underflow");
      return false;
   }

   GetObjectPtr()->popFrontLine();
   return true;
}

bool IJWLayer::MessageVectorWrapper::insertLine(int pos, String^ msg, int tag)
{
   if (!IsAlive())
      return false;
   char* _msg = (char*)Marshal::StringToHGlobalAnsi(msg).ToPointer();
   GetObjectPtr()->insertLine(pos, _msg, tag);
   return true;
}

bool IJWLayer::MessageVectorWrapper::insertLine(int pos, String^ msg)
{
   return insertLine(pos, msg, 0);
}

bool IJWLayer::MessageVectorWrapper::deleteLine(int lineIndex)
{
   if (!IsAlive())
      return false;

   if (lineIndex >= GetObjectPtr()->getNumLines())
      return false;

   GetObjectPtr()->deleteLine(lineIndex);
   return true;
}

void IJWLayer::MessageVectorWrapper::dump(String^ filename, String^ header)
{
   if (!IsAlive())
      return;

   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   char* _header = (char*)Marshal::StringToHGlobalAnsi(header).ToPointer();
   GetObjectPtr()->dump(_filename, _header);
}

void IJWLayer::MessageVectorWrapper::dump(String^ filename)
{
   if (!IsAlive())
      return;

   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   GetObjectPtr()->dump(_filename);
}

int IJWLayer::MessageVectorWrapper::getNumLines()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getNumLines();
}

String^ IJWLayer::MessageVectorWrapper::getLineTextByTag(int tag)
{
   if (!IsAlive())
      return nullptr;

   for (U32 i = 0; i < GetObjectPtr()->getNumLines(); i++)
      if (GetObjectPtr()->getLine(i).messageTag == tag)
         return gcnew String(GetObjectPtr()->getLine(i).message);
   return nullptr;
}

int IJWLayer::MessageVectorWrapper::getLineIndexByTag(int tag)
{
   if (!IsAlive())
      return -1;

   for (U32 i = 0; i < GetObjectPtr()->getNumLines(); i++)
      if (GetObjectPtr()->getLine(i).messageTag == tag)
         return i;
   return -1;
}

String^ IJWLayer::MessageVectorWrapper::getLineText(int index)
{
   if (!IsAlive())
      return nullptr;

   if (index >= GetObjectPtr()->getNumLines()) {
      Con::errorf(ConsoleLogEntry::General, "MessageVector::getLineText(con): out of bounds line");
      return nullptr;
   }

   return gcnew String(GetObjectPtr()->getLine(index).message);
}

int IJWLayer::MessageVectorWrapper::getLineTag(int index)
{
   if (!IsAlive())
      return -1;

   if (index >= GetObjectPtr()->getNumLines()) {
      Con::errorf(ConsoleLogEntry::General, "MessageVector::getLineText(con): out of bounds line");
      return -1;
   }

   return GetObjectPtr()->getLine(index).messageTag;
}

