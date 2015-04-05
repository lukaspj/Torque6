// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "debug/remote/RemoteDebuggerBase.h"
#include "debug/remote/RemoteDebugger1.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef RemoteDebuggerBase EngineRemoteDebuggerBase;
typedef RemoteDebugger1 EngineRemoteDebugger1;

namespace IJWLayer {

   public ref class RemoteDebuggerBase : SimObject
   {
   public:
      static RemoteDebuggerBase^ Wrap(int ID) { return static_cast<RemoteDebuggerBase^>(SimObject::Wrap(ID)); };
      static RemoteDebuggerBase^ Wrap(EngineRemoteDebuggerBase* obj) { return static_cast<RemoteDebuggerBase^>(SimObject::Wrap(obj)); };

      EngineRemoteDebuggerBase* GetObjectPtr(){
         return static_cast<EngineRemoteDebuggerBase*>(mObject);
      };
   };

   public ref class RemoteDebugger1 : SimObject
   {
   public:
      static RemoteDebugger1^ Wrap(int ID) { return static_cast<RemoteDebugger1^>(SimObject::Wrap(ID)); };
      static RemoteDebugger1^ Wrap(EngineRemoteDebugger1* obj) { return static_cast<RemoteDebugger1^>(SimObject::Wrap(obj)); };

      EngineRemoteDebugger1* GetObjectPtr(){
         return static_cast<EngineRemoteDebugger1*>(mObject);
      };

      String^ getCodeFiles();
      void setNextStatementBreak(bool enabled);
   };

}
