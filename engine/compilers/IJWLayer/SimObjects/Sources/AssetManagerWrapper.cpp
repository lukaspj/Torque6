#include "../../Stdafx.h"
#include "../Headers/AssetManagerWrapper.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::AssetQuery::clear()
{
   if (IsAlive())
      GetObjectPtr()->clear();
}

bool IJWLayer::AssetQuery::set(AssetQuery^ assetQuery)
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

int IJWLayer::AssetQuery::Count::get()
{
   if (IsAlive())
      return GetObjectPtr()->size();
}

String^ IJWLayer::AssetQuery::getAsset(int resultIndex)
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

void IJWLayer::AssetTagsManifest::createTag(String^ tagName)
{
   if (!IsAlive())
      return;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   GetObjectPtr()->createTag(_tagName);
}
bool IJWLayer::AssetTagsManifest::renameTag(String^ oldTagName, String^ newTagName)
{
   if (!IsAlive())
      return false;

   const char* _oldTagName = (char*)Marshal::StringToHGlobalAnsi(oldTagName).ToPointer();
   const char* _newTagName = (char*)Marshal::StringToHGlobalAnsi(newTagName).ToPointer();
   return GetObjectPtr()->renameTag(_oldTagName, _newTagName);
}
bool IJWLayer::AssetTagsManifest::deleteTag(String^ tagName)
{
   if (!IsAlive())
      return false;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   return GetObjectPtr()->deleteTag(_tagName);
}
bool IJWLayer::AssetTagsManifest::isTag(String^ tagName)
{
   if (!IsAlive())
      return false;

   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();
   return GetObjectPtr()->isTag(_tagName);
}
int IJWLayer::AssetTagsManifest::getTagCount()
{
   if (IsAlive())
      return GetObjectPtr()->getTagCount();
   return -1;
}
String^ IJWLayer::AssetTagsManifest::getTag(int tagIndex)
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
int IJWLayer::AssetTagsManifest::getAssetTagCount(String^ assetId)
{
   if (!IsAlive())
      return -1;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->getAssetTagCount(_assetId);
}
String^ IJWLayer::AssetTagsManifest::getAssetTag(String^ assetId, int tagIndex)
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
bool IJWLayer::AssetTagsManifest::tag(String^ assetId, String^ tagName)
{
   if (!IsAlive())
      return false;
   
   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();

   return GetObjectPtr()->tag(_assetId, _tagName);
}
bool IJWLayer::AssetTagsManifest::untag(String^ assetId, String^ tagName)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();

   return GetObjectPtr()->untag(_assetId, _tagName);
}
bool IJWLayer::AssetTagsManifest::hasTag(String^ assetId, String^ tagName)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   const char* _tagName = (char*)Marshal::StringToHGlobalAnsi(tagName).ToPointer();

   return GetObjectPtr()->hasTag(_assetId, _tagName);
}

bool IJWLayer::AssetManager::EchoInfo::get()
{
   if (IsAlive())
      return GetObjectPtr()->getEchoInfo();
   else
      return false;
}

void IJWLayer::AssetManager::EchoInfo::set(bool val)
{
   if (IsAlive())
      GetObjectPtr()->setEchoInfo(val);
}

bool IJWLayer::AssetManager::IgnoreAutoUnload::get()
{
   if (IsAlive())
      return GetObjectPtr()->getIgnoreAutoUnload();
   else
      return false;
}

void IJWLayer::AssetManager::IgnoreAutoUnload::set(bool val)
{
   if (IsAlive())
      GetObjectPtr()->setIgnoreAutoUnload(val);
}

bool IJWLayer::AssetManager::compileReferencedAssets(ModuleDefinition^ moduleDefinition)
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
 
bool IJWLayer::AssetManager::addModuleDeclaredAssets(ModuleDefinition^ moduleDefinition)
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
 
bool IJWLayer::AssetManager::addDeclaredAsset(ModuleDefinition^ moduleDefinition, String^ assetFilePath)
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

String^ IJWLayer::AssetManager::addPrivateAsset(AssetBase^ assetObject)
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

bool IJWLayer::AssetManager::removeDeclaredAssets(ModuleDefinition^ moduleDefinition)
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

bool IJWLayer::AssetManager::removeDeclaredAsset(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->removeDeclaredAsset(_assetId);
}

String^ IJWLayer::AssetManager::getAssetName(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetName(_assetId));
}

String^ IJWLayer::AssetManager::getAssetDescription(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetDescription(_assetId));
}

String^ IJWLayer::AssetManager::getAssetCategory(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetCategory(_assetId));
}

String^ IJWLayer::AssetManager::getAssetType(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetType(_assetId));
}

String^ IJWLayer::AssetManager::getAssetFilePath(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetFilePath(_assetId));
}

