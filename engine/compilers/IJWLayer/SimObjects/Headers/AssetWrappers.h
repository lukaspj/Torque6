// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

#include "assets/assetBase.h"
#include "assets/declaredAssets.h"
#include "assets/referencedAssets.h"
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

   public ref class DeclaredAssetWrapper : SimObjectWrapper
	{
   public:

      static DeclaredAssetWrapper^ Wrap(int ID) { return static_cast<DeclaredAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static DeclaredAssetWrapper^ Wrap(SimObject* obj) { return static_cast<DeclaredAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      DeclaredAssets* GetObjectPtr(){
         return static_cast<DeclaredAssets*>(mObject);
      };
	};

   public ref class ReferencedAssetsWrapper : SimObjectWrapper
	{
   public:

      static ReferencedAssetsWrapper^ Wrap(int ID) { return static_cast<ReferencedAssetsWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ReferencedAssetsWrapper^ Wrap(SimObject* obj) { return static_cast<ReferencedAssetsWrapper^>(SimObjectWrapper::Wrap(obj)); };

      ReferencedAssets* GetObjectPtr(){
         return static_cast<ReferencedAssets*>(mObject);
      };
	};

   public ref class AssetBaseWrapper : SimObjectWrapper
	{
   public:
      static AssetBaseWrapper^ Wrap(int ID) { return static_cast<AssetBaseWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static AssetBaseWrapper^ Wrap(SimObject* obj) { return static_cast<AssetBaseWrapper^>(SimObjectWrapper::Wrap(obj)); };

      AssetBase* GetObjectPtr(){
         return static_cast<AssetBase*>(mObject);
      };

      void refreshAsset();
      String^ getAssetId();
	};

   public ref class AudioAssetWrapper : AssetBaseWrapper
	{
   public:
      static AudioAssetWrapper^ Wrap(int ID) { return static_cast<AudioAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static AudioAssetWrapper^ Wrap(SimObject* obj) { return static_cast<AudioAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      AudioAsset* GetObjectPtr(){
         return static_cast<AudioAsset*>(mObject);
      };
	};

   public ref class BaseMaterialAssetWrapper : AssetBaseWrapper
	{
   public:
      static BaseMaterialAssetWrapper^ Wrap(int ID) { return static_cast<BaseMaterialAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static BaseMaterialAssetWrapper^ Wrap(SimObject* obj) { return static_cast<BaseMaterialAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      BaseMaterialAsset* GetObjectPtr(){
         return static_cast<BaseMaterialAsset*>(mObject);
      };
	};

   public ref class DeferredMaterialAssetWrapper : BaseMaterialAssetWrapper
	{
   public:
      static DeferredMaterialAssetWrapper^ Wrap(int ID) { return static_cast<DeferredMaterialAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static DeferredMaterialAssetWrapper^ Wrap(SimObject* obj) { return static_cast<DeferredMaterialAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      DeferredMaterialAsset* GetObjectPtr(){
         return static_cast<DeferredMaterialAsset*>(mObject);
      };
	};

   public ref class ForwardMaterialAssetWrapper : BaseMaterialAssetWrapper
	{
   public:
      static ForwardMaterialAssetWrapper^ Wrap(int ID) { return static_cast<ForwardMaterialAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ForwardMaterialAssetWrapper^ Wrap(SimObject* obj) { return static_cast<ForwardMaterialAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      ForwardMaterialAsset* GetObjectPtr(){
         return static_cast<ForwardMaterialAsset*>(mObject);
      };
	};

   public ref class MeshAssetWrapper : AssetBaseWrapper
	{
   public:
      static MeshAssetWrapper^ Wrap(int ID) { return static_cast<MeshAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static MeshAssetWrapper^ Wrap(SimObject* obj) { return static_cast<MeshAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      MeshAsset* GetObjectPtr(){
         return static_cast<MeshAsset*>(mObject);
      };
	};

   public ref class ImageAssetWrapper : AssetBaseWrapper
	{
   public:
      static ImageAssetWrapper^ Wrap(int ID) { return static_cast<ImageAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ImageAssetWrapper^ Wrap(SimObject* obj) { return static_cast<ImageAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

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
      static PluginAssetWrapper^ Wrap(int ID) { return static_cast<PluginAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static PluginAssetWrapper^ Wrap(SimObject* obj) { return static_cast<PluginAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      PluginAsset* GetObjectPtr(){
         return static_cast<PluginAsset*>(mObject);
      };
	};

   public ref class ShaderAssetWrapper : AssetBaseWrapper
	{
   public:
      static ShaderAssetWrapper^ Wrap(int ID) { return static_cast<ShaderAssetWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ShaderAssetWrapper^ Wrap(SimObject* obj) { return static_cast<ShaderAssetWrapper^>(SimObjectWrapper::Wrap(obj)); };

      Graphics::ShaderAsset* GetObjectPtr(){
         return static_cast<Graphics::ShaderAsset*>(mObject);
      };
	};
}
