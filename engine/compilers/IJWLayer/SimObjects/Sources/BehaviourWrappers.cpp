#include "../../Stdafx.h"
#include "../Headers/BehaviourWrappers.h"

using namespace System::Runtime::InteropServices;

IJWLayer::BehaviorTemplate^ IJWLayer::BehaviorInstance::Template::get()
{
   if (IsAlive())
      return BehaviorTemplate::Wrap(GetObjectPtr()->getTemplate());
   return nullptr;
}

IJWLayer::SimObject^ IJWLayer::BehaviorInstance::Owner::get()
{
   // TODO should be BehaviorComponent
   if (IsAlive())
      return SimObject::Wrap((EngineSimObject*)GetObjectPtr()->getBehaviorOwner());
}

void IJWLayer::BehaviorInstance::Owner::set(IJWLayer::SimObject^ val)
{
   // TODO should be BehaviorComponent
   if (IsAlive() && val->IsAlive())
      GetObjectPtr()->setBehaviorOwner((BehaviorComponent*)val->GetObjectPtr());
}

String^ IJWLayer::BehaviorInstance::getTemplateName()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->getTemplateName());
}

IJWLayer::BehaviorInstance^ IJWLayer::BehaviorTemplate::createInstance()
{
   if (!IsAlive())
      return nullptr;
   EngineBehaviorInstance* inst = GetObjectPtr()->createInstance();
   return inst ? BehaviorInstance::Wrap(inst) : nullptr;
}

String^ IJWLayer::BehaviorTemplate::FriendlyName::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getFriendlyName());
   return nullptr;
}

String^ IJWLayer::BehaviorTemplate::Description::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getDescription());
   return nullptr;
}

String^ IJWLayer::BehaviorTemplate::BehaviorType::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getBehaviorType());
   return nullptr;
}

bool IJWLayer::BehaviorTemplate::addBehaviorField(String^ fieldName, String^ desc, String^ type, String^ defaultValue, String^ userData)
{
   if (!IsAlive())
      return false;

   const char* _fieldName = (char*)Marshal::StringToHGlobalAnsi(fieldName).ToPointer();
   const char* _desc = (char*)Marshal::StringToHGlobalAnsi(desc).ToPointer();
   const char* _type = (char*)Marshal::StringToHGlobalAnsi(type).ToPointer();
   const char* _defaultValue = (char*)Marshal::StringToHGlobalAnsi(defaultValue).ToPointer();
   const char* _userData = (char*)Marshal::StringToHGlobalAnsi(userData).ToPointer();
   return GetObjectPtr()->addBehaviorField(_fieldName, _desc, _type, _defaultValue, _userData);
}

bool IJWLayer::BehaviorTemplate::addBehaviorField(String^ fieldName, String^ desc, String^ type, String^ defaultValue)
{
   return addBehaviorField(fieldName, desc, type, defaultValue, nullptr);
}

bool IJWLayer::BehaviorTemplate::addBehaviorField(String^ fieldName, String^ desc, String^ type)
{
   return addBehaviorField(fieldName, desc, type, nullptr, nullptr);
}

int IJWLayer::BehaviorTemplate::getBehaviorFieldCount()
{
   if (!IsAlive())
      return -1;

   return GetObjectPtr()->getBehaviorFieldCount();
}

String^ IJWLayer::BehaviorTemplate::getBehaviorField(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   EngineBehaviorTemplate::BehaviorField* pField = GetObjectPtr()->getBehaviorField(fieldIndex);

   // Was the field found?
   if (!pField)
   {
      // No, so warn.
      Con::warnf("getBehaviorField() - Could not find the behavior field '%i' on behavior '%s'", fieldIndex, GetObjectPtr()->getFriendlyName());
      return nullptr;
   }

   // Format and return behavior field.
   char* pBuffer = Con::getReturnBuffer(1024);
   dSprintf(pBuffer, 1024, "%s\t%s\t%s", pField->mName, pField->mType, pField->mDefaultValue);
   return gcnew String(pBuffer);
}

String^ IJWLayer::BehaviorTemplate::getBehaviorFieldUserData(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   EngineBehaviorTemplate::BehaviorField* pField = GetObjectPtr()->getBehaviorField(fieldIndex);

   // Was the field found?
   if (!pField)
   {
      // No, so warn.
      Con::warnf("getBehaviorFieldUserData() - Could not find the behavior field '%i' on behavior '%s'", fieldIndex, GetObjectPtr()->getFriendlyName());
      return nullptr;
   }

   return gcnew String(pField->mUserData);
}

