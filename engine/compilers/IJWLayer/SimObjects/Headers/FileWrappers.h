// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "StreamWrappers.h"

//#pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "platform/nativeDialogs/fileDialog.h"
#include "io/fileObject.h"
#include "io/zip/zipObject.h"

// #pragma managed
#pragma managed(pop)

typedef FileDialog EngineFileDialog;
typedef OpenFileDialog EngineOpenFileDialog;
typedef OpenFolderDialog EngineOpenFolderDialog;
typedef SaveFileDialog EngineSaveFileDialog;
typedef FileObject EngineFileObject;
typedef ZipObject EngineZipObject;

namespace IJWLayer {

   public ref class FileDialog : SimObject
   {
   public:
      static FileDialog^ Wrap(int ID) { return static_cast<FileDialog^>(SimObject::Wrap(ID)); };
      static FileDialog^ Wrap(EngineFileDialog* obj) { return static_cast<FileDialog^>(SimObject::Wrap(obj)); };

      EngineFileDialog* GetObjectPtr(){
         return static_cast<EngineFileDialog*>(mObject);
      };

      property String^ DefaultPath{
         String^ get();
         void set(String^ value);
      }

      property String^ DefaultFile{
         String^ get();
         void set(String^ value);
      }

      property String^ FileName{
         String^ get();
         void set(String^ value);
      }

      property String^ Filters{
         String^ get();
         void set(String^ value);
      }

      property String^ Title{
         String^ get();
         void set(String^ value);
      }

      property bool ChangePath{
         bool get();
         void set(bool value);
      }

      bool execute();
   };

   public ref class OpenFileDialog : FileDialog
   {
   public:
      static OpenFileDialog^ Wrap(int ID) { return static_cast<OpenFileDialog^>(SimObject::Wrap(ID)); };
      static OpenFileDialog^ Wrap(EngineOpenFileDialog* obj) { return static_cast<OpenFileDialog^>(SimObject::Wrap(obj)); };

      EngineOpenFileDialog* GetObjectPtr(){
         return static_cast<EngineOpenFileDialog*>(mObject);
      };

      property bool MustExist{
         bool get();
         void set(bool value);
      }

      property bool MultipleFiles{
         bool get();
         void set(bool value);
      }
   };

   public ref class OpenFolderDialog : OpenFileDialog
   {
   public:
      static OpenFolderDialog^ Wrap(int ID) { return static_cast<OpenFolderDialog^>(SimObject::Wrap(ID)); };
      static OpenFolderDialog^ Wrap(EngineOpenFolderDialog* obj) { return static_cast<OpenFolderDialog^>(SimObject::Wrap(obj)); };

      EngineOpenFolderDialog* GetObjectPtr(){
         return static_cast<EngineOpenFolderDialog*>(mObject);
      };

      property String^ FileMustExist{
         String^ get();
         void set(String^ value);
      }
   };

   public ref class SaveFileDialog : FileDialog
   {
   public:
      static SaveFileDialog^ Wrap(int ID) { return static_cast<SaveFileDialog^>(SimObject::Wrap(ID)); };
      static SaveFileDialog^ Wrap(EngineSaveFileDialog* obj) { return static_cast<SaveFileDialog^>(SimObject::Wrap(obj)); };

      EngineSaveFileDialog* GetObjectPtr(){
         return static_cast<EngineSaveFileDialog*>(mObject);
      };

      property bool OverwritePrompt{
         bool get();
         void set(bool value);
      }
   };

   public ref class FileObject : SimObject
   {
   public:
      static FileObject^ Wrap(int ID) { return static_cast<FileObject^>(SimObject::Wrap(ID)); };
      static FileObject^ Wrap(EngineFileObject* obj) { return static_cast<FileObject^>(SimObject::Wrap(obj)); };

      EngineFileObject* GetObjectPtr(){
         return static_cast<EngineFileObject*>(mObject);
      };

      bool openForRead(String^ fileName);
      bool openForWrite(String^ fileName);
      bool openForAppend(String^ fileName);
      bool isEOF();
      String^ readLine();
      String^ peekLine();
      void writeLine(String^ text);
      void close();
      void writeObject(SimObject^ object, String^ prepend);
      void writeObject(SimObject^ object);
   };

   public ref class ZipObject : SimObject
   {
   public:
      static ZipObject^ Wrap(int ID) { return static_cast<ZipObject^>(SimObject::Wrap(ID)); };
      static ZipObject^ Wrap(EngineZipObject* obj) { return static_cast<ZipObject^>(SimObject::Wrap(obj)); };

      EngineZipObject* GetObjectPtr(){
         return static_cast<EngineZipObject*>(mObject);
      };

      enum class AccessMode{
         Read = Zip::ZipArchive::Read,
         Write = Zip::ZipArchive::Write,
         ReadWrite = Zip::ZipArchive::ReadWrite,
      };

      bool openArchive(String^ fileName, AccessMode mode);
      bool openArchive(String^ fileName);
      void closeArchive();
      StreamObject^ openFileForRead(String^ fileName);
      StreamObject^ openFileForWrite(String^ fileName);
      void closeFile(StreamObject^ stream);
      bool addFile(String^ fileName, String^ pathInZip, bool replace);
      bool addFile(String^ fileName, String^ pathInZip);
      bool extractFile(String^ pathInZip, String^ fileName);
      bool deleteFile(String^ pathInZip);
      int getFileEntryCount();
      String^ getFileEntry(int index);
   };
}
