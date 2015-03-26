// IJWLayer.h

#pragma once

#include "CollectionsWrapper.h"
#include "module/moduleManager.h"
#include "module/moduleMergeDefinition.h"

using namespace System;

namespace IJWLayer {

   public ref class ModuleManagerWrapper : SimObjectWrapper
   {

   public:
      ModuleManagerWrapper(int ID) : SimObjectWrapper(ID){};
      ModuleManagerWrapper(ModuleManager* obj) : SimObjectWrapper(obj){};

      ModuleManager* GetObjectPtr(){
         return static_cast<ModuleManager*>(mObject);
      };

   };

   public ref class ModuleDefinitionWrapper : SimSetWrapper
   {
   public:
      ModuleDefinitionWrapper(int ID) : SimSetWrapper(ID){};
      ModuleDefinitionWrapper(ModuleDefinition* object) : SimSetWrapper(object){};

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
      ModuleMergeDefinitionWrapper(int ID) : SimObjectWrapper(ID){};
      ModuleMergeDefinitionWrapper(ModuleManager* obj) : SimObjectWrapper(obj){};

      ModuleMergeDefinition* GetObjectPtr(){
         return static_cast<ModuleMergeDefinition*>(mObject);
      };

   };
}
