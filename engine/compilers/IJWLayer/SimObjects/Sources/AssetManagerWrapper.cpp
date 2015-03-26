#include "../../Stdafx.h"
#include "../Headers/AssetManagerWrapper.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::AssetQueryWrapper::clear()
{
   if (IsAlive())
      GetObjectPtr()->clear();
}

bool IJWLayer::AssetQueryWrapper::set(AssetQueryWrapper^ assetQuery)
{
   if (!IsAlive())
      return false;

   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetQuery::set() - Could not find asset query '%s'.", "TODO, implement references");
      return false;
   }
   GetObjectPtr()->set(*assetQuery->GetObjectPtr());
}

int IJWLayer::AssetQueryWrapper::getCount()
{
   if (IsAlive())
      return GetObjectPtr()->size();
}

String^ IJWLayer::AssetQueryWrapper::getAsset(int resultIndex)
{
   if (!IsAlive())
      return nullptr;

   // Is index within bounds?
   if (resultIndex >= GetObjectPtr()->size())
   {
      // No, so warn.
      Con::warnf("AssetQuery::getAsset() - Result index '%s' is out of bounds.", "TODO, implement references");
      return nullptr;
   }

   return gcnew String(GetObjectPtr()->at(resultIndex));
}

void IJWLayer::AssetTagsManifestWrapper::createTag(String^ tagName)
{
   if (!IsAlive())
      return;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   GetObjectPtr()->createTag(_tagName);
}
bool IJWLayer::AssetTagsManifestWrapper::renameTag(String^ oldTagName, String^ newTagName)
{
   if (!IsAlive())
      return false;

   const char* _oldTagName = (char*)Marshal::StringToHGlobalAnsi(oldTagName).ToPointer();
   const char* _newTagName = (char*)Marshal::StringToHGlobalAnsi(newTagName).ToPointer();
   return GetObjectPtr()->renameTag(_oldTagName, _newTagName);
}
bool IJWLayer::AssetTagsManifestWrapper::deleteTag(String^ tagName)
{
   if (!IsAlive())
      return false;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   return GetObjectPtr()->deleteTag(_tagName);
}
bool IJWLayer::AssetTagsManifestWrapper::isTag(String^ tagName)
{
   if (!IsAlive())
      return false;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   return GetObjectPtr()->isTag(_tagName);
}
int IJWLayer::AssetTagsManifestWrapper::getTagCount()
{
   if (IsAlive())
      return GetObjectPtr()->getTagCount();
   return -1;
}
String^ IJWLayer::AssetTagsManifestWrapper::getTag(int tagIndex)
{
   if (!IsAlive())
      return nullptr;
   // Is the tag index out-of-bounds?
   if (tagIndex >= GetObjectPtr()->getTagCount())
   {
      // Yes, so warn.
      Con::warnf("AssetTagsManifest: Asset tag index '%d' is out of bounds.  Asset tag count is '%d'", tagIndex, GetObjectPtr()->getTagCount());
      return nullptr;
   }

   return gcnew String(GetObjectPtr()->getTag(tagIndex));
}
int IJWLayer::AssetTagsManifestWrapper::getAssetTagCount(String^ assetId)
{
   if (!IsAlive())
      return -1;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->getAssetTagCount(_assetId);
}
String^ IJWLayer::AssetTagsManifestWrapper::getAssetTag(String^ assetId, int tagIndex)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();

   // Is the tag index out-of-bounds?
   if (tagIndex >= GetObjectPtr()->getAssetTagCount(_assetId))
   {
      // Yes, so warn.
      Con::warnf("AssetTagsManifest: Asset tag index '%d' is out of bounds.  Asset tag count is '%d'", tagIndex, GetObjectPtr()->getTagCount());
      return nullptr;
   }

   return gcnew String(GetObjectPtr()->getAssetTag(_assetId, tagIndex));
}
bool IJWLayer::AssetTagsManifestWrapper::tag(String^ assetId, String^ tagName)
{
   if (!IsAlive())
      return false;
   
   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();

   return GetObjectPtr()->tag(_assetId, _tagName);
}
bool IJWLayer::AssetTagsManifestWrapper::untag(String^ assetId, String^ tagName)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();

   return GetObjectPtr()->untag(_assetId, _tagName);
}
bool IJWLayer::AssetTagsManifestWrapper::hasTag(String^ assetId, String^ tagName)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();

   return GetObjectPtr()->hasTag(_assetId, _tagName);
}

