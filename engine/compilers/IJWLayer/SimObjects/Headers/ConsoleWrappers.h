// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "console/consoleLogger.h"

using namespace System;

namespace IJWLayer {

   public ref class ConsoleLoggerWrapper : SimObjectWrapper
   {
   public:
      ConsoleLoggerWrapper(int ID) : SimObjectWrapper(ID){};
      ConsoleLoggerWrapper(ConsoleLogger* object) : SimObjectWrapper(object){};

      ConsoleLogger* GetObjectPtr(){
         return static_cast<ConsoleLogger*>(mObject);
      };

      bool attach();
      bool detach();
   };

}
