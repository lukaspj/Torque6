#include "../../Stdafx.h"
#include "../Headers/ModuleWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::ModuleManager::setModuleExtension(String^ moduleExtension)
{
   if (!IsAlive())
      return false;
   const char* _moduleExtension = (char*)Marshal::StringToHGlobalAnsi(moduleExtension).ToPointer();
   return GetObjectPtr()->setModuleExtension(_moduleExtension);
}

bool IJWLayer::ModuleManager::scanModules(String^ rootPath, bool rootOnly)
{
   if (!IsAlive())
      return false;

   const char* _rootPath = (char*)Marshal::StringToHGlobalAnsi(rootPath).ToPointer();
   return GetObjectPtr()->scanModules(_rootPath, rootOnly);
}

bool IJWLayer::ModuleManager::scanModules(String^ rootPath)
{
   return scanModules(rootPath, false);
}

bool IJWLayer::ModuleManager::unregisterModule(String^ moduleId, int versionId)
{
   if (!IsAlive())
      return false;

   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   return GetObjectPtr()->unregisterModule(_moduleId, versionId);
}

bool IJWLayer::ModuleManager::unregisterModule(String^ moduleId)
{
   return unregisterModule(moduleId, 0);
}

bool IJWLayer::ModuleManager::loadGroup(String^ moduleGroup)
{
   if (!IsAlive())
      return false;

   const char* _moduleGroup = (char*)Marshal::StringToHGlobalAnsi(moduleGroup).ToPointer();
   return GetObjectPtr()->loadModuleGroup(_moduleGroup);
}

bool IJWLayer::ModuleManager::unloadGroup(String^ moduleGroup)
{
   if (!IsAlive())
      return false;

   const char* _moduleGroup = (char*)Marshal::StringToHGlobalAnsi(moduleGroup).ToPointer();
   return GetObjectPtr()->unloadModuleGroup(_moduleGroup);
}

bool IJWLayer::ModuleManager::loadExplicit(String^ moduleId, int versionId)
{
   if (!IsAlive())
      return false;

   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   return GetObjectPtr()->loadModuleExplicit(_moduleId, versionId);
}

bool IJWLayer::ModuleManager::loadExplicit(String^ moduleId)
{
   return loadExplicit(moduleId, 0);
}

bool IJWLayer::ModuleManager::unloadExplicit(String^ moduleId)
{
   if (!IsAlive())
      return false;

   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   return GetObjectPtr()->unloadModuleExplicit(_moduleId);
}

IJWLayer::ModuleDefinition^ IJWLayer::ModuleManager::findModule(String^ moduleId, int versionId)
{
   if (!IsAlive())
      return nullptr;

   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   
   EngineModuleDefinition* modDef = GetObjectPtr()->findModule(_moduleId, versionId);

   return ModuleDefinition::Wrap(modDef);
}

array<IJWLayer::ModuleDefinition^>^ IJWLayer::ModuleManager::findModules(bool loadedOnly)
{
   if (!IsAlive())
      return nullptr;

   // Find module type definitions.
   Vector<const EngineModuleDefinition*> moduleDefinitions;

   // Find modules.
   GetObjectPtr()->findModules(loadedOnly, moduleDefinitions);

   array<IJWLayer::ModuleDefinition^>^ retArr = gcnew array<IJWLayer::ModuleDefinition^>(moduleDefinitions.size());

   for (int i = 0; i < moduleDefinitions.size(); i++)
   {
      retArr[i] = ModuleDefinition::Wrap(const_cast<EngineModuleDefinition*>(moduleDefinitions[i]));
   }

   return retArr;
}

array<IJWLayer::ModuleDefinition^>^ IJWLayer::ModuleManager::findModules()
{
   return findModules(false);
}

array<IJWLayer::ModuleDefinition^>^ IJWLayer::ModuleManager::findModuleTypes(String^ moduleType, bool loadedOnly)
{
   if (!IsAlive())
      return nullptr;

   const char* _moduleType = (char*)Marshal::StringToHGlobalAnsi(moduleType).ToPointer();

   // Find module type definitions.
   Vector<const EngineModuleDefinition*> moduleDefinitions;

   // Find modules.
   GetObjectPtr()->findModules(loadedOnly, moduleDefinitions);

   GetObjectPtr()->findModuleTypes(_moduleType, loadedOnly, moduleDefinitions);

   array<IJWLayer::ModuleDefinition^>^ retArr = gcnew array<IJWLayer::ModuleDefinition^>(moduleDefinitions.size());

   for (int i = 0; i < moduleDefinitions.size(); i++)
   {
      retArr[i] = ModuleDefinition::Wrap(const_cast<EngineModuleDefinition*>(moduleDefinitions[i]));
   }

   return retArr;
}