String^ IJWLayer::BehaviorTemplate::getBehaviorFieldDescription(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   EngineBehaviorTemplate::BehaviorField* pField = GetObjectPtr()->getBehaviorField(fieldIndex);

   // Was the field found?
   if (!pField)
   {
      // No, so warn.
      Con::warnf("getBehaviorFieldDescription() - Could not find the behavior field '%i' on behavior '%s'", fieldIndex, GetObjectPtr()->getFriendlyName());
      return nullptr;
   }

   return gcnew String(pField->mDescription);
}

bool IJWLayer::BehaviorTemplate::addBehaviorOutput(String^ outputName, String^ label, String^ description)
{
   if (!IsAlive())
      return false;
   const char* _outputName = (char*)Marshal::StringToHGlobalAnsi(outputName).ToPointer();
   const char* _label = (char*)Marshal::StringToHGlobalAnsi(label).ToPointer();
   const char* _description = (char*)Marshal::StringToHGlobalAnsi(description).ToPointer();

   return GetObjectPtr()->addBehaviorInput(_outputName, _label, _description);
}

int IJWLayer::BehaviorTemplate::getBehaviorOutputCount()
{
   if (!IsAlive())
      return -1;

   return GetObjectPtr()->getBehaviorOutputCount();
}

String^ IJWLayer::BehaviorTemplate::getBehaviorOutput(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   EngineBehaviorTemplate::BehaviorPortOutput* pPortOutput = GetObjectPtr()->getBehaviourOutput(fieldIndex);

   // Was the field found?
   if (!pPortOutput)
   {
      // No, so warn.
      Con::warnf("getBehaviorField() - Could not find the behavior output '%i' on behavior '%s'", fieldIndex, GetObjectPtr()->getFriendlyName());
      return nullptr;
   }

   // Format and return behavior field.
   char* pBuffer = Con::getReturnBuffer(1024);
   dSprintf(pBuffer, 1024, "%s\t%s\t%s", pPortOutput->mName, pPortOutput->mLabel, pPortOutput->mDescription);
   return gcnew String(pBuffer);
}

bool IJWLayer::BehaviorTemplate::hasBehaviorOutput(String^ outputName)
{
   if (!IsAlive())
      return false;

   const char* _outputName = (char*)Marshal::StringToHGlobalAnsi(outputName).ToPointer();
   return GetObjectPtr()->hasBehaviorOutput(_outputName);
}

bool IJWLayer::BehaviorTemplate::addBehaviorInput(String^ inputName, String^ label, String^ description)
{
   if (!IsAlive())
      return false;
   const char* _inputName = (char*)Marshal::StringToHGlobalAnsi(inputName).ToPointer();
   const char* _label = (char*)Marshal::StringToHGlobalAnsi(label).ToPointer();
   const char* _description = (char*)Marshal::StringToHGlobalAnsi(description).ToPointer();

   return GetObjectPtr()->addBehaviorInput(_inputName, _label, _description);
}

int IJWLayer::BehaviorTemplate::getBehaviorInputCount()
{
   if (!IsAlive())
      return -1;

   return GetObjectPtr()->getBehaviorInputCount();
}

String^ IJWLayer::BehaviorTemplate::getBehaviorInput(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   EngineBehaviorTemplate::BehaviorPortInput* pPortInput = GetObjectPtr()->getBehaviourInput(fieldIndex);

   // Was the field found?
   if (!pPortInput)
   {
      // No, so warn.
      Con::warnf("getBehaviorOutput() - Could not find the behavior input '%i' on behavior '%s'", fieldIndex, GetObjectPtr()->getFriendlyName());
      return nullptr;
   }

   // Format and return behavior field.
   char* pBuffer = Con::getReturnBuffer(1024);
   dSprintf(pBuffer, 1024, "%s\t%s\t%s", pPortInput->mName, pPortInput->mLabel, pPortInput->mDescription);
   return gcnew String(pBuffer);
}

bool IJWLayer::BehaviorTemplate::hasBehaviorInput(String^ inputName)
{
   if (!IsAlive())
      return false;

   const char* _inputName = (char*)Marshal::StringToHGlobalAnsi(inputName).ToPointer();
   return GetObjectPtr()->hasBehaviorInput(_inputName);
}