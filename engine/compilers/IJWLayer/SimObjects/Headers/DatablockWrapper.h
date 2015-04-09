// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "sim/simDatablock.h"

// #pragma unmanaged
#pragma managed(pop)

using System::String;

typedef SimDataBlock EngineSimDataBlock;

namespace IJWLayer {

   public ref class SimDataBlock : SimObject
   {
   public:
      static SimDataBlock^ Wrap(int ID) { return static_cast<SimDataBlock^>(SimObject::Wrap(ID)); };
      static SimDataBlock^ Wrap(EngineSimDataBlock* obj) { return static_cast<SimDataBlock^>(SimObject::Wrap(obj)); };

      EngineSimDataBlock* GetObjectPtr(){
         return static_cast<EngineSimDataBlock*>(mObject);
      };

      void deleteDataBlocks();
   };

}
