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
      RemoteDebuggerBaseWrapper(int ID) : SimObjectWrapper(ID){};
      RemoteDebuggerBaseWrapper(RemoteDebuggerBase* object) : SimObjectWrapper(object){};

      RemoteDebuggerBase* GetObjectPtr(){
         return static_cast<RemoteDebuggerBase*>(mObject);
      };
   };

   public ref class RemoteDebugger1Wrapper : SimObjectWrapper
   {
   public:
      RemoteDebugger1Wrapper(int ID) : SimObjectWrapper(ID){};
      RemoteDebugger1Wrapper(RemoteDebugger1* object) : SimObjectWrapper(object){};

      RemoteDebugger1* GetObjectPtr(){
         return static_cast<RemoteDebugger1*>(mObject);
      };

      String^ getCodeFiles();
      void setNextStatementBreak(bool enabled);
   };

}
