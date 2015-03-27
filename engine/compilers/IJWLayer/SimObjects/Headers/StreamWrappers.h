// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "io/streamObject.h"
#include "io/fileStreamObject.h"

using namespace System;

namespace IJWLayer {

   public ref class StreamObjectWrapper : SimObjectWrapper
   {
   public:
      static StreamObjectWrapper^ Wrap(int ID) { return static_cast<StreamObjectWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static StreamObjectWrapper^ Wrap(StreamObject* obj) { return static_cast<StreamObjectWrapper^>(SimObjectWrapper::Wrap(obj)); };

      StreamObject* GetObjectPtr(){
         return static_cast<StreamObject*>(mObject);
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
      bool copyFrom(StreamObjectWrapper^ other);
   };

   public ref class FileStreamObjectWrapper : StreamObjectWrapper
   {

   public:
      static FileStreamObjectWrapper^ Wrap(int ID) { return static_cast<FileStreamObjectWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static FileStreamObjectWrapper^ Wrap(FileStreamObject* obj) { return static_cast<FileStreamObjectWrapper^>(SimObjectWrapper::Wrap(obj)); };

      FileStreamObject* GetObjectPtr(){
         return static_cast<FileStreamObject*>(mObject);
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
