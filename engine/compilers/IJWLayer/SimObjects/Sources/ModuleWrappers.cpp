#include "../../Stdafx.h"
#include "../Headers/ModuleWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::ModuleManagerWrapper::setModuleExtension(String^ moduleExtension)
{
   if (!IsAlive())
      return false;
   const char* _moduleExtension = (char*)Marshal::StringToHGlobalAnsi(moduleExtension).ToPointer();
   return GetObjectPtr()->setModuleExtension(_moduleExtension);
}

bool IJWLayer::ModuleManagerWrapper::scanModules(String^ rootPath, bool rootOnly)
{
   if (!IsAlive())
      return false;

   const char* _rootPath = (char*)Marshal::StringToHGlobalAnsi(rootPath).ToPointer();
   return GetObjectPtr()->scanModules(_rootPath, rootOnly);
}

bool IJWLayer::ModuleManagerWrapper::scanModules(String^ rootPath)
{
   return scanModules(rootPath, false);
}

bool IJWLayer::ModuleManagerWrapper::unregisterModule(String^ moduleId, int versionId)
{
   if (!IsAlive())
      return false;

   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   return GetObjectPtr()->unregisterModule(_moduleId, versionId);
}

bool IJWLayer::ModuleManagerWrapper::unregisterModule(String^ moduleId)
{
   return unregisterModule(moduleId, 0);
}

bool IJWLayer::ModuleManagerWrapper::loadGroup(String^ moduleGroup)
{
   if (!IsAlive())
      return false;

   const char* _moduleGroup = (char*)Marshal::StringToHGlobalAnsi(moduleGroup).ToPointer();
   return GetObjectPtr()->loadModuleGroup(_moduleGroup);
}

bool IJWLayer::ModuleManagerWrapper::unloadGroup(String^ moduleGroup)
{
   if (!IsAlive())
      return false;

   const char* _moduleGroup = (char*)Marshal::StringToHGlobalAnsi(moduleGroup).ToPointer();
   return GetObjectPtr()->unloadModuleGroup(_moduleGroup);
}

bool IJWLayer::ModuleManagerWrapper::loadExplicit(String^ moduleId, int versionId)
{
   if (!IsAlive())
      return false;

   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   return GetObjectPtr()->loadModuleExplicit(_moduleId, versionId);
}

bool IJWLayer::ModuleManagerWrapper::loadExplicit(String^ moduleId)
{
   return loadExplicit(moduleId, 0);
}

bool IJWLayer::ModuleManagerWrapper::unloadExplicit(String^ moduleId)
{
   if (!IsAlive())
      return false;

   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   return GetObjectPtr()->unloadModuleExplicit(_moduleId);
}

IJWLayer::ModuleDefinitionWrapper^ IJWLayer::ModuleManagerWrapper::findModule(String^ moduleId, int versionId)
{
   if (!IsAlive())
      return nullptr;

   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   
   ModuleDefinition* modDef = GetObjectPtr()->findModule(_moduleId, versionId);

   return gcnew ModuleDefinitionWrapper(modDef);
}

array<IJWLayer::ModuleDefinitionWrapper^>^ IJWLayer::ModuleManagerWrapper::findModules(bool loadedOnly)
{
   if (!IsAlive())
      return nullptr;

   // Find module type definitions.
   Vector<const ModuleDefinition*> moduleDefinitions;

   // Find modules.
   GetObjectPtr()->findModules(loadedOnly, moduleDefinitions);

   array<IJWLayer::ModuleDefinitionWrapper^>^ retArr = gcnew array<IJWLayer::ModuleDefinitionWrapper^>(moduleDefinitions.size());

   for (int i = 0; i < moduleDefinitions.size(); i++)
   {
      retArr[i] = gcnew ModuleDefinitionWrapper(const_cast<ModuleDefinition*>(moduleDefinitions[i]));
   }

   return retArr;
}

array<IJWLayer::ModuleDefinitionWrapper^>^ IJWLayer::ModuleManagerWrapper::findModules()
{
   return findModules(false);
}

array<IJWLayer::ModuleDefinitionWrapper^>^ IJWLayer::ModuleManagerWrapper::findModuleTypes(String^ moduleType, bool loadedOnly)
{
   if (!IsAlive())
      return nullptr;

   const char* _moduleType = (char*)Marshal::StringToHGlobalAnsi(moduleType).ToPointer();

   // Find module type definitions.
   Vector<const ModuleDefinition*> moduleDefinitions;

   // Find modules.
   GetObjectPtr()->findModules(loadedOnly, moduleDefinitions);

   GetObjectPtr()->findModuleTypes(_moduleType, loadedOnly, moduleDefinitions);

   array<IJWLayer::ModuleDefinitionWrapper^>^ retArr = gcnew array<IJWLayer::ModuleDefinitionWrapper^>(moduleDefinitions.size());

   for (int i = 0; i < moduleDefinitions.size(); i++)
   {
      retArr[i] = gcnew ModuleDefinitionWrapper(const_cast<ModuleDefinition*>(moduleDefinitions[i]));
   }

   return retArr;
}

