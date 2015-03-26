#include "../../Stdafx.h"
#include "../Headers/BehaviourWrappers.h"

using namespace System::Runtime::InteropServices;

String^ IJWLayer::BehaviorInstanceWrapper::getTemplateName()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(GetObjectPtr()->getTemplateName());
}

IJWLayer::BehaviorInstanceWrapper^ IJWLayer::BehaviorTemplateWrapper::createInstance()
{
   if (!IsAlive())
      return nullptr;
   BehaviorInstance* inst = GetObjectPtr()->createInstance();
   return inst ? gcnew BehaviorInstanceWrapper(inst) : nullptr;
}

bool IJWLayer::BehaviorTemplateWrapper::addBehaviorField(String^ fieldName, String^ desc, String^ type, String^ defaultValue, String^ userData)
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

bool IJWLayer::BehaviorTemplateWrapper::addBehaviorField(String^ fieldName, String^ desc, String^ type, String^ defaultValue)
{
   return addBehaviorField(fieldName, desc, type, defaultValue, nullptr);
}

bool IJWLayer::BehaviorTemplateWrapper::addBehaviorField(String^ fieldName, String^ desc, String^ type)
{
   return addBehaviorField(fieldName, desc, type, nullptr, nullptr);
}

int IJWLayer::BehaviorTemplateWrapper::getBehaviorFieldCount()
{
   if (!IsAlive())
      return -1;

   return GetObjectPtr()->getBehaviorFieldCount();
}

String^ IJWLayer::BehaviorTemplateWrapper::getBehaviorField(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   BehaviorTemplate::BehaviorField* pField = GetObjectPtr()->getBehaviorField(fieldIndex);

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

String^ IJWLayer::BehaviorTemplateWrapper::getBehaviorFieldUserData(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   BehaviorTemplate::BehaviorField* pField = GetObjectPtr()->getBehaviorField(fieldIndex);

   // Was the field found?
   if (!pField)
   {
      // No, so warn.
      Con::warnf("getBehaviorFieldUserData() - Could not find the behavior field '%i' on behavior '%s'", fieldIndex, GetObjectPtr()->getFriendlyName());
      return nullptr;
   }

   return gcnew String(pField->mUserData);
}

String^ IJWLayer::BehaviorTemplateWrapper::getBehaviorFieldDescription(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   BehaviorTemplate::BehaviorField* pField = GetObjectPtr()->getBehaviorField(fieldIndex);

   // Was the field found?
   if (!pField)
   {
      // No, so warn.
      Con::warnf("getBehaviorFieldDescription() - Could not find the behavior field '%i' on behavior '%s'", fieldIndex, GetObjectPtr()->getFriendlyName());
      return nullptr;
   }

   return gcnew String(pField->mDescription);
}

bool IJWLayer::BehaviorTemplateWrapper::addBehaviorOutput(String^ outputName, String^ label, String^ description)
{
   if (!IsAlive())
      return false;
   const char* _outputName = (char*)Marshal::StringToHGlobalAnsi(outputName).ToPointer();
   const char* _label = (char*)Marshal::StringToHGlobalAnsi(label).ToPointer();
   const char* _description = (char*)Marshal::StringToHGlobalAnsi(description).ToPointer();

   return GetObjectPtr()->addBehaviorInput(_outputName, _label, _description);
}

int IJWLayer::BehaviorTemplateWrapper::getBehaviorOutputCount()
{
   if (!IsAlive())
      return -1;

   return GetObjectPtr()->getBehaviorOutputCount();
}

String^ IJWLayer::BehaviorTemplateWrapper::getBehaviorOutput(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   BehaviorTemplate::BehaviorPortOutput* pPortOutput = GetObjectPtr()->getBehaviourOutput(fieldIndex);

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

bool IJWLayer::BehaviorTemplateWrapper::hasBehaviorOutput(String^ outputName)
{
   if (!IsAlive())
      return false;

   const char* _outputName = (char*)Marshal::StringToHGlobalAnsi(outputName).ToPointer();
   return GetObjectPtr()->hasBehaviorOutput(_outputName);
}

bool IJWLayer::BehaviorTemplateWrapper::addBehaviorInput(String^ inputName, String^ label, String^ description)
{
   if (!IsAlive())
      return false;
   const char* _inputName = (char*)Marshal::StringToHGlobalAnsi(inputName).ToPointer();
   const char* _label = (char*)Marshal::StringToHGlobalAnsi(label).ToPointer();
   const char* _description = (char*)Marshal::StringToHGlobalAnsi(description).ToPointer();

   return GetObjectPtr()->addBehaviorInput(_inputName, _label, _description);
}

int IJWLayer::BehaviorTemplateWrapper::getBehaviorInputCount()
{
   if (!IsAlive())
      return -1;

   return GetObjectPtr()->getBehaviorInputCount();
}

String^ IJWLayer::BehaviorTemplateWrapper::getBehaviorInput(int fieldIndex)
{
   if (!IsAlive())
      return nullptr;

   // Fetch behavior field.
   BehaviorTemplate::BehaviorPortInput* pPortInput = GetObjectPtr()->getBehaviourInput(fieldIndex);

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

bool IJWLayer::BehaviorTemplateWrapper::hasBehaviorInput(String^ inputName)
{
   if (!IsAlive())
      return false;

   const char* _inputName = (char*)Marshal::StringToHGlobalAnsi(inputName).ToPointer();
   return GetObjectPtr()->hasBehaviorInput(_inputName);
}