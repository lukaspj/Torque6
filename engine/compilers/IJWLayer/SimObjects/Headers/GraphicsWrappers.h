// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "graphics/DynamicTexture.h"
#include "graphics/PNGImage.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef DynamicTexture EngineDynamicTexture;
typedef PNGImage EnginePNGImage;

namespace IJWLayer {

   public ref class DynamicTexture : SimObject
   {
   public:
      static DynamicTexture^ Wrap(int ID) { return static_cast<DynamicTexture^>(SimObject::Wrap(ID)); };
      static DynamicTexture^ Wrap(EngineDynamicTexture* obj) { return static_cast<DynamicTexture^>(SimObject::Wrap(obj)); };

      EngineDynamicTexture* GetObjectPtr(){
         return static_cast<EngineDynamicTexture*>(mObject);
      };
   };

   public ref class PNGImage : SimObject
   {
   public:
      static PNGImage^ Wrap(int ID) { return static_cast<PNGImage^>(SimObject::Wrap(ID)); };
      static PNGImage^ Wrap(EnginePNGImage* obj) { return static_cast<PNGImage^>(SimObject::Wrap(obj)); };

      EnginePNGImage* GetObjectPtr(){
         return static_cast<EnginePNGImage*>(mObject);
      };

      bool CreateBaseImage(int width, int height, int imageType);
      bool MergeOn(int width, int height, String^ imageFile);
      bool SaveImage(String^ fileName);
   };
}
