// IJWLayer.h

#pragma once

#include "CollectionsWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "module/moduleManager.h"
#include "module/moduleMergeDefinition.h"

// #pragma unmanaged
#pragma managed(pop)


using namespace System;

typedef ModuleManager EngineModuleManager;
typedef ModuleDefinition EngineModuleDefinition;
typedef ModuleMergeDefinition EngineModuleMergeDefinition;

namespace IJWLayer {

   ref class ModuleDefinition;
   public ref class ModuleManager : SimObject
   {

   public:
      static ModuleManager^ Wrap(int ID) { return static_cast<ModuleManager^>(SimObject::Wrap(ID)); };
      static ModuleManager^ Wrap(String^ Name) { return static_cast<ModuleManager^>(SimObject::Wrap(Name)); };
      static ModuleManager^ Wrap(EngineModuleManager* obj) { return static_cast<ModuleManager ^>(SimObject::Wrap(obj)); };

      EngineModuleManager* GetObjectPtr(){
         return static_cast<EngineModuleManager*>(mObject);
      };

      property bool EnforceDependencies{
         bool get();
         void set(bool value);
      }

      property bool EchoInfo{
         bool get();
         void set(bool value);
      }

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
      ModuleDefinition^ findModule(String^ moduleId, int versionId);
      array<IJWLayer::ModuleDefinition^>^ findModules(bool loadedOnly);
      array<IJWLayer::ModuleDefinition^>^ findModules();
      array<IJWLayer::ModuleDefinition^>^ findModuleTypes(String^ moduleType, bool loadedOnly);
      array<IJWLayer::ModuleDefinition^>^ findModuleTypes(String^ moduleType);
      String^ copyModule(ModuleDefinition^ source, String^ targetId, String^ targetPath, bool useVersionPathing);
      bool synchronizeDependencies(ModuleDefinition^ root, String^ targetDependencyPath);
      bool isModuleMergeAvailable();
      bool canMergeModules(String^ mergeSourcePath);
      bool mergeModules(String^ mergeTargetPath, bool removeMergeDefinition, bool registerNewModules);
      void addListener(SimObject^ listener);
      void removeListener(SimObject^ listener);
   };

   public ref class ModuleDefinition : SimSet
   {
   public:
      static ModuleDefinition^ Wrap(int ID) { return static_cast<ModuleDefinition^>(SimObject::Wrap(ID)); };
      static ModuleDefinition^ Wrap(String^ Name) { return static_cast<ModuleDefinition^>(SimObject::Wrap(Name)); };
      static ModuleDefinition^ Wrap(EngineModuleDefinition* obj) { return static_cast<ModuleDefinition^>(SimObject::Wrap(obj)); };

      EngineModuleDefinition* GetObjectPtr(){
         return static_cast<EngineModuleDefinition*>(mObject);
      };

      property String^ ModuleId{
         String^ get();
         void set(String^ value);
      }
      property int VersionId{
         int get();
         void set(int value);
      }
      property int BuildId{
         int get();
         void set(int value);
      }
      property bool Enabled{
         bool get();
         void set(bool value);
      }
      property bool Synchronized{
         bool get();
         void set(bool value);
      }
      property bool Deprecated{
         bool get();
         void set(bool value);
      }
      property bool CriticalMerge{
         bool get();
         void set(bool value);
      }
      property String^ Description{
         String^ get();
         void set(String^ value);
      }
      property String^ Author{
         String^ get();
         void set(String^ value);
      }
      property String^ Group{
         String^ get();
         void set(String^ value);
      }
      property String^ Type{
         String^ get();
         void set(String^ value);
      }
      property String^ Dependencies{
         String^ get();
         void set(String^ value);
      }
      property String^ ScriptFile{
         String^ get();
         void set(String^ value);
      }
      property String^ CreateFunction{
         String^ get();
         void set(String^ value);
      }
      property String^ DestroyFunction{
         String^ get();
         void set(String^ value);
      }
      property String^ AssetTagsManifest{
         String^ get();
         void set(String^ value);
      }
      property int ScopeSet{
         int get();
      }
      property String^ ModulePath{
         String^ get();
      }
      property String^ ModuleFile{
         String^ get();
      }
      property String^ ModuleFilePath{
         String^ get();
      }
      property String^ ModuleScriptFilePath{
         String^ get();
      }
      property String^ Signature{
         String^ get();
      }

      bool save();
      ModuleManager^ getModuleManager();
      int getDependencyCount();
      String^ getDependency(int dependencyIndex);
      bool addDependency(String^ moduleId, int versionId);
      bool removeDependency(String^ moduleId);
   };

   public ref class ModuleMergeDefinition : SimObject
   {

   public:
      static ModuleMergeDefinition^ Wrap(int ID) { return static_cast<ModuleMergeDefinition^>(SimObject::Wrap(ID)); };
      static ModuleMergeDefinition^ Wrap(String^ Name) { return static_cast<ModuleMergeDefinition^>(SimObject::Wrap(Name)); };
      static ModuleMergeDefinition^ Wrap(EngineModuleMergeDefinition* obj) { return static_cast<ModuleMergeDefinition ^>(SimObject::Wrap(obj)); };

      EngineModuleMergeDefinition* GetObjectPtr(){
         return static_cast<EngineModuleMergeDefinition*>(mObject);
      };

      property String^ MergePath{
         String^ get();
         void set(String^ value);
      }
   };
}
