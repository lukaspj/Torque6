// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "graphics/DynamicTexture.h"
#include "graphics/PNGImage.h"

using namespace System;

namespace IJWLayer {

   public ref class DynamicTextureWrapper : SimObjectWrapper
   {
   public:
      DynamicTextureWrapper(int ID) : SimObjectWrapper(ID){};

      DynamicTexture* GetObjectPtr(){
         return static_cast<DynamicTexture*>(mObject);
      };
   };

   public ref class PNGImageWrapper : SimObjectWrapper
   {
   public:
      PNGImageWrapper(int ID) : SimObjectWrapper(ID){};

      PNGImage* GetObjectPtr(){
         return static_cast<PNGImage*>(mObject);
      };

      bool CreateBaseImage(int width, int height, int imageType);
      bool MergeOn(int width, int height, String^ imageFile);
      bool SaveImage(String^ fileName);
   };
}
