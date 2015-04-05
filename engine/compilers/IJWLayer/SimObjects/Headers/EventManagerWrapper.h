// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "messaging/eventManager.h"

// #pragma unmanaged
#pragma managed(pop)

typedef EventManager EngineEventManager;

namespace IJWLayer {
   using namespace System;

   public ref class EventManager : SimObject
   {
   public:
      static EventManager^ Wrap(int ID) { return static_cast<EventManager^>(SimObject::Wrap(ID)); };
      static EventManager^ Wrap(EngineEventManager* obj) { return static_cast<EventManager^>(SimObject::Wrap(obj)); };

      EngineEventManager* GetObjectPtr(){
         return static_cast<EngineEventManager*>(mObject);
      };

      bool registerEvent(String^ eventName);
      void unregisterEvent(String^ eventName);
      bool isRegisteredEvent(String^ eventName);
      bool postEvent(String^ eventName, String^ data);
      bool subscribe(SimObject^ listener, String^ eventName, String^ callback);
      bool subscribe(SimObject^ listener, String^ eventName);
      void remove(SimObject^ listener, String^ eventName);
      void dumpEvents();
      void dumpSubscribers(String^ eventName);
      void dumpSubscribers();
   };
}
