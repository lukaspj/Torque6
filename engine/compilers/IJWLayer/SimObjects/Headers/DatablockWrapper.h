// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "sim/simDatablock.h"

using namespace System;

namespace IJWLayer {

   public ref class SimDatablockWrapper : SimObjectWrapper
   {
   public:
      static SimDatablockWrapper^ Wrap(int ID) { return static_cast<SimDatablockWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static SimDatablockWrapper^ Wrap(SimDataBlock* obj) { return static_cast<SimDatablockWrapper^>(SimObjectWrapper::Wrap(obj)); };

      SimDataBlock* GetObjectPtr(){
         return static_cast<SimDataBlock*>(mObject);
      };

      void deleteDataBlocks();
   };

}