array<IJWLayer::ModuleDefinitionWrapper^>^ IJWLayer::ModuleManagerWrapper::findModuleTypes(String^ moduleType)
{
   return findModuleTypes(moduleType, false);
}

String^ IJWLayer::ModuleManagerWrapper::copyModule(ModuleDefinitionWrapper^ source, String^ targetId, String^ targetPath, bool useVersionPathing)
{
   if (!IsAlive() || !source->IsAlive())
      return nullptr;

   const char* _target = (char*)Marshal::StringToHGlobalAnsi(targetId).ToPointer();
   const char* _targetPath = (char*)Marshal::StringToHGlobalAnsi(targetPath).ToPointer();

   return gcnew String(GetObjectPtr()->copyModule(source->GetObjectPtr(), _target, _targetPath, useVersionPathing));
}

bool IJWLayer::ModuleManagerWrapper::synchronizeDependencies(ModuleDefinitionWrapper^ root, String^ targetDependencyPath)
{
   if (!IsAlive() || !root->IsAlive())
      return false;

   const char* _targetDependencyPath = (char*)Marshal::StringToHGlobalAnsi(targetDependencyPath).ToPointer();

   return GetObjectPtr()->synchronizeDependencies(root->GetObjectPtr(), _targetDependencyPath);
}

bool IJWLayer::ModuleManagerWrapper::isModuleMergeAvailable()
{
   if (IsAlive())
      return GetObjectPtr()->isModuleMergeAvailable();
   return false;
}

bool IJWLayer::ModuleManagerWrapper::canMergeModules(String^ mergeSourcePath)
{
   if (!IsAlive())
      return false;

   const char* _mergeSourcePath = (char*)Marshal::StringToHGlobalAnsi(mergeSourcePath).ToPointer();
   return GetObjectPtr()->canMergeModules(_mergeSourcePath);
}

bool IJWLayer::ModuleManagerWrapper::mergeModules(String^ mergeTargetPath, bool removeMergeDefinition, bool registerNewModules)
{
   if (!IsAlive())
      return false;

   const char* _mergeTargetPath = (char*)Marshal::StringToHGlobalAnsi(mergeTargetPath).ToPointer();
   return GetObjectPtr()->mergeModules(_mergeTargetPath, removeMergeDefinition, registerNewModules);
}

void IJWLayer::ModuleManagerWrapper::addListener(SimObjectWrapper^ listener)
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

void IJWLayer::ModuleManagerWrapper::removeListener(SimObjectWrapper^ listener)
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

bool IJWLayer::ModuleDefinitionWrapper::save()
{
   if (IsAlive())
      return GetObjectPtr()->save();
   return false;
}

IJWLayer::ModuleManagerWrapper^ IJWLayer::ModuleDefinitionWrapper::getModuleManager()
{
   if (!IsAlive())
      return nullptr;
   // Fetch module manager.
   ModuleManager* pModuleManager = GetObjectPtr()->getModuleManager();

   return pModuleManager != NULL ? gcnew ModuleManagerWrapper(pModuleManager) : nullptr;
}

int IJWLayer::ModuleDefinitionWrapper::getDependencyCount()
{
   if (IsAlive())
      return GetObjectPtr()->getDependencyCount();
   return -1;
}

String^ IJWLayer::ModuleDefinitionWrapper::getDependency(int dependencyIndex)
{
   if (!IsAlive())
      return nullptr;
   // Get module dependency.
   ModuleDefinition::ModuleDependency dependency;
   if (GetObjectPtr()->getDependency(dependencyIndex, dependency) == false)
      return String::Empty;

   // Format module dependency.
   char* pReturnBuffer = Con::getReturnBuffer(256);
   dSprintf(pReturnBuffer, 256, "%s %d", dependency.mModuleId, dependency.mVersionId);

   return gcnew String(pReturnBuffer);
}

bool IJWLayer::ModuleDefinitionWrapper::addDependency(String^ moduleId, int versionId)
{
   if (!IsAlive())
      return false;
   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   GetObjectPtr()->addDependency(_moduleId, versionId);
}

bool IJWLayer::ModuleDefinitionWrapper::removeDependency(String^ moduleId)
{
   if (!IsAlive())
      return false;
   const char* _moduleId = (char*)Marshal::StringToHGlobalAnsi(moduleId).ToPointer();
   GetObjectPtr()->removeDependency(_moduleId);
}