// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "CollectionsWrapper.h"
#include "AssetWrappers.h"
#include "ModuleWrappers.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "assets/assetManager.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef AssetTagsManifest EngineAssetTagsManifest;
typedef AssetQuery EngineAssetQuery;
typedef AssetManager EngineAssetManager;

namespace IJWLayer {
   public ref class AssetTagsManifest : SimObject
   {
   public:
      static AssetTagsManifest^ Wrap(int ID) { return static_cast<AssetTagsManifest^>(SimObject::Wrap(ID)); };
      static AssetTagsManifest^ Wrap(String^ Name) { return static_cast<AssetTagsManifest^>(SimObject::Wrap(Name)); };
      static AssetTagsManifest^ Wrap(EngineAssetTagsManifest* obj) { return static_cast<AssetTagsManifest^>(SimObject::Wrap(obj)); };

      EngineAssetTagsManifest* GetObjectPtr(){
         return static_cast<EngineAssetTagsManifest*>(mObject);
      };

      void createTag(String^ tagName);
      bool renameTag(String^ oldTagName, String^ newTagName);
      bool deleteTag(String^ tagName);
      bool isTag(String^ tagName);
      int getTagCount();
      String^ getTag(int tagIndex);
      int getAssetTagCount(String^ assetId);
      String^ getAssetTag(String^ assetId, int tagIndex);
      bool tag(String^ assetId, String^ tagName);
      bool untag(String^ assetId, String^ tagName);
      bool hasTag(String^ assetId, String^ tagName);
   };

   public ref class AssetQuery : SimObject
   {
   public:
      static AssetQuery^ Wrap(int ID) { return static_cast<AssetQuery^>(SimObject::Wrap(ID)); };
      static AssetQuery^ Wrap(String^ Name) { return static_cast<AssetQuery^>(SimObject::Wrap(Name)); };
      static AssetQuery^ Wrap(EngineAssetQuery* obj) { return static_cast<AssetQuery^>(SimObject::Wrap(obj)); };

      EngineAssetQuery* GetObjectPtr(){
         return static_cast<EngineAssetQuery*>(mObject);
      };

      void clear();
      bool set(AssetQuery^ assetQuery);
      String^ getAsset(int resultIndex);
      property int Count{
         int get();
      }
   };

   public ref class AssetManager : SimObject
   {
   public:
      static AssetManager^ Wrap(int ID) { return static_cast<AssetManager^>(SimObject::Wrap(ID)); };
      static AssetManager^ Wrap(String^ Name) { return static_cast<AssetManager^>(SimObject::Wrap(Name)); };
      static AssetManager^ Wrap(EngineAssetManager* obj) { return static_cast<AssetManager^>(SimObject::Wrap(obj)); };

      EngineAssetManager* GetObjectPtr(){
         return static_cast<EngineAssetManager*>(mObject);
      };

      property bool EchoInfo{
         bool get();
         void set(bool val);
      }

      property bool IgnoreAutoUnload{
         bool get();
         void set(bool val);
      }

      bool compileReferencedAssets(ModuleDefinition^ moduleDefinition);
      bool addModuleDeclaredAssets(ModuleDefinition^ moduleDefinition);
      bool addDeclaredAsset(ModuleDefinition^ moduleDefinition, String^ assetFilePath);
      String^ addPrivateAsset(AssetBase^ assetObject);
      bool removeDeclaredAssets(ModuleDefinition^ moduleDefinition);
      bool removeDeclaredAsset(String^ assetId);
      String^ getAssetName(String^ assetId);
      String^ getAssetDescription(String^ assetId);
      String^ getAssetCategory(String^ assetId);
      String^ getAssetType(String^ assetId);
      String^ getAssetFilePath(String^ assetId);
      String^ getAssetPath(String^ assetId);
      ModuleDefinition^ getAssetModule(String^ assetId);
      bool isAssetInternal(String^ assetId);
      bool isAssetPrivate(String^ assetId);
      bool isAssetAutoUnload(String^ assetId);
      bool isAssetLoaded(String^ assetId);
      bool isDeclaredAsset(String^ assetId);
      bool isReferencedAsset(String^ assetId);
      bool renameDeclaredAsset(String^ assetIdFrom, String^ assetIdTo);
      bool renameReferencedAsset(String^ assetIdFrom, String^ assetIdTo);
      String^ acquireAsset(String^ assetId, bool asPrivate);
      String^ acquireAsset(String^ assetId);
      bool releaseAsset(String^ assetId);
      void purgeAssets();
      bool deleteAsset(String^ assetId, bool deleteLooseFiles, bool deleteDependencies);
      void refreshAsset(String^ assetId);
      void refreshAllAssets(bool includeUnloaded);
      bool saveAssetTags();
      bool restoreAssetTags();
      AssetTagsManifest^ getAssetTags();
      int findAllAssets(AssetQuery^ assetQuery, bool ignoreInternal, bool ignorePrivate);
      int findAllAssets(AssetQuery^ assetQuery, bool ignoreInternal);
      int findAllAssets(AssetQuery^ assetQuery);
      int findAssetName(AssetQuery^ assetQuery, String^ assetName, bool partialName);
      int findAssetName(AssetQuery^ assetQuery, String^ assetName);
      int findAssetCategory(AssetQuery^ assetQuery, String^ assetCategory, bool assetQueryAsSource);
      int findAssetCategory(AssetQuery^ assetQuery, String^ assetCategory);
      int findAssetAutoUnload(AssetQuery^ assetQuery, bool assetAutoUnload, bool assetQueryAsSource);
      int findAssetAutoUnload(AssetQuery^ assetQuery, bool assetAutoUnload);
      int findAssetInternal(AssetQuery^ assetQuery, bool assetInternal, bool assetQueryAsSource);
      int findAssetInternal(AssetQuery^ assetQuery, bool assetInternal);
      int findAssetPrivate(AssetQuery^ assetQuery, bool assetPrivate, bool assetQueryAsSource);
      int findAssetPrivate(AssetQuery^ assetQuery, bool assetPrivate);
      int findAssetType(AssetQuery^ assetQuery, String^ assetType, bool assetQueryAsSource);
      int findAssetType(AssetQuery^ assetQuery, String^ assetType);
      int findAssetDependsOn(AssetQuery^ assetQuery, String^ assetId);
      int findAssetIsDependedOn(AssetQuery^ assetQuery, String^ assetId);
      int findInvalidAssetReferences(AssetQuery^ assetQuery);
      int findTaggedAssets(AssetQuery^ assetQuery, String^ assetTagNames, bool assetQueryAsSource);
      int findTaggedAssets(AssetQuery^ assetQuery, String^ assetTagNames);
      int findAssetLooseFile(AssetQuery^ assetQuery, String^ assetLooseFile, bool assetQueryAsSource);
      int findAssetLooseFile(AssetQuery^ assetQuery, String^ assetLooseFile);
      bool getDeclaredAssetCount();
      bool getReferencedAssetCount();
      bool getLoadedInternalAssetCount();
      bool getMaxLoadedInternalAssetCount();
      bool getLoadedExternalAssetCount();
      bool getMaxLoadedExternalAssetCount();
      void dumpDeclaredAssets();
   };


}
