// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "console/consoleLogger.h"

using namespace System;

namespace IJWLayer {

   public ref class ConsoleLoggerWrapper : SimObjectWrapper
   {
   public:
      static ConsoleLoggerWrapper^ Wrap(int ID) { return static_cast<ConsoleLoggerWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ConsoleLoggerWrapper^ Wrap(SimObject* obj) { return static_cast<ConsoleLoggerWrapper^>(SimObjectWrapper::Wrap(obj)); };

      ConsoleLogger* GetObjectPtr(){
         return static_cast<ConsoleLogger*>(mObject);
      };

      bool attach();
      bool detach();
   };

}
