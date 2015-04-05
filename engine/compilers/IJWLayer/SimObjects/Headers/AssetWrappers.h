// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

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

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef DeclaredAssets EngineDeclaredAssets;
typedef ReferencedAssets EngineReferencedAssets;
typedef AssetBase EngineAssetBase;
typedef AudioAsset EngineAudioAsset;
typedef BaseMaterialAsset EngineBaseMaterialAsset;
typedef DeferredMaterialAsset EngineDeferredMaterialAsset;
typedef ForwardMaterialAsset EngineForwardMaterialAsset;
typedef MeshAsset EngineMeshAsset;
typedef ImageAsset EngineImageAsset;
typedef PluginAsset EnginePluginAsset;

namespace IJWLayer {

   public ref class DeclaredAssets : SimObject
	{
   public:

      static DeclaredAssets^ Wrap(int ID) { return static_cast<DeclaredAssets^>(SimObject::Wrap(ID)); };
      static DeclaredAssets^ Wrap(EngineDeclaredAssets* obj) { return static_cast<DeclaredAssets^>(SimObject::Wrap(obj)); };

      EngineDeclaredAssets* GetObjectPtr(){
         return static_cast<EngineDeclaredAssets*>(mObject);
      };

      property String^ Path{
         String^ get();
         void set(String^ val);
      }
      property String^ Extension{
         String^ get();
         void set(String^ val);
      }
      property bool Recurse{
         bool get();
         void set(bool val);
      }
	};

   public ref class ReferencedAssets : SimObject
	{
   public:

      static ReferencedAssets^ Wrap(int ID) { return static_cast<ReferencedAssets^>(SimObject::Wrap(ID)); };
      static ReferencedAssets^ Wrap(EngineReferencedAssets* obj) { return static_cast<ReferencedAssets^>(SimObject::Wrap(obj)); };

      EngineReferencedAssets* GetObjectPtr(){
         return static_cast<EngineReferencedAssets*>(mObject);
      };

      property String^ Path{
         String^ get();
         void set(String^ val);
      }
      property String^ Extension{
         String^ get();
         void set(String^ val);
      }
      property bool Recurse{
         bool get();
         void set(bool val);
      }
	};

   public ref class AssetBase : SimObject
	{
   public:
      static AssetBase^ Wrap(int ID) { return static_cast<AssetBase^>(SimObject::Wrap(ID)); };
      static AssetBase^ Wrap(EngineAssetBase* obj) { return static_cast<AssetBase^>(SimObject::Wrap(obj)); };

      EngineAssetBase* GetObjectPtr(){
         return static_cast<EngineAssetBase*>(mObject);
      };

      property String^ AssetName{
         String^ get();
         void set(String^ val);
      }
      property String^ AssetDescription{
         String^ get();
         void set(String^ val);
      }
      property String^ AssetCategory{
         String^ get();
         void set(String^ val);
      }
      property bool AutoUnload{
         bool get();
         void set(bool val);
      }
      property bool Internal{
         bool get();
         void set(bool val);
      }
      property bool Private{
         bool get();
      }

      void refreshAsset();
      String^ getAssetId();
	};

   public ref class AudioAsset : AssetBase
	{
   public:
      static AudioAsset^ Wrap(int ID) { return static_cast<AudioAsset^>(SimObject::Wrap(ID)); };
      static AudioAsset^ Wrap(EngineAudioAsset* obj) { return static_cast<AudioAsset^>(SimObject::Wrap(obj)); };

      EngineAudioAsset* GetObjectPtr(){
         return static_cast<EngineAudioAsset*>(mObject);
      };
      property String^ AudioFile{
         String^ get();
         void set(String^ val);
      }
      property float Volume{
         float get();
         void set(float val);
      }
      property int VolumeChannel{
         int get();
         void set(int val);
      }
      property bool Looping{
         bool get();
         void set(bool val);
      }
      property bool Streaming{
         bool get();
         void set(bool val);
      }
	};

