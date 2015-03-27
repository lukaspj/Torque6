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
      static DynamicTextureWrapper^ Wrap(int ID) { return static_cast<DynamicTextureWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static DynamicTextureWrapper^ Wrap(DynamicTexture* obj) { return static_cast<DynamicTextureWrapper^>(SimObjectWrapper::Wrap(obj)); };

      DynamicTexture* GetObjectPtr(){
         return static_cast<DynamicTexture*>(mObject);
      };
   };

   public ref class PNGImageWrapper : SimObjectWrapper
   {
   public:
      static PNGImageWrapper^ Wrap(int ID) { return static_cast<PNGImageWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static PNGImageWrapper^ Wrap(PNGImage* obj) { return static_cast<PNGImageWrapper^>(SimObjectWrapper::Wrap(obj)); };

      PNGImage* GetObjectPtr(){
         return static_cast<PNGImage*>(mObject);
      };

      bool CreateBaseImage(int width, int height, int imageType);
      bool MergeOn(int width, int height, String^ imageFile);
      bool SaveImage(String^ fileName);
   };
}