bool IJWLayer::AssetManagerWrapper::compileReferencedAssets(ModuleDefinitionWrapper^ moduleDefinition)
{
   if (!IsAlive())
      return false;
   if (!moduleDefinition->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::compileReferencedAssets() - Could not find the module definition '%s'.", "TODO, implement references");
      return false;
   }

   return GetObjectPtr()->compileReferencedAssets(moduleDefinition->GetObjectPtr());
}
 
bool IJWLayer::AssetManagerWrapper::addModuleDeclaredAssets(ModuleDefinitionWrapper^ moduleDefinition)
{
   if (!IsAlive())
      return false;
   if (!moduleDefinition->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::addModuleDeclaredAssets() - Could not find the module definition '%s'.", "TODO, implement references");
      return false;
   }

   return GetObjectPtr()->addModuleDeclaredAssets(moduleDefinition->GetObjectPtr());
}
 
bool IJWLayer::AssetManagerWrapper::addDeclaredAsset(ModuleDefinitionWrapper^ moduleDefinition, String^ assetFilePath)
{
   if (!IsAlive())
      return false;
   if (!moduleDefinition->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::addDeclaredAssets() - Could not find the module definition '%s'.", "TODO, implement references");
      return false;
   }

   const char* _assetFilePath = (char*)Marshal::StringToHGlobalAnsi(assetFilePath).ToPointer();
   return GetObjectPtr()->addDeclaredAsset(moduleDefinition->GetObjectPtr(), _assetFilePath);
}

String^ IJWLayer::AssetManagerWrapper::addPrivateAsset(AssetBaseWrapper^ assetObject)
{
   if (!IsAlive())
      return nullptr;
   if (!assetObject->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::addPrivateAsset() - Could not find the asset '%s'.", "TODO, implement references");
      return nullptr;
   }

   return gcnew String(GetObjectPtr()->addPrivateAsset(assetObject->GetObjectPtr()));
}

bool IJWLayer::AssetManagerWrapper::removeDeclaredAssets(ModuleDefinitionWrapper^ moduleDefinition)
{
   if (!IsAlive())
      return false;
   if (!moduleDefinition->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::removeDeclaredAssets() - Could not find the module definition '%s'.", "TODO, implement references");
      return false;
   }

   return GetObjectPtr()->removeDeclaredAssets(moduleDefinition->GetObjectPtr());
}

bool IJWLayer::AssetManagerWrapper::removeDeclaredAsset(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->removeDeclaredAsset(_assetId);
}

String^ IJWLayer::AssetManagerWrapper::getAssetName(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetName(_assetId));
}

String^ IJWLayer::AssetManagerWrapper::getAssetDescription(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetDescription(_assetId));
}

String^ IJWLayer::AssetManagerWrapper::getAssetCategory(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetCategory(_assetId));
}

String^ IJWLayer::AssetManagerWrapper::getAssetType(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetType(_assetId));
}

String^ IJWLayer::AssetManagerWrapper::getAssetFilePath(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetFilePath(_assetId));
}

String^ IJWLayer::AssetManagerWrapper::getAssetPath(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetPath(_assetId));
}

IJWLayer::ModuleDefinitionWrapper^ IJWLayer::AssetManagerWrapper::getAssetModule(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   ModuleDefinition* pModuleDefinition = GetObjectPtr()->getAssetModuleDefinition(_assetId);

   return pModuleDefinition == NULL ? nullptr : gcnew ModuleDefinitionWrapper(pModuleDefinition);
}

bool IJWLayer::AssetManagerWrapper::isAssetInternal(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isAssetInternal(_assetId);
}

bool IJWLayer::AssetManagerWrapper::isAssetPrivate(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isAssetPrivate(_assetId);
}

