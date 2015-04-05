#include "../../Stdafx.h"
#include "../Headers/StreamWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

String^ IJWLayer::StreamObject::getStatus()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getStatus());
   return nullptr;
}

bool IJWLayer::StreamObject::isEOS()
{
   if (IsAlive())
      return GetObjectPtr()->isEOS();
   return false;
}

bool IJWLayer::StreamObject::isEOF()
{
   if (IsAlive())
      return GetObjectPtr()->isEOS();
   return false;
}

int IJWLayer::StreamObject::getPosition()
{
   if (IsAlive())
      return GetObjectPtr()->getPosition();
   return -1;
}

bool IJWLayer::StreamObject::setPosition(int newPos)
{
   if (IsAlive())
      return GetObjectPtr()->setPosition(newPos);
   return -1;
}

int IJWLayer::StreamObject::getStreamSize()
{
   if (IsAlive())
      return GetObjectPtr()->getStreamSize();
   return -1;
}

String^ IJWLayer::StreamObject::readLine()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->readLine());
   return nullptr;
}

void IJWLayer::StreamObject::writeLine(String^ line)
{
   if (!IsAlive())
      return;

   const char* _line = (char*)Marshal::StringToHGlobalAnsi(line).ToPointer();
   GetObjectPtr()->writeLine((U8*)_line);
}

String^ IJWLayer::StreamObject::readSTString(bool caseSensitive)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->readSTString(caseSensitive));
   return nullptr;
}

String^ IJWLayer::StreamObject::readSTString()
{
   return readSTString(false);
}

String^ IJWLayer::StreamObject::readString()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->readString());
   return nullptr;
}

String^ IJWLayer::StreamObject::readLongString(int maxLength)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->readLongString(maxLength));
   return nullptr;
}

void IJWLayer::StreamObject::writeLongString(int maxLength, String^ string)
{
   if (!IsAlive())
      return;

   const char* _string = (char*)Marshal::StringToHGlobalAnsi(string).ToPointer();
   GetObjectPtr()->writeLongString(maxLength, _string);
}

void IJWLayer::StreamObject::writeString(String^ string, int maxLength)
{
   if (!IsAlive())
      return;

   const char* _string = (char*)Marshal::StringToHGlobalAnsi(string).ToPointer();
   GetObjectPtr()->writeString(_string, maxLength);
}

void IJWLayer::StreamObject::writeString(String^ string)
{
   writeString(string, 255);
}

bool IJWLayer::StreamObject::copyFrom(StreamObject^ other)
{
   if (!IsAlive() || !other->IsAlive())
      return false;

   return GetObjectPtr()->copyFrom(other->GetObjectPtr());
}

bool IJWLayer::FileStreamObject::open(String^ fileName, FileMode mode)
{
   if (!IsAlive())
      return false;

   bool found = false;

   if (!found)
   {
      Con::errorf("FileStreamObject::open - Mode must be one of Read, Write, ReadWrite or WriteAppend.");
      return false;
   }

   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   char buffer[1024];
   Con::expandPath(buffer, sizeof(buffer), _fileName);
   return GetObjectPtr()->open(buffer, (FileStream::AccessMode)mode);
}

void IJWLayer::FileStreamObject::close()
{
   if (IsAlive())
      GetObjectPtr()->close();
}