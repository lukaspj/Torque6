// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "platform/nativeDialogs/fileDialog.h"
#include "io/fileObject.h"
#include "io/zip/zipObject.h"
#include "StreamWrappers.h"

namespace IJWLayer {

   public ref class FileDialogWrapper : SimObjectWrapper
   {
   public:
      static FileDialogWrapper^ Wrap(int ID) { return static_cast<FileDialogWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static FileDialogWrapper^ Wrap(FileDialog* obj) { return static_cast<FileDialogWrapper^>(SimObjectWrapper::Wrap(obj)); };

      FileDialog* GetObjectPtr(){
         return static_cast<FileDialog*>(mObject);
      };

      bool execute();
   };

   public ref class OpenFileDialogWrapper : FileDialogWrapper
   {
   public:
      static OpenFileDialogWrapper^ Wrap(int ID) { return static_cast<OpenFileDialogWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static OpenFileDialogWrapper^ Wrap(OpenFileDialog* obj) { return static_cast<OpenFileDialogWrapper^>(SimObjectWrapper::Wrap(obj)); };

      OpenFileDialog* GetObjectPtr(){
         return static_cast<OpenFileDialog*>(mObject);
      };
   };

   public ref class OpenFolderDialogWrapper : OpenFileDialogWrapper
   {
   public:
      static OpenFolderDialogWrapper^ Wrap(int ID) { return static_cast<OpenFolderDialogWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static OpenFolderDialogWrapper^ Wrap(OpenFolderDialog* obj) { return static_cast<OpenFolderDialogWrapper^>(SimObjectWrapper::Wrap(obj)); };

      OpenFolderDialog* GetObjectPtr(){
         return static_cast<OpenFolderDialog*>(mObject);
      };
   };

   public ref class SaveFileDialogWrapper : FileDialogWrapper
   {
   public:
      static SaveFileDialogWrapper^ Wrap(int ID) { return static_cast<SaveFileDialogWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static SaveFileDialogWrapper^ Wrap(SaveFileDialog* obj) { return static_cast<SaveFileDialogWrapper^>(SimObjectWrapper::Wrap(obj)); };

      SaveFileDialog* GetObjectPtr(){
         return static_cast<SaveFileDialog*>(mObject);
      };
   };

   public ref class FileObjectWrapper : SimObjectWrapper
   {
   public:
      static FileObjectWrapper^ Wrap(int ID) { return static_cast<FileObjectWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static FileObjectWrapper^ Wrap(FileObject* obj) { return static_cast<FileObjectWrapper^>(SimObjectWrapper::Wrap(obj)); };

      FileObject* GetObjectPtr(){
         return static_cast<FileObject*>(mObject);
      };

      bool openForRead(String^ fileName);
      bool openForWrite(String^ fileName);
      bool openForAppend(String^ fileName);
      bool isEOF();
      String^ readLine();
      String^ peekLine();
      void writeLine(String^ text);
      void close();
      void writeObject(SimObjectWrapper^ object, String^ prepend);
      void writeObject(SimObjectWrapper^ object);
   };

   public ref class ZipObjectWrapper : SimObjectWrapper
   {
   public:
      static ZipObjectWrapper^ Wrap(int ID) { return static_cast<ZipObjectWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ZipObjectWrapper^ Wrap(ZipObject* obj) { return static_cast<ZipObjectWrapper^>(SimObjectWrapper::Wrap(obj)); };

      ZipObject* GetObjectPtr(){
         return static_cast<ZipObject*>(mObject);
      };

      enum class AccessMode{
         Read = Zip::ZipArchive::Read,
         Write = Zip::ZipArchive::Write,
         ReadWrite = Zip::ZipArchive::ReadWrite,
      };

      bool openArchive(String^ fileName, AccessMode mode);
      bool openArchive(String^ fileName);
      void closeArchive();
      StreamObjectWrapper^ openFileForRead(String^ fileName);
      StreamObjectWrapper^ openFileForWrite(String^ fileName);
      void closeFile(StreamObjectWrapper^ stream);
      bool addFile(String^ fileName, String^ pathInZip, bool replace);
      bool addFile(String^ fileName, String^ pathInZip);
      bool extractFile(String^ pathInZip, String^ fileName);
      bool deleteFile(String^ pathInZip);
      int getFileEntryCount();
      String^ getFileEntry(int index);
   };
}
