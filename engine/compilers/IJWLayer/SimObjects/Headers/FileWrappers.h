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
      FileDialogWrapper(int ID) : SimObjectWrapper(ID){};

      FileDialog* GetObjectPtr(){
         return static_cast<FileDialog*>(mObject);
      };

      bool execute();
   };

   public ref class OpenFileDialogWrapper : FileDialogWrapper
   {
   public:
      OpenFileDialogWrapper(int ID) : FileDialogWrapper(ID){};

      OpenFileDialog* GetObjectPtr(){
         return static_cast<OpenFileDialog*>(mObject);
      };
   };

   public ref class OpenFolderDialogWrapper : OpenFileDialogWrapper
   {
   public:
      OpenFolderDialogWrapper(int ID) : OpenFileDialogWrapper(ID){};

      OpenFolderDialog* GetObjectPtr(){
         return static_cast<OpenFolderDialog*>(mObject);
      };
   };

   public ref class SaveFileDialogWrapper : FileDialogWrapper
   {
   public:
      SaveFileDialogWrapper(int ID) : FileDialogWrapper(ID){};

      SaveFileDialog* GetObjectPtr(){
         return static_cast<SaveFileDialog*>(mObject);
      };
   };

   public ref class FileObjectWrapper : SimObjectWrapper
   {
   public:
      FileObjectWrapper(int ID) : SimObjectWrapper(ID){};

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
      ZipObjectWrapper(int ID) : SimObjectWrapper(ID){};

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
