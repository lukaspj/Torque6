// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

#include "assets/assetManager.h"

using namespace System;

namespace IJWLayer {

   public ref class SimSetWrapper : SimObjectWrapper
   {
   public:
      SimSetWrapper(int ID) : SimObjectWrapper(ID){};

      SimSet* GetObjectPtr(){
         return static_cast<SimSet*>(mObject);
      };

      void listObjects();
      void add(...array<SimObjectWrapper^>^ objects);
      void remove(...array<SimObjectWrapper^>^ objects);
      void deleteObjects();
      void clear();
      void callOnChildren(String^ method, ...array<String^>^ args);
      void reorderChild(SimObjectWrapper^ child1, SimObjectWrapper^ child2);
      int getCount();
      SimObjectWrapper^ getObject(int index);
      bool isMember(SimObjectWrapper^ object);
      SimObjectWrapper^ findObjectByInternalName(String^ name, bool searchChildren);
      SimObjectWrapper^ findObjectByInternalName(String^ name);
      void bringToFront(SimObjectWrapper^ object);
      void pushToBack(SimObjectWrapper^ object);
   };
}