bool IJWLayer::AssetManagerWrapper::isAssetAutoUnload(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isAssetAutoUnload(_assetId);
}

bool IJWLayer::AssetManagerWrapper::isAssetLoaded(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isAssetLoaded(_assetId);
}

bool IJWLayer::AssetManagerWrapper::isDeclaredAsset(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isDeclaredAsset(_assetId);
}

bool IJWLayer::AssetManagerWrapper::isReferencedAsset(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isReferencedAsset(_assetId);
}

bool IJWLayer::AssetManagerWrapper::renameDeclaredAsset(String^ assetIdFrom, String^ assetIdTo)
{
   if (!IsAlive())
      return false;

   const char* _assetIdFrom = (char*)Marshal::StringToHGlobalAnsi(assetIdFrom).ToPointer();
   const char* _assetIdTo = (char*)Marshal::StringToHGlobalAnsi(assetIdFrom).ToPointer();
   return GetObjectPtr()->renameDeclaredAsset(_assetIdFrom, _assetIdTo);
}

bool IJWLayer::AssetManagerWrapper::renameReferencedAsset(String^ assetIdFrom, String^ assetIdTo)
{
   if (!IsAlive())
      return false;

   const char* _assetIdFrom = (char*)Marshal::StringToHGlobalAnsi(assetIdFrom).ToPointer();
   const char* _assetIdTo = (char*)Marshal::StringToHGlobalAnsi(assetIdFrom).ToPointer();
   return GetObjectPtr()->renameReferencedAsset(_assetIdFrom, _assetIdTo);
}

String^ IJWLayer::AssetManagerWrapper::acquireAsset(String^ assetId, bool asPrivate)
{
   if (!IsAlive())
      return nullptr;

   const char* pAssetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();

   // Reset asset reference.
   AssetBase* pAssetBase = NULL;

   // Acquire private asset?
   if (asPrivate)
   {
      // Acquire private asset.
      pAssetBase = GetObjectPtr()->acquireAsPrivateAsset<AssetBase>(pAssetId);
   }
   else
   {
      // Acquire public asset.
      pAssetBase = GetObjectPtr()->acquireAsset<AssetBase>(pAssetId);
   }

   return gcnew String(pAssetBase != NULL ? pAssetBase->getIdString() : StringTable->EmptyString);
}

String^ IJWLayer::AssetManagerWrapper::acquireAsset(String^ assetId)
{
   return acquireAsset(assetId, false);
}

bool IJWLayer::AssetManagerWrapper::releaseAsset(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* pAssetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->releaseAsset(pAssetId);
}

void IJWLayer::AssetManagerWrapper::purgeAssets()
{
   if (IsAlive())
      return GetObjectPtr()->purgeAssets();
}

bool IJWLayer::AssetManagerWrapper::deleteAsset(String^ assetId, bool deleteLooseFiles, bool deleteDependencies)
{
   if (!IsAlive())
      return false;

   const char* pAssetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();

   // Delete asset.
   return GetObjectPtr()->deleteAsset(pAssetId, deleteLooseFiles, deleteDependencies);
}

void IJWLayer::AssetManagerWrapper::refreshAsset(String^ assetId)
{
   if (!IsAlive())
      return;

   const char* pAssetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   GetObjectPtr()->refreshAsset(pAssetId);
}

void IJWLayer::AssetManagerWrapper::refreshAllAssets(bool includeUnloaded)
{
   if (IsAlive())
      GetObjectPtr()->refreshAllAssets(includeUnloaded);
}

bool IJWLayer::AssetManagerWrapper::saveAssetTags()
{
   if (IsAlive())
      GetObjectPtr()->saveAssetTags();
   return false;
}

bool IJWLayer::AssetManagerWrapper::restoreAssetTags()
{
   if (IsAlive())
      GetObjectPtr()->restoreAssetTags();
   return false;
}

