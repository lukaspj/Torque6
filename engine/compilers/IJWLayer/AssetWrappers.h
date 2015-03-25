// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

#include "assets/assetBase.h"
#include "audio/AudioAsset.h"
#include "3d/assets/baseMaterialAsset.h"
#include "3d/assets/deferredMaterialAsset.h"
#include "3d/assets/forwardMaterialAsset.h"
#include "3d/assets/meshAsset.h"
#include "2d/assets/ImageAsset.h"
#include "plugins/pluginAsset.h"
#include "graphics/shaders.h"

using namespace System;

namespace IJWLayer {

   public ref class AssetBaseWrapper : SimObjectWrapper
	{
   public:
      AssetBaseWrapper(int ID) : SimObjectWrapper(ID){};

      AssetBase* GetObjectPtr(){
         return static_cast<AssetBase*>(mObject);
      };

      void refreshAsset();
      String^ getAssetId();
	};

   public ref class AudioAssetWrapper : AssetBaseWrapper
	{
   public:
      AudioAssetWrapper(int ID) : AssetBaseWrapper(ID){};

      AudioAsset* GetObjectPtr(){
         return static_cast<AudioAsset*>(mObject);
      };
	};

   public ref class BaseMaterialAssetWrapper : AssetBaseWrapper
	{
   public:
      BaseMaterialAssetWrapper(int ID) : AssetBaseWrapper(ID){};

      BaseMaterialAsset* GetObjectPtr(){
         return static_cast<BaseMaterialAsset*>(mObject);
      };
	};

   public ref class DeferredMaterialAssetWrapper : BaseMaterialAssetWrapper
	{
   public:
      DeferredMaterialAssetWrapper(int ID) : BaseMaterialAssetWrapper(ID){};

      DeferredMaterialAsset* GetObjectPtr(){
         return static_cast<DeferredMaterialAsset*>(mObject);
      };
	};

   public ref class ForwardMaterialAssetWrapper : BaseMaterialAssetWrapper
	{
   public:
      ForwardMaterialAssetWrapper(int ID) : BaseMaterialAssetWrapper(ID){};

      ForwardMaterialAsset* GetObjectPtr(){
         return static_cast<ForwardMaterialAsset*>(mObject);
      };
	};

   public ref class MeshAssetWrapper : AssetBaseWrapper
	{
   public:
      MeshAssetWrapper(int ID) : AssetBaseWrapper(ID){};

      MeshAsset* GetObjectPtr(){
         return static_cast<MeshAsset*>(mObject);
      };
	};

   public ref class ImageAssetWrapper : AssetBaseWrapper
	{
   public:
      ImageAssetWrapper(int ID) : ImageAssetWrapper(ID){};

      ImageAsset* GetObjectPtr(){
         return static_cast<ImageAsset*>(mObject);
      };
      property String^ ImageFile{
         String^ get();
         void set(String^ value);
      }
      property String^ FilterMode{
         String^ get();
         void set(String^ value);
      }
      property bool Force16Bit{
         bool get();
         void set(bool value);
      }
      property bool CellRowOrder{
         bool get();
         void set(bool value);
      }
      property int CellOffsetX{
         int get();
         void set(int value);
      }
      property int CellOffsetY{
         int get();
         void set(int value);
      }
      property int CellStrideX{
         int get();
         void set(int value);
      }
      property int CellStrideY{
         int get();
         void set(int value);
      }
      property int CellCountX{
         int get();
         void set(int value);
      }
      property int CellCountY{
         int get();
         void set(int value);
      }
      property int CellWidth{
         int get();
         void set(int value);
      }
      property int CellHeight{
         int get();
         void set(int value);
      }
      property int ImageWidth{
         int get();
      }
      property int ImageHeight{
         int get();
      }
      property String^ ImageSize{
         String^ get();
      }
      property bool IsImagePOT{
         bool get();
      }
      property int FrameCount{
         int get();
      }
      String^ getFrameSize(int frame);
      bool clearExplicitCells();
      bool addExplicitCell(int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName);
      bool insertExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName);
      bool removeExplicitCell(int cellIndex);
      bool setExplicitCell(int cellIndex, int cellOffsetX, int cellOffsetY, int cellWidth, int cellHeight, String^ cellName);
      int getExplicitCellCount();
      String^ getExplicitCellOffset(String^ cell);
      String^ getExplicitCellOffset(int cellIdx);
      int getExplicitCellWidth(String^ cell);
      int getExplicitCellWidth(int cellIdx);
      int getExplicitCellHeight(String^ cell);
      int getExplicitCellHeight(int cellIdx);
      String^ getExplicitCellName(int cellIdx);
      int getExplicitCellIndex(String^ cell);
   };

   public ref class PluginAssetWrapper : AssetBaseWrapper
	{
   public:
      PluginAssetWrapper(int ID) : PluginAssetWrapper(ID){};

      PluginAsset* GetObjectPtr(){
         return static_cast<PluginAsset*>(mObject);
      };
	};

   public ref class ShaderAssetWrapper : AssetBaseWrapper
	{
   public:
      ShaderAssetWrapper(int ID) : AssetBaseWrapper(ID){};

      Graphics::ShaderAsset* GetObjectPtr(){
         return static_cast<Graphics::ShaderAsset*>(mObject);
      };
	};
}
