// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "messaging/message.h"
#include "gui/messageVector.h"
#include "messaging/scriptMsgListener.h"
#include "messaging/messageForwarder.h"
#include "messaging/dispatcher.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef Message EngineMessage;
typedef MessageForwarder EngineMessageForwarder;
typedef ScriptMsgListener EngineScriptMsgListener;
typedef MessageVector EngineMessageVector;

namespace IJWLayer {

   public ref class Message : SimObject
   {
   public:
      static Message^ Wrap(int ID) { return static_cast<Message^>(SimObject::Wrap(ID)); };
      static Message^ Wrap(EngineMessage* obj) { return static_cast<Message^>(SimObject::Wrap(obj)); };

      EngineMessage* GetObjectPtr(){
         return static_cast<EngineMessage*>(mObject);
      };

      String^ getType();
      void addReference();
      void freeReference();
   };

   public ref class ScriptMsgListener : SimObject
   {
   public:
      static ScriptMsgListener^ Wrap(int ID) { return static_cast<ScriptMsgListener^>(SimObject::Wrap(ID)); };
      static ScriptMsgListener^ Wrap(EngineScriptMsgListener* obj) { return static_cast<ScriptMsgListener^>(SimObject::Wrap(obj)); };

      EngineScriptMsgListener* GetObjectPtr(){
         return static_cast<EngineScriptMsgListener*>(mObject);
      };
   };

   public ref class MessageForwarder : ScriptMsgListener
   {
   public:
      static MessageForwarder^ Wrap(int ID) { return static_cast<MessageForwarder^>(SimObject::Wrap(ID)); };
      static MessageForwarder^ Wrap(EngineMessageForwarder* obj) { return static_cast<MessageForwarder ^>(SimObject::Wrap(obj)); };

      EngineMessageForwarder* GetObjectPtr(){
         return static_cast<EngineMessageForwarder*>(mObject);
      };

      property String^ ToQueue{
         String^ get();
         void set(String^ value);
      }
   };

   public ref class MessageVector : SimObject
   {
   public:
      static MessageVector^ Wrap(int ID) { return static_cast<MessageVector^>(SimObject::Wrap(ID)); };
      static MessageVector^ Wrap(EngineMessageVector* obj) { return static_cast<MessageVector^>(SimObject::Wrap(obj)); };

      EngineMessageVector* GetObjectPtr(){
         return static_cast<EngineMessageVector*>(mObject);
      };

      void clear();
      void pushBackLine(String^ msg, int tag);
      void pushBackLine(String^ msg);
      bool popBackLine();
      void pushFrontLine(String^ msg, int tag);
      void pushFrontLine(String^ msg);
      bool popFrontLine();
      bool insertLine(int pos, String^ msg, int tag);
      bool insertLine(int pos, String^ msg);
      bool deleteLine(int lineIndex);
      void dump(String^ filename, String^ header);
      void dump(String^ filename);
      int getNumLines();
      String^ getLineTextByTag(int tag);
      int getLineIndexByTag(int tag);
      String^ getLineText(int index);
      int getLineTag(int index);

   };
}
