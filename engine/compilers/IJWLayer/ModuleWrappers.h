// IJWLayer.h

#pragma once

#include "SimSetWrapper.h"
#include "module/moduleManager.h"

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
}