array<IJWLayer::ModuleDefinition^>^ IJWLayer::ModuleManager::findModuleTypes(String^ moduleType)
{
   return findModuleTypes(moduleType, false);
}

String^ IJWLayer::ModuleManager::copyModule(ModuleDefinition^ source, String^ targetId, String^ targetPath, bool useVersionPathing)
{
   if (!IsAlive() || !source->IsAlive())
      return nullptr;

   const char* _target = (char*)Marshal::StringToHGlobalAnsi(targetId).ToPointer();
   const char* _targetPath = (char*)Marshal::StringToHGlobalAnsi(targetPath).ToPointer();

   return gcnew String(GetObjectPtr()->copyModule(source->GetObjectPtr(), _target, _targetPath, useVersionPathing));
}

bool IJWLayer::ModuleManager::synchronizeDependencies(ModuleDefinition^ root, String^ targetDependencyPath)
{
   if (!IsAlive() || !root->IsAlive())
      return false;

   const char* _targetDependencyPath = (char*)Marshal::StringToHGlobalAnsi(targetDependencyPath).ToPointer();

   return GetObjectPtr()->synchronizeDependencies(root->GetObjectPtr(), _targetDependencyPath);
}

bool IJWLayer::ModuleManager::isModuleMergeAvailable()
{
   if (IsAlive())
      return GetObjectPtr()->isModuleMergeAvailable();
   return false;
}

bool IJWLayer::ModuleManager::canMergeModules(String^ mergeSourcePath)
{
   if (!IsAlive())
      return false;

   const char* _mergeSourcePath = (char*)Marshal::StringToHGlobalAnsi(mergeSourcePath).ToPointer();
   return GetObjectPtr()->canMergeModules(_mergeSourcePath);
}

bool IJWLayer::ModuleManager::mergeModules(String^ mergeTargetPath, bool removeMergeDefinition, bool registerNewModules)
{
   if (!IsAlive())
      return false;

   const char* _mergeTargetPath = (char*)Marshal::StringToHGlobalAnsi(mergeTargetPath).ToPointer();
   return GetObjectPtr()->mergeModules(_mergeTargetPath, removeMergeDefinition, registerNewModules);
}

void IJWLayer::ModuleManager::addListener(SimObject^ listener)
{
   if (!IsAlive())
      return;

   if (!listener->IsAlive())
   {
      // No, so warn.
      Con::warnf("ModuleManager::addListener() - Could not find the listener object '%s'.", "TODO, implement references");
      return;
   }

   return GetObjectPtr()->addListener(listener->GetObjectPtr());
}

void IJWLayer::ModuleManager::removeListener(SimObject^ listener)
{
   if (!IsAlive())
      return;

   if (!listener->IsAlive())
   {
      // No, so warn.
      Con::warnf("ModuleManager::removeListener() - Could not find the listener object '%s'.", "TODO, implement references");
      return;
   }

   return GetObjectPtr()->removeListener(listener->GetObjectPtr());
}

bool IJWLayer::ModuleDefinition::save()
{
   if (IsAlive())
      return GetObjectPtr()->save();
   return false;
}

IJWLayer::ModuleManager^ IJWLayer::ModuleDefinition::getModuleManager()
{
   if (!IsAlive())
      return nullptr;
   // Fetch module manager.
   EngineModuleManager* pModuleManager = GetObjectPtr()->getModuleManager();

   return pModuleManager != NULL ? ModuleManager::Wrap(pModuleManager) : nullptr;
}

int IJWLayer::ModuleDefinition::getDependencyCount()
{
   if (IsAlive())
      return GetObjectPtr()->getDependencyCount();
   return -1;
}

String^ IJWLayer::ModuleDefinition::getDependency(int dependencyIndex)
{
   if (!IsAlive())
      return nullptr;
   // Get module dependency.
   EngineModuleDefinition::ModuleDependency dependency;
   if (GetObjectPtr()->getDependency(dependencyIndex, dependency) == false)
      return String::Empty;

   // Format module dependency.
   char* pReturnBuffer = Con::getReturnBuffer(256);
   dSprintf(pReturnBuffer, 256, "%s %d", dependency.mModuleId, dependency.mVersionId);

   return gcnew String(pReturnBuffer);
}

bool IJWLayer::ModuleDefinition::addDependency(String^ moduleId, int versionId)
{
   if (!IsAlive())
      return false;
   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   GetObjectPtr()->addDependency(_moduleId, versionId);
}

bool IJWLayer::ModuleDefinition::removeDependency(String^ moduleId)
{
   if (!IsAlive())
      return false;
   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   GetObjectPtr()->removeDependency(_moduleId);
}