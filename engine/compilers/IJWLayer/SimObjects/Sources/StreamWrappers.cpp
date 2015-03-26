#include "../../Stdafx.h"
#include "../Headers/StreamWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

String^ IJWLayer::StreamObjectWrapper::getStatus()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getStatus());
   return nullptr;
}

bool IJWLayer::StreamObjectWrapper::isEOS()
{
   if (IsAlive())
      return GetObjectPtr()->isEOS();
   return false;
}

bool IJWLayer::StreamObjectWrapper::isEOF()
{
   if (IsAlive())
      return GetObjectPtr()->isEOS();
   return false;
}

int IJWLayer::StreamObjectWrapper::getPosition()
{
   if (IsAlive())
      return GetObjectPtr()->getPosition();
   return -1;
}

bool IJWLayer::StreamObjectWrapper::setPosition(int newPos)
{
   if (IsAlive())
      return GetObjectPtr()->setPosition(newPos);
   return -1;
}

int IJWLayer::StreamObjectWrapper::getStreamSize()
{
   if (IsAlive())
      return GetObjectPtr()->getStreamSize();
   return -1;
}

String^ IJWLayer::StreamObjectWrapper::readLine()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->readLine());
   return nullptr;
}

void IJWLayer::StreamObjectWrapper::writeLine(String^ line)
{
   if (!IsAlive())
      return;

   const char* _line = (char*)Marshal::StringToHGlobalAnsi(line).ToPointer();
   GetObjectPtr()->writeLine((U8*)_line);
}

String^ IJWLayer::StreamObjectWrapper::readSTString(bool caseSensitive)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->readSTString(caseSensitive));
   return nullptr;
}

String^ IJWLayer::StreamObjectWrapper::readSTString()
{
   return readSTString(false);
}

String^ IJWLayer::StreamObjectWrapper::readString()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->readString());
   return nullptr;
}

String^ IJWLayer::StreamObjectWrapper::readLongString(int maxLength)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->readLongString(maxLength));
   return nullptr;
}

void IJWLayer::StreamObjectWrapper::writeLongString(int maxLength, String^ string)
{
   if (!IsAlive())
      return;

   const char* _string = (char*)Marshal::StringToHGlobalAnsi(string).ToPointer();
   GetObjectPtr()->writeLongString(maxLength, _string);
}

void IJWLayer::StreamObjectWrapper::writeString(String^ string, int maxLength)
{
   if (!IsAlive())
      return;

   const char* _string = (char*)Marshal::StringToHGlobalAnsi(string).ToPointer();
   GetObjectPtr()->writeString(_string, maxLength);
}

void IJWLayer::StreamObjectWrapper::writeString(String^ string)
{
   writeString(string, 255);
}

bool IJWLayer::StreamObjectWrapper::copyFrom(StreamObjectWrapper^ other)
{
   if (!IsAlive() || !other->IsAlive())
      return false;

   return GetObjectPtr()->copyFrom(other->GetObjectPtr());
}

bool IJWLayer::FileStreamObjectWrapper::open(String^ fileName, FileMode mode)
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

void IJWLayer::FileStreamObjectWrapper::close()
{
   if (IsAlive())
      GetObjectPtr()->close();
}