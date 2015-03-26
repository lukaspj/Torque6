// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "messaging/message.h"
#include "gui/messageVector.h"
#include "messaging/scriptMsgListener.h"
#include "messaging/messageForwarder.h"
#include "messaging/dispatcher.h"

using namespace System;

namespace IJWLayer {

   public ref class MessageWrapper : SimObjectWrapper
   {
   public:
      MessageWrapper(int ID) : SimObjectWrapper(ID){};

      Message* GetObjectPtr(){
         return static_cast<Message*>(mObject);
      };

      String^ getType();
      void addReference();
      void freeReference();
   };

   public ref class ScriptMsgListenerWrapper : SimObjectWrapper
   {
   public:
      ScriptMsgListenerWrapper(int ID) : SimObjectWrapper(ID){};

      ScriptMsgListener* GetObjectPtr(){
         return static_cast<ScriptMsgListener*>(mObject);
      };
   };

   public ref class MessageForwarderWrapper : ScriptMsgListenerWrapper
   {
   public:
      MessageForwarderWrapper(int ID) : ScriptMsgListenerWrapper(ID){};

      MessageForwarder* GetObjectPtr(){
         return static_cast<MessageForwarder*>(mObject);
      };
   };

   public ref class MessageVectorWrapper : SimObjectWrapper
   {
   public:
      MessageVectorWrapper(int ID) : SimObjectWrapper(ID){};

      MessageVector* GetObjectPtr(){
         return static_cast<MessageVector*>(mObject);
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