String^ IJWLayer::AssetManager::getAssetPath(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return gcnew String(GetObjectPtr()->getAssetPath(_assetId));
}

IJWLayer::ModuleDefinition^ IJWLayer::AssetManager::getAssetModule(String^ assetId)
{
   if (!IsAlive())
      return nullptr;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   EngineModuleDefinition* pModuleDefinition = GetObjectPtr()->getAssetModuleDefinition(_assetId);

   return pModuleDefinition == NULL ? nullptr : ModuleDefinition::Wrap(pModuleDefinition);
}

bool IJWLayer::AssetManager::isAssetInternal(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isAssetInternal(_assetId);
}

bool IJWLayer::AssetManager::isAssetPrivate(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isAssetPrivate(_assetId);
}

bool IJWLayer::AssetManager::isAssetAutoUnload(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isAssetAutoUnload(_assetId);
}

bool IJWLayer::AssetManager::isAssetLoaded(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isAssetLoaded(_assetId);
}

bool IJWLayer::AssetManager::isDeclaredAsset(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isDeclaredAsset(_assetId);
}

bool IJWLayer::AssetManager::isReferencedAsset(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* _assetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->isReferencedAsset(_assetId);
}

bool IJWLayer::AssetManager::renameDeclaredAsset(String^ assetIdFrom, String^ assetIdTo)
{
   if (!IsAlive())
      return false;

   const char* _assetIdFrom = (char*)Marshal::StringToHGlobalAnsi(assetIdFrom).ToPointer();
   const char* _assetIdTo = (char*)Marshal::StringToHGlobalAnsi(assetIdFrom).ToPointer();
   return GetObjectPtr()->renameDeclaredAsset(_assetIdFrom, _assetIdTo);
}

bool IJWLayer::AssetManager::renameReferencedAsset(String^ assetIdFrom, String^ assetIdTo)
{
   if (!IsAlive())
      return false;

   const char* _assetIdFrom = (char*)Marshal::StringToHGlobalAnsi(assetIdFrom).ToPointer();
   const char* _assetIdTo = (char*)Marshal::StringToHGlobalAnsi(assetIdFrom).ToPointer();
   return GetObjectPtr()->renameReferencedAsset(_assetIdFrom, _assetIdTo);
}

String^ IJWLayer::AssetManager::acquireAsset(String^ assetId, bool asPrivate)
{
   if (!IsAlive())
      return nullptr;

   const char* pAssetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();

   // Reset asset reference.
   EngineAssetBase* pAssetBase = NULL;

   // Acquire private asset?
   if (asPrivate)
   {
      // Acquire private asset.
      pAssetBase = GetObjectPtr()->acquireAsPrivateAsset<EngineAssetBase>(pAssetId);
   }
   else
   {
      // Acquire public asset.
      pAssetBase = GetObjectPtr()->acquireAsset<EngineAssetBase>(pAssetId);
   }

   return gcnew String(pAssetBase != NULL ? pAssetBase->getIdString() : StringTable->EmptyString);
}

String^ IJWLayer::AssetManager::acquireAsset(String^ assetId)
{
   return acquireAsset(assetId, false);
}

bool IJWLayer::AssetManager::releaseAsset(String^ assetId)
{
   if (!IsAlive())
      return false;

   const char* pAssetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   return GetObjectPtr()->releaseAsset(pAssetId);
}

void IJWLayer::AssetManager::purgeAssets()
{
   if (IsAlive())
      return GetObjectPtr()->purgeAssets();
}

bool IJWLayer::AssetManager::deleteAsset(String^ assetId, bool deleteLooseFiles, bool deleteDependencies)
{
   if (!IsAlive())
      return false;

   const char* pAssetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();

   // Delete asset.
   return GetObjectPtr()->deleteAsset(pAssetId, deleteLooseFiles, deleteDependencies);
}

void IJWLayer::AssetManager::refreshAsset(String^ assetId)
{
   if (!IsAlive())
      return;

   const char* pAssetId = (char*)Marshal::StringToHGlobalAnsi(assetId).ToPointer();
   GetObjectPtr()->refreshAsset(pAssetId);
}

void IJWLayer::AssetManager::refreshAllAssets(bool includeUnloaded)
{
   if (IsAlive())
      GetObjectPtr()->refreshAllAssets(includeUnloaded);
}

bool IJWLayer::AssetManager::saveAssetTags()
{
   if (IsAlive())
      GetObjectPtr()->saveAssetTags();
   return false;
}

bool IJWLayer::AssetManager::restoreAssetTags()
{
   if (IsAlive())
      GetObjectPtr()->restoreAssetTags();
   return false;
}

