// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "CollectionsWrapper.h"
#include "AssetWrappers.h"
#include "ModuleWrappers.h"

#include "assets/assetManager.h"

using namespace System;

namespace IJWLayer {
   public ref class AssetTagsManifestWrapper : SimObjectWrapper
   {
   public:
      static AssetTagsManifestWrapper^ Wrap(int ID) { return static_cast<AssetTagsManifestWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static AssetTagsManifestWrapper^ Wrap(AssetTagsManifest* obj) { return static_cast<AssetTagsManifestWrapper^>(SimObjectWrapper::Wrap(obj)); };

      AssetTagsManifest* GetObjectPtr(){
         return static_cast<AssetTagsManifest*>(mObject);
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

   public ref class AssetQueryWrapper : SimObjectWrapper
   {
   public:
      static AssetQueryWrapper^ Wrap(int ID) { return static_cast<AssetQueryWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static AssetQueryWrapper^ Wrap(SimObject* obj) { return static_cast<AssetQueryWrapper^>(SimObjectWrapper::Wrap(obj)); };

      AssetQuery* GetObjectPtr(){
         return static_cast<AssetQuery*>(mObject);
      };

      void clear();
      bool set(AssetQueryWrapper^ assetQuery);
      int getCount();
      String^ getAsset(int resultIndex);
   };

   public ref class AssetManagerWrapper : SimObjectWrapper
   {
   public:
      static AssetManagerWrapper^ Wrap(int ID) { return static_cast<AssetManagerWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static AssetManagerWrapper^ Wrap(SimObject* obj) { return static_cast<AssetManagerWrapper^>(SimObjectWrapper::Wrap(obj)); };

      AssetManager* GetObjectPtr(){
         return static_cast<AssetManager*>(mObject);
      };

      bool compileReferencedAssets(ModuleDefinitionWrapper^ moduleDefinition);
      bool addModuleDeclaredAssets(ModuleDefinitionWrapper^ moduleDefinition);
      bool addDeclaredAsset(ModuleDefinitionWrapper^ moduleDefinition, String^ assetFilePath);
      String^ addPrivateAsset(AssetBaseWrapper^ assetObject);
      bool removeDeclaredAssets(ModuleDefinitionWrapper^ moduleDefinition);
      bool removeDeclaredAsset(String^ assetId);
      String^ getAssetName(String^ assetId);
      String^ getAssetDescription(String^ assetId);
      String^ getAssetCategory(String^ assetId);
      String^ getAssetType(String^ assetId);
      String^ getAssetFilePath(String^ assetId);
      String^ getAssetPath(String^ assetId);
      ModuleDefinitionWrapper^ getAssetModule(String^ assetId);
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
      AssetTagsManifestWrapper^ getAssetTags();
      int findAllAssets(AssetQueryWrapper^ assetQuery, bool ignoreInternal, bool ignorePrivate);
      int findAllAssets(AssetQueryWrapper^ assetQuery, bool ignoreInternal);
      int findAllAssets(AssetQueryWrapper^ assetQuery);
      int findAssetName(AssetQueryWrapper^ assetQuery, String^ assetName, bool partialName);
      int findAssetName(AssetQueryWrapper^ assetQuery, String^ assetName);
      int findAssetCategory(AssetQueryWrapper^ assetQuery, String^ assetCategory, bool assetQueryAsSource);
      int findAssetCategory(AssetQueryWrapper^ assetQuery, String^ assetCategory);
      int findAssetAutoUnload(AssetQueryWrapper^ assetQuery, bool assetAutoUnload, bool assetQueryAsSource);
      int findAssetAutoUnload(AssetQueryWrapper^ assetQuery, bool assetAutoUnload);
      int findAssetInternal(AssetQueryWrapper^ assetQuery, bool assetInternal, bool assetQueryAsSource);
      int findAssetInternal(AssetQueryWrapper^ assetQuery, bool assetInternal);
      int findAssetPrivate(AssetQueryWrapper^ assetQuery, bool assetPrivate, bool assetQueryAsSource);
      int findAssetPrivate(AssetQueryWrapper^ assetQuery, bool assetPrivate);
      int findAssetType(AssetQueryWrapper^ assetQuery, String^ assetType, bool assetQueryAsSource);
      int findAssetType(AssetQueryWrapper^ assetQuery, String^ assetType);
      int findAssetDependsOn(AssetQueryWrapper^ assetQuery, String^ assetId);
      int findAssetIsDependedOn(AssetQueryWrapper^ assetQuery, String^ assetId);
      int findInvalidAssetReferences(AssetQueryWrapper^ assetQuery);
      int findTaggedAssets(AssetQueryWrapper^ assetQuery, String^ assetTagNames, bool assetQueryAsSource);
      int findTaggedAssets(AssetQueryWrapper^ assetQuery, String^ assetTagNames);
      int findAssetLooseFile(AssetQueryWrapper^ assetQuery, String^ assetLooseFile, bool assetQueryAsSource);
      int findAssetLooseFile(AssetQueryWrapper^ assetQuery, String^ assetLooseFile);
      bool getDeclaredAssetCount();
      bool getReferencedAssetCount();
      bool getLoadedInternalAssetCount();
      bool getMaxLoadedInternalAssetCount();
      bool getLoadedExternalAssetCount();
      bool getMaxLoadedExternalAssetCount();
      void dumpDeclaredAssets();
   };


}
