#include "../../Stdafx.h"
#include "../Headers/FileWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::FileDialogWrapper::execute()
{
   if (!IsAlive())
      return false;
   GetObjectPtr()->Execute();
}

bool IJWLayer::FileObjectWrapper::openForRead(String^ filename)
{
   if (!IsAlive())
      return false;
   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   GetObjectPtr()->readMemory(_filename);
}

bool IJWLayer::FileObjectWrapper::openForWrite(String^ filename)
{
   if (!IsAlive())
      return false;
   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   GetObjectPtr()->openForWrite(_filename);
}

bool IJWLayer::FileObjectWrapper::openForAppend(String^ filename)
{
   if (!IsAlive())
      return false;
   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   GetObjectPtr()->openForWrite(_filename, true);
}

bool IJWLayer::FileObjectWrapper::isEOF()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->isEOF();
}

String^ IJWLayer::FileObjectWrapper::readLine()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String((const char*)GetObjectPtr()->readLine());
}

String^ IJWLayer::FileObjectWrapper::peekLine()
{
   if (!IsAlive())
      return nullptr;
   char *line = Con::getReturnBuffer(512);
   GetObjectPtr()->peekLine((U8*)line, 512);
   return gcnew String(line);
}

void IJWLayer::FileObjectWrapper::writeLine(String^ text)
{
   if (!IsAlive())
      return;

   char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   GetObjectPtr()->writeLine((const U8 *)_text);
}

void IJWLayer::FileObjectWrapper::close()
{
   if (IsAlive())
      GetObjectPtr()->close();
}

void IJWLayer::FileObjectWrapper::writeObject(SimObjectWrapper^ object, String^ text)
{
   if (!IsAlive())
      return;

   if (!object->IsAlive())
   {
      Con::printf("FileObject::writeObject - Invalid Object!");
      return;
   }

   char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   GetObjectPtr()->writeObject(object->GetObjectPtr(), (const U8 *)_text);
}

void IJWLayer::FileObjectWrapper::writeObject(SimObjectWrapper^ object)
{
   writeObject(object, nullptr);
}

bool IJWLayer::ZipObjectWrapper::openArchive(String^ fileName, IJWLayer::ZipObjectWrapper::AccessMode mode)
{
   if (!IsAlive())
      return false;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   char buf[512];
   Con::expandPath(buf, sizeof(buf), _fileName);

   return GetObjectPtr()->openArchive(buf, (Zip::ZipArchive::AccessMode)mode);
}

bool IJWLayer::ZipObjectWrapper::openArchive(String^ fileName)
{
   return openArchive(fileName, AccessMode::Read);
}

void IJWLayer::ZipObjectWrapper::closeArchive()
{
   if (IsAlive())
      GetObjectPtr()->closeArchive();
}

IJWLayer::StreamObjectWrapper^ IJWLayer::ZipObjectWrapper::openFileForRead(String^ fileName)
{
   if (!IsAlive())
      return nullptr;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return StreamObjectWrapper::Wrap(GetObjectPtr()->openFileForRead(_fileName));
}

IJWLayer::StreamObjectWrapper^ IJWLayer::ZipObjectWrapper::openFileForWrite(String^ fileName)
{
   if (!IsAlive())
      return nullptr;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return StreamObjectWrapper::Wrap(GetObjectPtr()->openFileForWrite(_fileName));
}

void IJWLayer::ZipObjectWrapper::closeFile(IJWLayer::StreamObjectWrapper^ stream)
{
   if (IsAlive() && stream->IsAlive())
      GetObjectPtr()->closeFile(stream->GetObjectPtr());
}

bool IJWLayer::ZipObjectWrapper::addFile(String^ fileName, String^ pathInZip, bool replace)
{
   if (!IsAlive())
      return false;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   char* _pathInZip = (char*)Marshal::StringToHGlobalAnsi(pathInZip).ToPointer();

   GetObjectPtr()->addFile(_fileName, _pathInZip, replace);
}

bool IJWLayer::ZipObjectWrapper::addFile(String^ fileName, String^ pathInZip)
{
   return addFile(fileName, pathInZip, true);
}

bool IJWLayer::ZipObjectWrapper::extractFile(String^ fileName, String^ pathInZip)
{
   if (!IsAlive())
      return false;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   char* _pathInZip = (char*)Marshal::StringToHGlobalAnsi(pathInZip).ToPointer();

   GetObjectPtr()->extractFile(_fileName, _pathInZip);
}

bool IJWLayer::ZipObjectWrapper::deleteFile(String^ pathInZip)
{
   if (!IsAlive())
      return false;

   char* _pathInZip = (char*)Marshal::StringToHGlobalAnsi(pathInZip).ToPointer();

   GetObjectPtr()->deleteFile(_pathInZip);
}

int IJWLayer::ZipObjectWrapper::getFileEntryCount()
{
   if (IsAlive())
      return GetObjectPtr()->getFileEntryCount();
   return -1;
}

String^ IJWLayer::ZipObjectWrapper::getFileEntry(int index)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getFileEntry(index));
   return nullptr;
}