IJWLayer::AssetTagsManifest^ IJWLayer::AssetManager::getAssetTags()
{
   if (!IsAlive())
      return nullptr;

   // Fetch the asset tags manifest.
   EngineAssetTagsManifest* pAssetTagsManifest = GetObjectPtr()->getAssetTags();

   return pAssetTagsManifest == NULL ? nullptr : AssetTagsManifest::Wrap(pAssetTagsManifest);
}

int IJWLayer::AssetManager::findAllAssets(AssetQuery^ assetQuery, bool ignoreInternal, bool ignorePrivate)
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

int IJWLayer::AssetManager::findAllAssets(AssetQuery^ assetQuery, bool ignoreInternal)
{
   return findAllAssets(assetQuery, ignoreInternal, true);
}

int IJWLayer::AssetManager::findAllAssets(AssetQuery^ assetQuery)
{
   return findAllAssets(assetQuery, true, true);
}

int IJWLayer::AssetManager::findAssetName(AssetQuery^ assetQuery, String^ assetName, bool partialName)
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

int IJWLayer::AssetManager::findAssetName(AssetQuery^ assetQuery, String^ assetName)
{
   return findAssetName(assetQuery, assetName, false);
}

int IJWLayer::AssetManager::findAssetCategory(AssetQuery^ assetQuery, String^ assetName, bool assetQueryAsSource)
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

int IJWLayer::AssetManager::findAssetCategory(AssetQuery^ assetQuery, String^ assetName)
{
   return findAssetName(assetQuery, assetName, false);
}

int IJWLayer::AssetManager::findAssetAutoUnload(AssetQuery^ assetQuery, bool assetAutoUnload, bool assetQueryAsSource)
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

int IJWLayer::AssetManager::findAssetAutoUnload(AssetQuery^ assetQuery, bool assetAutoUnload)
{
   return findAssetAutoUnload(assetQuery, assetAutoUnload, false);
}

int IJWLayer::AssetManager::findAssetInternal(AssetQuery^ assetQuery, bool assetInternal, bool assetQueryAsSource)
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

int IJWLayer::AssetManager::findAssetInternal(AssetQuery^ assetQuery, bool assetInternal)
{
   return findAssetInternal(assetQuery, assetInternal, false);
}

int IJWLayer::AssetManager::findAssetPrivate(AssetQuery^ assetQuery, bool assetPrivate, bool assetQueryAsSource)
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

int IJWLayer::AssetManager::findAssetPrivate(AssetQuery^ assetQuery, bool assetPrivate)
{
   return findAssetPrivate(assetQuery, assetPrivate, false);
}

int IJWLayer::AssetManager::findAssetType(AssetQuery^ assetQuery, String^ assetType, bool assetQueryAsSource)
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

int IJWLayer::AssetManager::findAssetType(AssetQuery^ assetQuery, String^ assetType)
{
   return findAssetType(assetQuery, assetType, false);
}

int IJWLayer::AssetManager::findAssetDependsOn(AssetQuery^ assetQuery, String^ assetId)
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

int IJWLayer::AssetManager::findAssetIsDependedOn(AssetQuery^ assetQuery, String^ assetId)
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

int IJWLayer::AssetManager::findInvalidAssetReferences(AssetQuery^ assetQuery)
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

int IJWLayer::AssetManager::findTaggedAssets(AssetQuery^ assetQuery, String^ assetTagNames, bool assetQueryAsSource)
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

int IJWLayer::AssetManager::findTaggedAssets(AssetQuery^ assetQuery, String^ assetTagNames)
{
   return findTaggedAssets(assetQuery, assetTagNames, false);
}

int IJWLayer::AssetManager::findAssetLooseFile(AssetQuery^ assetQuery, String^ assetLooseFile, bool assetQueryAsSource)
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

int IJWLayer::AssetManager::findAssetLooseFile(AssetQuery^ assetQuery, String^ assetLooseFile)
{
   return findAssetLooseFile(assetQuery, assetLooseFile, false);
}

bool IJWLayer::AssetManager::getDeclaredAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getDeclaredAssetCount();
   return false;
}

bool IJWLayer::AssetManager::getReferencedAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getReferencedAssetCount();
   return false;
}

bool IJWLayer::AssetManager::getLoadedInternalAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getLoadedInternalAssetCount();
   return false;
}

bool IJWLayer::AssetManager::getMaxLoadedInternalAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getMaxLoadedInternalAssetCount();
   return false;
}

bool IJWLayer::AssetManager::getLoadedExternalAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getLoadedExternalAssetCount();
   return false;
}

bool IJWLayer::AssetManager::getMaxLoadedExternalAssetCount()
{
   if (IsAlive())
      return GetObjectPtr()->getMaxLoadedExternalAssetCount();
   return false;
}

void IJWLayer::AssetManager::dumpDeclaredAssets()
{
   if (IsAlive())
      GetObjectPtr()->dumpDeclaredAssets();
}