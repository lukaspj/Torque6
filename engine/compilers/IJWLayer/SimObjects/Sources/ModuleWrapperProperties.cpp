#include "../../Stdafx.h"
#include "../Headers/ModuleWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::ModuleManager::EnforceDependencies::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getEnforceDependencies();
}

void IJWLayer::ModuleManager::EnforceDependencies::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setEnforceDependencies(value);
}

bool IJWLayer::ModuleManager::EchoInfo::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getEchoInfo();
}

void IJWLayer::ModuleManager::EchoInfo::set(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setEchoInfo(value);
}

String^ IJWLayer::ModuleDefinition::ModuleId::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModuleId());
   return nullptr;
}

void IJWLayer::ModuleDefinition::ModuleId::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setModuleId(_value);
}

int IJWLayer::ModuleDefinition::VersionId::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getVersionId();
}

void IJWLayer::ModuleDefinition::VersionId::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setVersionId(value);
}

int IJWLayer::ModuleDefinition::BuildId::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getBuildId();
}

void IJWLayer::ModuleDefinition::BuildId::set(int value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setBuildId(value);
}

bool IJWLayer::ModuleDefinition::Enabled::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getEnabled();
}

void IJWLayer::ModuleDefinition::Enabled::set(bool value)
{
   if (!IsAlive())
      return
   GetObjectPtr()->setEnabled(value);
}

bool IJWLayer::ModuleDefinition::Synchronized::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getSynchronized();
}

void IJWLayer::ModuleDefinition::Synchronized::set(bool value)
{
   if (!IsAlive())
      return
   GetObjectPtr()->setSynchronized(value);
}

bool IJWLayer::ModuleDefinition::Deprecated::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getDeprecated();
}

void IJWLayer::ModuleDefinition::Deprecated::set(bool value)
{
   if (!IsAlive())
      return
   GetObjectPtr()->setDeprecated(value);
}

bool IJWLayer::ModuleDefinition::CriticalMerge::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getCriticalMerge();
}

void IJWLayer::ModuleDefinition::CriticalMerge::set(bool value)
{
   if (!IsAlive())
      return
   GetObjectPtr()->setCriticalMerge(value);
}

String^ IJWLayer::ModuleDefinition::Description::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModuleDescription());
   return nullptr;
}

void IJWLayer::ModuleDefinition::Description::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setModuleDescription(_value);
}

String^ IJWLayer::ModuleDefinition::Author::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAuthor());
   return nullptr;
}

void IJWLayer::ModuleDefinition::Author::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setAuthor(_value);
}

String^ IJWLayer::ModuleDefinition::Group::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModuleGroup());
   return nullptr;
}

void IJWLayer::ModuleDefinition::Group::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setModuleGroup(_value);
}

String^ IJWLayer::ModuleDefinition::Type::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModuleType());
   return nullptr;
}

void IJWLayer::ModuleDefinition::Type::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setModuleType(_value);
}

String^ IJWLayer::ModuleDefinition::Dependencies::get()
{
   if (IsAlive())
      throw gcnew NotImplementedException("Need to use a typeModuleDependencyVector");
      //return gcnew String(GetObjectPtr()->getDependencies());
   return nullptr;
}

void IJWLayer::ModuleDefinition::Dependencies::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   
   throw gcnew NotImplementedException("Need to use a typeModuleDependencyVector");
   //GetObjectPtr()->setDependencies(_value);
}

String^ IJWLayer::ModuleDefinition::ScriptFile::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getScriptFile());
   return nullptr;
}

void IJWLayer::ModuleDefinition::ScriptFile::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setScriptFile(_value);
}

String^ IJWLayer::ModuleDefinition::CreateFunction::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getCreateFunction());
   return nullptr;
}

void IJWLayer::ModuleDefinition::CreateFunction::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setCreateFunction(_value);
}

String^ IJWLayer::ModuleDefinition::DestroyFunction::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getDestroyFunction());
   return nullptr;
}

void IJWLayer::ModuleDefinition::DestroyFunction::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setDestroyFunction(_value);
}

String^ IJWLayer::ModuleDefinition::AssetTagsManifest::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAssetTagsManifest());
   return nullptr;
}

void IJWLayer::ModuleDefinition::AssetTagsManifest::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setAssetTagsManifest(_value);
}

int IJWLayer::ModuleDefinition::ScopeSet::get()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->getScopeSet();
}

String^ IJWLayer::ModuleDefinition::ModulePath::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModulePath());
   return nullptr;
}

String^ IJWLayer::ModuleDefinition::ModuleFile::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModuleFile());
   return nullptr;
}

String^ IJWLayer::ModuleDefinition::ModuleFilePath::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModuleFilePath());
   return nullptr;
}

String^ IJWLayer::ModuleDefinition::ModuleScriptFilePath::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModuleScriptFilePath());
   return nullptr;
}

String^ IJWLayer::ModuleDefinition::Signature::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getSignature());
   return nullptr;
}

String^ IJWLayer::ModuleMergeDefinition::MergePath::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getModuleMergePath());
   return nullptr;
}

void IJWLayer::ModuleMergeDefinition::MergePath::set(String^ value)
{
   if (!IsAlive())
      return;
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setModuleMergePath(_value);
}