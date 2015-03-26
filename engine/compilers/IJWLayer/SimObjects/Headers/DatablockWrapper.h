// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "sim/simDatablock.h"

using namespace System;

namespace IJWLayer {

   public ref class SimDatablockWrapper : SimObjectWrapper
   {
   public:
      SimDatablockWrapper(int ID) : SimObjectWrapper(ID){};
      SimDatablockWrapper(SimDataBlock* object) : SimObjectWrapper(object){};

      SimDataBlock* GetObjectPtr(){
         return static_cast<SimDataBlock*>(mObject);
      };

      void deleteDataBlocks();
   };

}
