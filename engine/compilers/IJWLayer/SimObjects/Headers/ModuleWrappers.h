// IJWLayer.h

#pragma once

#include "CollectionsWrapper.h"
#include "module/moduleManager.h"
#include "module/moduleMergeDefinition.h"

using namespace System;

namespace IJWLayer {

   ref class ModuleDefinitionWrapper;
   public ref class ModuleManagerWrapper : SimObjectWrapper
   {

   public:
      static ModuleManagerWrapper^ Wrap(int ID) { return static_cast<ModuleManagerWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ModuleManagerWrapper^ Wrap(ModuleManager* obj) { return static_cast<ModuleManagerWrapper ^>(SimObjectWrapper::Wrap(obj)); };

      ModuleManager* GetObjectPtr(){
         return static_cast<ModuleManager*>(mObject);
      };

      bool setModuleExtension(String^ moduleExtension);
      bool scanModules(String^ moduleRootPath, bool rootOnly);
      bool scanModules(String^ moduleRootPath);
      bool unregisterModule(String^ moduleId, int versionId);
      bool unregisterModule(String^ moduleId);
      bool loadGroup(String^ moduleGroup);
      bool unloadGroup(String^ moduleGroup);
      bool loadExplicit(String^ moduleId, int versionId);
      bool loadExplicit(String^ moduleId);
      bool unloadExplicit(String^ moduleId);
      ModuleDefinitionWrapper^ findModule(String^ moduleId, int versionId);
      array<IJWLayer::ModuleDefinitionWrapper^>^ findModules(bool loadedOnly);
      array<IJWLayer::ModuleDefinitionWrapper^>^ findModules();
      array<IJWLayer::ModuleDefinitionWrapper^>^ findModuleTypes(String^ moduleType, bool loadedOnly);
      array<IJWLayer::ModuleDefinitionWrapper^>^ findModuleTypes(String^ moduleType);
      String^ copyModule(ModuleDefinitionWrapper^ source, String^ targetId, String^ targetPath, bool useVersionPathing);
      bool synchronizeDependencies(ModuleDefinitionWrapper^ root, String^ targetDependencyPath);
      bool isModuleMergeAvailable();
      bool canMergeModules(String^ mergeSourcePath);
      bool mergeModules(String^ mergeTargetPath, bool removeMergeDefinition, bool registerNewModules);
      void addListener(SimObjectWrapper^ listener);
      void removeListener(SimObjectWrapper^ listener);
   };

   public ref class ModuleDefinitionWrapper : SimSetWrapper
   {
   public:
      static ModuleDefinitionWrapper^ Wrap(int ID) { return static_cast<ModuleDefinitionWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ModuleDefinitionWrapper^ Wrap(ModuleDefinition* obj) { return static_cast<ModuleDefinitionWrapper^>(SimObjectWrapper::Wrap(obj)); };

      ModuleDefinition* GetObjectPtr(){
         return static_cast<ModuleDefinition*>(mObject);
      };

      bool save();
      ModuleManagerWrapper^ getModuleManager();
      int getDependencyCount();
      String^ getDependency(int dependencyIndex);
      bool addDependency(String^ moduleId, int versionId);
      bool removeDependency(String^ moduleId);
   };

   public ref class ModuleMergeDefinitionWrapper : SimObjectWrapper
   {

   public:
      static ModuleMergeDefinitionWrapper^ Wrap(int ID) { return static_cast<ModuleMergeDefinitionWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ModuleMergeDefinitionWrapper^ Wrap(ModuleMergeDefinition* obj) { return static_cast<ModuleMergeDefinitionWrapper ^>(SimObjectWrapper::Wrap(obj)); };

      ModuleMergeDefinition* GetObjectPtr(){
         return static_cast<ModuleMergeDefinition*>(mObject);
      };

   };
}
