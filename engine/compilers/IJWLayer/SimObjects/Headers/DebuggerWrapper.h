// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "debug/remote/RemoteDebuggerBase.h"
#include "debug/remote/RemoteDebugger1.h"

using namespace System;

namespace IJWLayer {

   public ref class RemoteDebuggerBaseWrapper : SimObjectWrapper
   {
   public:
      static RemoteDebuggerBaseWrapper^ Wrap(int ID) { return static_cast<RemoteDebuggerBaseWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static RemoteDebuggerBaseWrapper^ Wrap(RemoteDebuggerBase* obj) { return static_cast<RemoteDebuggerBaseWrapper^>(SimObjectWrapper::Wrap(obj)); };

      RemoteDebuggerBase* GetObjectPtr(){
         return static_cast<RemoteDebuggerBase*>(mObject);
      };
   };

   public ref class RemoteDebugger1Wrapper : SimObjectWrapper
   {
   public:
      static RemoteDebugger1Wrapper^ Wrap(int ID) { return static_cast<RemoteDebugger1Wrapper^>(SimObjectWrapper::Wrap(ID)); };
      static RemoteDebugger1Wrapper^ Wrap(RemoteDebugger1* obj) { return static_cast<RemoteDebugger1Wrapper^>(SimObjectWrapper::Wrap(obj)); };

      RemoteDebugger1* GetObjectPtr(){
         return static_cast<RemoteDebugger1*>(mObject);
      };

      String^ getCodeFiles();
      void setNextStatementBreak(bool enabled);
   };

}
