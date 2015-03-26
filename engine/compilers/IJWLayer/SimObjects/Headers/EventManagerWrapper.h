// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "messaging/eventManager.h"

namespace IJWLayer {
   using namespace System;

   public ref class EventManagerWrapper : SimObjectWrapper
   {
   public:
      EventManagerWrapper(int ID) : SimObjectWrapper(ID){};

      EventManager* GetObjectPtr(){
         return static_cast<EventManager*>(mObject);
      };

      bool registerEvent(String^ eventName);
      void unregisterEvent(String^ eventName);
      bool isRegisteredEvent(String^ eventName);
      bool postEvent(String^ eventName, String^ data);
      bool subscribe(SimObjectWrapper^ listener, String^ eventName, String^ callback);
      bool subscribe(SimObjectWrapper^ listener, String^ eventName);
      void remove(SimObjectWrapper^ listener, String^ eventName);
      void dumpEvents();
      void dumpSubscribers(String^ eventName);
      void dumpSubscribers();
   };
}
