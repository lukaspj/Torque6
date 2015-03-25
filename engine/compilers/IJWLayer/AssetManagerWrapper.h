// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "SimSetWrapper.h"
#include "AssetWrappers.h"

#include "assets/assetManager.h"

using namespace System;

namespace IJWLayer {
   ref class AssetQueryWrapper;
   public ref class AssetManagerWrapper : SimObjectWrapper
   {
   public:
      AssetManagerWrapper(int ID) : SimObjectWrapper(ID){};

      AssetManager* GetObjectPtr(){
         return static_cast<AssetManager*>(mObject);
      };
/*
      bool compileReferencedAssets(ModuleDefinitionWrapper^ moduleDefinition);
      bool addModuleDeclaredAssets(ModuleDefinitionWrapper^ moduleDefinition);
      bool addDeclaredAsset(ModuleDefinitionWrapper^ moduleDefinition, String^ assetFilePath);
      String^ addPrivateAsset(AssetBaseWrapper^ assetObject);
      bool removeDeclaredAssets(ModuleDefinitionWrapper^ moduleDefinition);
      bool removeDeclaredAsset(int assetId);
      String^ getAssetName(int assetId);
      String^ getAssetDescription(int assetId);
      String^ getAssetCategory(int assetId);
      String^ getAssetType(int assetId);
      String^ getAssetFilePath(int assetId);
      String^ getAssetPath(int assetId);
      ModuleDefinitionWrapper^ getAssetModule(int assetId);
      bool isAssetInternal(int assetId);
      bool isAssetPrivate(int assetId);
      bool isAssetAutoUnload(int assetId);
      bool isAssetLoaded(int assetId);
      bool isDeclaredAsset(int assetId);
      bool isReferencedAsset(int assetId);
      bool renameDeclaredAsset(int assetIdFrom, int assetIdTo);
      bool renameReferencedAsset(int assetIdFrom, int assetIdTo);
      String^ acquireAsset(int assetId, bool asPrivate);
      String^ acquireAsset(int assetId);
      bool releaseAsset(int assetId);
      void purgeAssets();
      bool deleteAsset(int assetId, bool deleteLooseFiles, bool deleteDependencies);
      void refreshAsset(int assetId);
      void refreshAllAssets(bool includeUnloaded);
      bool saveAssetTags();
      bool restoreAssetTags();
      int getAssetTags();
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
      int findAssetDependsOn(AssetQueryWrapper^ assetQuery, int assetId);
      int findAssetIsDependedOn(AssetQueryWrapper^ assetQuery, int assetId);
      int findInvalidAssetReferences(AssetQueryWrapper^ assetQuery);
      int findTaggedAssets(AssetQueryWrapper^ assetQuery, String^ assetTagNames, bool assetQueryAsSource);
      int findTaggedAssets(AssetQueryWrapper^ assetQuery, String^ assetTagNames);
      int findAssetLooseFile(AssetQueryWrapper^ assetQuery, String^ assetLooseFile, bool assetQueryAsSource);
      int findAssetLooseFile(AssetQueryWrapper^ assetQuery, String^ assetLooseFile);
      int getDeclaredAssetCount();
      int getReferencedAssetCount();
      int getLoadedInternalAssetCount();
      int getMaxLoadedInternalAssetCount();
      int getLoadedExternalAssetCount();
      int getMaxLoadedExternalAssetCount();
      void dumpDeclaredAssets();*/
   };
}
