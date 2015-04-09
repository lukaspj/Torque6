// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/consoleLogger.h"

// #pragma unmanaged
#pragma managed(pop)

using System::String;

typedef ConsoleLogger EngineConsoleLogger;

namespace IJWLayer {

   public ref class ConsoleLogger : SimObject
   {
   public:
      static ConsoleLogger^ Wrap(int ID) { return static_cast<ConsoleLogger^>(SimObject::Wrap(ID)); };
      static ConsoleLogger^ Wrap(EngineConsoleLogger* obj) { return static_cast<ConsoleLogger^>(SimObject::Wrap(obj)); };

      EngineConsoleLogger* GetObjectPtr(){
         return static_cast<EngineConsoleLogger*>(mObject);
      };

      property int Level{
         int get();
         void set(int value);
      }

      bool attach();
      bool detach();
   };

}
