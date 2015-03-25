#include "Stdafx.h"
#include "ModuleWrappers.h"
#include "MarshalHelper.h"

using namespace System::Runtime::InteropServices;

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