   ref class ShaderAsset;
   public ref class BaseMaterialAsset : AssetBase
	{
   public:
      static BaseMaterialAsset^ Wrap(int ID) { return static_cast<BaseMaterialAsset^>(SimObject::Wrap(ID)); };
      static BaseMaterialAsset^ Wrap(EngineBaseMaterialAsset* obj) { return static_cast<BaseMaterialAsset^>(SimObject::Wrap(obj)); };

      EngineBaseMaterialAsset* GetObjectPtr(){
         return static_cast<EngineBaseMaterialAsset*>(mObject);
      };

      void setShaderAsset(String^ assetId);
      ShaderAsset^ getShaderAsset();
	};

   public ref class DeferredMaterialAsset : BaseMaterialAsset
	{
   public:
      static DeferredMaterialAsset^ Wrap(int ID) { return static_cast<DeferredMaterialAsset^>(SimObject::Wrap(ID)); };
      static DeferredMaterialAsset^ Wrap(EngineDeferredMaterialAsset* obj) { return static_cast<DeferredMaterialAsset^>(SimObject::Wrap(obj)); };

      EngineDeferredMaterialAsset* GetObjectPtr(){
         return static_cast<EngineDeferredMaterialAsset*>(mObject);
      };
	};

   public ref class ForwardMaterialAsset : BaseMaterialAsset
	{
   public:
      static ForwardMaterialAsset^ Wrap(int ID) { return static_cast<ForwardMaterialAsset^>(SimObject::Wrap(ID)); };
      static ForwardMaterialAsset^ Wrap(EngineForwardMaterialAsset* obj) { return static_cast<ForwardMaterialAsset^>(SimObject::Wrap(obj)); };

      EngineForwardMaterialAsset* GetObjectPtr(){
         return static_cast<EngineForwardMaterialAsset*>(mObject);
      };
	};

   public ref class MeshAsset : AssetBase
   {
   public:
      static MeshAsset^ Wrap(int ID) { return static_cast<MeshAsset^>(SimObject::Wrap(ID)); };
      static MeshAsset^ Wrap(EngineMeshAsset* obj) { return static_cast<MeshAsset^>(SimObject::Wrap(obj)); };

      EngineMeshAsset* GetObjectPtr(){
         return static_cast<EngineMeshAsset*>(mObject);
      };

      property String^ MeshFile{
         String^ get();
         void set(String^ val);
      }
	};

   public ref class ImageAsset : AssetBase
	{
   public:
      static ImageAsset^ Wrap(int ID) { return static_cast<ImageAsset^>(SimObject::Wrap(ID)); };
      static ImageAsset^ Wrap(EngineImageAsset* obj) { return static_cast<ImageAsset^>(SimObject::Wrap(obj)); };

      EngineImageAsset* GetObjectPtr(){
         return static_cast<EngineImageAsset*>(mObject);
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

   public ref class PluginAsset : AssetBase
	{
   public:
      static PluginAsset^ Wrap(int ID) { return static_cast<PluginAsset^>(SimObject::Wrap(ID)); };
      static PluginAsset^ Wrap(EnginePluginAsset* obj) { return static_cast<PluginAsset^>(SimObject::Wrap(obj)); };

      EnginePluginAsset* GetObjectPtr(){
         return static_cast<EnginePluginAsset*>(mObject);
      };

      property String^ PluginFile{
         String^ get();
         void set(String^ val);
      }
	};

   public ref class ShaderAsset : AssetBase
	{
   public:
      static ShaderAsset^ Wrap(int ID) { return static_cast<ShaderAsset^>(SimObject::Wrap(ID)); };
      static ShaderAsset^ Wrap(Graphics::ShaderAsset* obj) { return static_cast<ShaderAsset^>(SimObject::Wrap(obj)); };

      Graphics::ShaderAsset* GetObjectPtr(){
         return static_cast<Graphics::ShaderAsset*>(mObject);
      };

      property String^ VertexShaderFile{
         String^ get();
         void set(String^ val);
      }
      property String^ PixelShaderFile{
         String^ get();
         void set(String^ val);
      }
	};
}