IJWLayer::AssetTagsManifestWrapper^ IJWLayer::AssetManagerWrapper::getAssetTags()
{
   if (!IsAlive())
      return nullptr;

   // Fetch the asset tags manifest.
   AssetTagsManifest* pAssetTagsManifest = GetObjectPtr()->getAssetTags();

   return pAssetTagsManifest == NULL ? nullptr : gcnew AssetTagsManifestWrapper(pAssetTagsManifest);
}

int IJWLayer::AssetManagerWrapper::findAllAssets(AssetQueryWrapper^ assetQuery, bool ignoreInternal, bool ignorePrivate)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAllAssets() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   // Perform query.
   return GetObjectPtr()->findAllAssets(assetQuery->GetObjectPtr(), ignoreInternal, ignorePrivate);
}

int IJWLayer::AssetManagerWrapper::findAllAssets(AssetQueryWrapper^ assetQuery, bool ignoreInternal)
{
   return findAllAssets(assetQuery, ignoreInternal, true);
}

int IJWLayer::AssetManagerWrapper::findAllAssets(AssetQueryWrapper^ assetQuery)
{
   return findAllAssets(assetQuery, true, true);
}

int IJWLayer::AssetManagerWrapper::findAssetName(AssetQueryWrapper^ assetQuery, String^ assetName, bool partialName)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAssetName() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   const char* _assetName = (char*)Marshal::StringToHGlobalAnsi(assetName).ToPointer();

   // Perform query.
   return GetObjectPtr()->findAssetName(assetQuery->GetObjectPtr(), _assetName, partialName);
}

int IJWLayer::AssetManagerWrapper::findAssetName(AssetQueryWrapper^ assetQuery, String^ assetName)
{
   return findAssetName(assetQuery, assetName, false);
}

int IJWLayer::AssetManagerWrapper::findAssetCategory(AssetQueryWrapper^ assetQuery, String^ assetName, bool assetQueryAsSource)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAssetCategory() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   const char* _assetName = (char*)Marshal::StringToHGlobalAnsi(assetName).ToPointer();

   // Perform query.
   return GetObjectPtr()->findAssetCategory(assetQuery->GetObjectPtr(), _assetName, assetQueryAsSource);
}

int IJWLayer::AssetManagerWrapper::findAssetCategory(AssetQueryWrapper^ assetQuery, String^ assetName)
{
   return findAssetName(assetQuery, assetName, false);
}

int IJWLayer::AssetManagerWrapper::findAssetAutoUnload(AssetQueryWrapper^ assetQuery, bool assetAutoUnload, bool assetQueryAsSource)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAssetAutoUnload() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   // Perform query.
   return GetObjectPtr()->findAssetAutoUnload(assetQuery->GetObjectPtr(), assetAutoUnload, assetQueryAsSource);
}

int IJWLayer::AssetManagerWrapper::findAssetAutoUnload(AssetQueryWrapper^ assetQuery, bool assetAutoUnload)
{
   return findAssetAutoUnload(assetQuery, assetAutoUnload, false);
}

int IJWLayer::AssetManagerWrapper::findAssetInternal(AssetQueryWrapper^ assetQuery, bool assetInternal, bool assetQueryAsSource)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAssetInternal() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   // Perform query.
   return GetObjectPtr()->findAssetInternal(assetQuery->GetObjectPtr(), assetInternal, assetQueryAsSource);
}

int IJWLayer::AssetManagerWrapper::findAssetInternal(AssetQueryWrapper^ assetQuery, bool assetInternal)
{
   return findAssetInternal(assetQuery, assetInternal, false);
}

int IJWLayer::AssetManagerWrapper::findAssetPrivate(AssetQueryWrapper^ assetQuery, bool assetPrivate, bool assetQueryAsSource)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAssetPrivate() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   // Perform query.
   return GetObjectPtr()->findAssetPrivate(assetQuery->GetObjectPtr(), assetPrivate, assetQueryAsSource);
}

int IJWLayer::AssetManagerWrapper::findAssetPrivate(AssetQueryWrapper^ assetQuery, bool assetPrivate)
{
   return findAssetPrivate(assetQuery, assetPrivate, false);
}

