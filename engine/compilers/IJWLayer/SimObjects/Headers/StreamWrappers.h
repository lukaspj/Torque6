// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "io/streamObject.h"
#include "io/fileStreamObject.h"

// #pragma managed
#pragma managed(pop)

using namespace System;

typedef StreamObject EngineStreamObject;
typedef FileStreamObject EngineFileStreamObject;

namespace IJWLayer {

   public ref class StreamObject : SimObject
   {
   public:
      static StreamObject^ Wrap(int ID) { return static_cast<StreamObject^>(SimObject::Wrap(ID)); };
      static StreamObject^ Wrap(EngineStreamObject* obj) { return static_cast<StreamObject^>(SimObject::Wrap(obj)); };

      EngineStreamObject* GetObjectPtr(){
         return static_cast<EngineStreamObject*>(mObject);
      };

      String^ getStatus();
      bool isEOS();
      bool isEOF();
      int getPosition();
      bool setPosition(int pos);
      int getStreamSize();
      String^ readLine();
      void writeLine(String^ line);
      String^ readSTString(bool caseSensitive);
      String^ readSTString();
      String^ readString();
      String^ readLongString(int maxLength);
      void writeLongString(int maxLength, String^ string);
      void writeString(String^ string, int maxLength);
      void writeString(String^ string);
      bool copyFrom(StreamObject^ other);
   };

   public ref class FileStreamObject : StreamObject
   {

   public:
      static FileStreamObject^ Wrap(int ID) { return static_cast<FileStreamObject^>(SimObject::Wrap(ID)); };
      static FileStreamObject^ Wrap(EngineFileStreamObject* obj) { return static_cast<FileStreamObject^>(SimObject::Wrap(obj)); };

      EngineFileStreamObject* GetObjectPtr(){
         return static_cast<EngineFileStreamObject*>(mObject);
      };

      enum class FileMode{
         Read = FileStream::Read,
         Write = FileStream::Write,
         ReadWrite = FileStream::ReadWrite,
         WriteAppend = FileStream::WriteAppend
      };

      bool open(String^ fileName, FileMode mode);
      void close();
   };
}
