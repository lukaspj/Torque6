#include "../../Stdafx.h"
#include "../Headers/FileWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::FileDialog::execute()
{
   if (!IsAlive())
      return false;
   GetObjectPtr()->Execute();
}

bool IJWLayer::FileObject::openForRead(String^ filename)
{
   if (!IsAlive())
      return false;
   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   GetObjectPtr()->readMemory(_filename);
   Marshal::FreeHGlobal((IntPtr)_filename);
}

bool IJWLayer::FileObject::openForWrite(String^ filename)
{
   if (!IsAlive())
      return false;
   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   GetObjectPtr()->openForWrite(_filename);
}

bool IJWLayer::FileObject::openForAppend(String^ filename)
{
   if (!IsAlive())
      return false;
   char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();
   GetObjectPtr()->openForWrite(_filename, true);
}

bool IJWLayer::FileObject::isEOF()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->isEOF();
}

String^ IJWLayer::FileObject::readLine()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String((const char*)GetObjectPtr()->readLine());
}

String^ IJWLayer::FileObject::peekLine()
{
   if (!IsAlive())
      return nullptr;
   char *line = Con::getReturnBuffer(512);
   GetObjectPtr()->peekLine((U8*)line, 512);
   return gcnew String(line);
}

void IJWLayer::FileObject::writeLine(String^ text)
{
   if (!IsAlive())
      return;

   char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   GetObjectPtr()->writeLine((const U8 *)_text);
}

void IJWLayer::FileObject::close()
{
   if (IsAlive())
      GetObjectPtr()->close();
}

void IJWLayer::FileObject::writeObject(SimObject^ object, String^ text)
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

void IJWLayer::FileObject::writeObject(SimObject^ object)
{
   writeObject(object, nullptr);
}

bool IJWLayer::ZipObject::openArchive(String^ fileName, IJWLayer::ZipObject::AccessMode mode)
{
   if (!IsAlive())
      return false;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   char buf[512];
   Con::expandPath(buf, sizeof(buf), _fileName);

   return GetObjectPtr()->openArchive(buf, (Zip::ZipArchive::AccessMode)mode);
}

bool IJWLayer::ZipObject::openArchive(String^ fileName)
{
   return openArchive(fileName, AccessMode::Read);
}

void IJWLayer::ZipObject::closeArchive()
{
   if (IsAlive())
      GetObjectPtr()->closeArchive();
}

IJWLayer::StreamObject^ IJWLayer::ZipObject::openFileForRead(String^ fileName)
{
   if (!IsAlive())
      return nullptr;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return StreamObject::Wrap(GetObjectPtr()->openFileForRead(_fileName));
}

IJWLayer::StreamObject^ IJWLayer::ZipObject::openFileForWrite(String^ fileName)
{
   if (!IsAlive())
      return nullptr;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return StreamObject::Wrap(GetObjectPtr()->openFileForWrite(_fileName));
}

void IJWLayer::ZipObject::closeFile(IJWLayer::StreamObject^ stream)
{
   if (IsAlive() && stream->IsAlive())
      GetObjectPtr()->closeFile(stream->GetObjectPtr());
}

bool IJWLayer::ZipObject::addFile(String^ fileName, String^ pathInZip, bool replace)
{
   if (!IsAlive())
      return false;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   char* _pathInZip = (char*)Marshal::StringToHGlobalAnsi(pathInZip).ToPointer();

   GetObjectPtr()->addFile(_fileName, _pathInZip, replace);
}

bool IJWLayer::ZipObject::addFile(String^ fileName, String^ pathInZip)
{
   return addFile(fileName, pathInZip, true);
}

bool IJWLayer::ZipObject::extractFile(String^ fileName, String^ pathInZip)
{
   if (!IsAlive())
      return false;

   char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   char* _pathInZip = (char*)Marshal::StringToHGlobalAnsi(pathInZip).ToPointer();

   GetObjectPtr()->extractFile(_fileName, _pathInZip);
}

bool IJWLayer::ZipObject::deleteFile(String^ pathInZip)
{
   if (!IsAlive())
      return false;

   char* _pathInZip = (char*)Marshal::StringToHGlobalAnsi(pathInZip).ToPointer();

   GetObjectPtr()->deleteFile(_pathInZip);
}

int IJWLayer::ZipObject::getFileEntryCount()
{
   if (IsAlive())
      return GetObjectPtr()->getFileEntryCount();
   return -1;
}

String^ IJWLayer::ZipObject::getFileEntry(int index)
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getFileEntry(index));
   return nullptr;
}