int IJWLayer::AssetManagerWrapper::findAssetType(AssetQueryWrapper^ assetQuery, String^ assetType, bool assetQueryAsSource)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAssetType() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   const char* _assetType = (char*)Marshal::StringToHGlobalAnsi(assetType).ToPointer();

   // Perform query.
   return GetObjectPtr()->findAssetType(assetQuery->GetObjectPtr(), _assetType, assetQueryAsSource);
}

int IJWLayer::AssetManagerWrapper::findAssetType(AssetQueryWrapper^ assetQuery, String^ assetType)
{
   return findAssetType(assetQuery, assetType, false);
}

int IJWLayer::AssetManagerWrapper::findAssetDependsOn(AssetQueryWrapper^ assetQuery, String^ assetId)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAssetDependsOn() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();

   // Perform query.
   return GetObjectPtr()->findAssetDependsOn(assetQuery->GetObjectPtr(), _assetId);
}

int IJWLayer::AssetManagerWrapper::findAssetIsDependedOn(AssetQueryWrapper^ assetQuery, String^ assetId)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findAssetIsDependedOn() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();

   // Perform query.
   return GetObjectPtr()->findAssetIsDependedOn(assetQuery->GetObjectPtr(), _assetId);
}

int IJWLayer::AssetManagerWrapper::findInvalidAssetReferences(AssetQueryWrapper^ assetQuery)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findInvalidAssetReferences() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   // Perform query.
   return GetObjectPtr()->findInvalidAssetReferences(assetQuery->GetObjectPtr());
}

int IJWLayer::AssetManagerWrapper::findTaggedAssets(AssetQueryWrapper^ assetQuery, String^ assetTagNames, bool assetQueryAsSource)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findTaggedAssets() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   const char* _assetTagNames = (char*)Marshal::StringToHGlobalAnsi(assetTagNames).ToPointer();

   // Perform query.
   return GetObjectPtr()->findTaggedAssets(assetQuery->GetObjectPtr(), _assetTagNames, assetQueryAsSource);
}

int IJWLayer::AssetManagerWrapper::findTaggedAssets(AssetQueryWrapper^ assetQuery, String^ assetTagNames)
{
   return findTaggedAssets(assetQuery, assetTagNames, false);
}

int IJWLayer::AssetManagerWrapper::findAssetLooseFile(AssetQueryWrapper^ assetQuery, String^ assetLooseFile, bool assetQueryAsSource)
{
   if (!IsAlive())
      return -1;

   // Did we find the asset query?
   if (!assetQuery->IsAlive())
   {
      // No, so warn.
      Con::warnf("AssetManager::findTaggedAssets() - Could not find the asset query object '%s'.", "TODO, implement references");
      return -1;
   }

   const char* _assetLooseFile = (char*)Marshal::StringToHGlobalAnsi(assetLooseFile).ToPointer();

   // Perform query.
   return GetObjectPtr()->findAssetLooseFile(assetQuery->GetObjectPtr(), _assetLooseFile, assetQueryAsSource);
}

int IJWLayer::AssetManagerWrapper::findAssetLooseFile(AssetQueryWrapper^ assetQuery, String^ assetLooseFile)
{
   return findAssetLooseFile(assetQuery, assetLooseFile, false);
}

bool IJWLayer::AssetManagerWrapper::getDeclaredAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getDeclaredAssetCount();
   return false;
}

bool IJWLayer::AssetManagerWrapper::getReferencedAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getReferencedAssetCount();
   return false;
}

bool IJWLayer::AssetManagerWrapper::getLoadedInternalAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getLoadedInternalAssetCount();
   return false;
}

bool IJWLayer::AssetManagerWrapper::getMaxLoadedInternalAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getMaxLoadedInternalAssetCount();
   return false;
}

bool IJWLayer::AssetManagerWrapper::getLoadedExternalAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getLoadedExternalAssetCount();
   return false;
}

bool IJWLayer::AssetManagerWrapper::getMaxLoadedExternalAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getMaxLoadedExternalAssetCount();
   return false;
}

void IJWLayer::AssetManagerWrapper::dumpDeclaredAssets()
{
   if (IsAlive())
      GetObjectPtr()->dumpDeclaredAssets();
}