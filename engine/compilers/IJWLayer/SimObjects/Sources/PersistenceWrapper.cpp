#include "../../Stdafx.h"
#include "../Headers/PersistenceWrapper.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::SimXMLDocumentWrapper::reset()
{
   if (IsAlive())
      GetObjectPtr()->reset();
}

bool IJWLayer::SimXMLDocumentWrapper::loadFile(String^ fileName)
{
   if (!IsAlive())
      return false;

   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return GetObjectPtr()->loadFile(_fileName);
}

bool IJWLayer::SimXMLDocumentWrapper::saveFile(String^ fileName)
{
   if (!IsAlive())
      return false;

   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return GetObjectPtr()->saveFile(_fileName);
}

bool IJWLayer::SimXMLDocumentWrapper::parse(String^ textXML)
{
   if (!IsAlive())
      return false;

   const char* _textXML = (char*)Marshal::StringToHGlobalAnsi(textXML).ToPointer();
   return GetObjectPtr()->loadFile(_textXML);
}

void IJWLayer::SimXMLDocumentWrapper::clear()
{
   if (IsAlive())
      GetObjectPtr()->clear();
}

String^ IJWLayer::SimXMLDocumentWrapper::getErrorDesc()
{
   if (IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->getErrorDesc());
}

void IJWLayer::SimXMLDocumentWrapper::clearError()
{
   if (IsAlive())
      GetObjectPtr()->clearError();
}

bool IJWLayer::SimXMLDocumentWrapper::pushFirstChildElement(String^ name)
{
   if (!IsAlive())
      return false;

   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   return GetObjectPtr()->pushFirstChildElement(_name);
}

bool IJWLayer::SimXMLDocumentWrapper::pushChildElement(int index)
{
   if (!IsAlive())
      return false;

   return GetObjectPtr()->pushChildElement(index);
}

bool IJWLayer::SimXMLDocumentWrapper::nextSiblingElement(String^ name)
{
   if (!IsAlive())
      return false;

   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   return GetObjectPtr()->nextSiblingElement(_name);
}

String^ IJWLayer::SimXMLDocumentWrapper::elementValue()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->elementValue());
   return nullptr;
}

void IJWLayer::SimXMLDocumentWrapper::popElement()
{
   if (IsAlive())
      GetObjectPtr()->popElement();
}

String^ IJWLayer::SimXMLDocumentWrapper::attribute(String^ attribute)
{
   if (!IsAlive())
      return nullptr;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   return gcnew String(GetObjectPtr()->attribute(_attribute));
}

float IJWLayer::SimXMLDocumentWrapper::attributeF32(String^ attribute)
{
   if (!IsAlive())
      return -1;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   return dAtof(GetObjectPtr()->attribute(_attribute));
}

int IJWLayer::SimXMLDocumentWrapper::attributeS32(String^ attribute)
{
   if (!IsAlive())
      return -1;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   return dAtoi(GetObjectPtr()->attribute(_attribute));
}

bool IJWLayer::SimXMLDocumentWrapper::attributeExists(String^ attribute)
{
   if (!IsAlive())
      return -1;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   return GetObjectPtr()->attributeExists(_attribute);
}

String^ IJWLayer::SimXMLDocumentWrapper::firstAttribute()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->firstAttribute());
}

String^ IJWLayer::SimXMLDocumentWrapper::lastAttribute()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->lastAttribute());
}

String^ IJWLayer::SimXMLDocumentWrapper::nextAttribute()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->nextAttribute());
}

String^ IJWLayer::SimXMLDocumentWrapper::prevAttribute()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->prevAttribute());
}

void IJWLayer::SimXMLDocumentWrapper::setAttribute(String^ attribute, String^ attributeValue)
{
   if (!IsAlive())
      return;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   const char* _attributeValue = (char*)Marshal::StringToHGlobalAnsi(attributeValue).ToPointer();
   return GetObjectPtr()->setAttribute(_attribute, _attributeValue);
}

void IJWLayer::SimXMLDocumentWrapper::setObjectAttributes(String^ attributeValue)
{
   if (!IsAlive())
      return;

   const char* _attributeValue = (char*)Marshal::StringToHGlobalAnsi(attributeValue).ToPointer();
   return GetObjectPtr()->setObjectAttributes(_attributeValue);
}

void IJWLayer::SimXMLDocumentWrapper::pushNewElement(String^ name)
{
   if (!IsAlive())
      return;

   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   return GetObjectPtr()->pushNewElement(_name);
}

void IJWLayer::SimXMLDocumentWrapper::addNewElement(String^ name)
{
   if (!IsAlive())
      return;

   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   return GetObjectPtr()->addNewElement(_name);
}

void IJWLayer::SimXMLDocumentWrapper::addHeader()
{
   if (!IsAlive())
      return;

   return GetObjectPtr()->addHeader();
}

void IJWLayer::SimXMLDocumentWrapper::addComment(String^ comment)
{
   if (!IsAlive())
      return;

   const char* _comment = (char*)Marshal::StringToHGlobalAnsi(comment).ToPointer();
   GetObjectPtr()->addComment(_comment);
}

String^ IJWLayer::SimXMLDocumentWrapper::readComment(int index)
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->readComment(index));
}

void IJWLayer::SimXMLDocumentWrapper::addText(String^ text)
{
   if (!IsAlive())
      return;

   const char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   GetObjectPtr()->addText(_text);
}

String^ IJWLayer::SimXMLDocumentWrapper::getText()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->getText());
}

void IJWLayer::SimXMLDocumentWrapper::removeText()
{
   if (IsAlive())
      GetObjectPtr()->removeText();
}

void IJWLayer::SimXMLDocumentWrapper::addData(String^ text)
{
   if (!IsAlive())
      return;

   const char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   GetObjectPtr()->addData(_text);
}

String^ IJWLayer::SimXMLDocumentWrapper::getData()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->getData());
}

void IJWLayer::TamlWrapper::Format::set(String^ value)
{
   if (!IsAlive())
      return;

   const char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();

   // Fetch format mode.
   const Taml::TamlFormatMode formatMode = Taml::getFormatModeEnum(_value);

   // Was the format valid?
   if (formatMode == Taml::InvalidFormat)
   {
      // No, so warn.
      Con::warnf("Taml::setFormat() - Invalid format mode used: '%s'.", _value);
      return;
   }

   // Set format mode.
   GetObjectPtr()->setFormatMode(formatMode);
}

String^ IJWLayer::TamlWrapper::Format::get()
{
   if (IsAlive())
      return gcnew String(Taml::getFormatModeDescription(GetObjectPtr()->getFormatMode()));
   return nullptr;
}

void IJWLayer::TamlWrapper::AutoFormat::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setAutoFormat(value);
}

bool IJWLayer::TamlWrapper::AutoFormat::get()
{
   if (IsAlive())
      return GetObjectPtr()->getAutoFormat();
   return false;
}

void IJWLayer::TamlWrapper::WriteDefaults::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setWriteDefaults(value);
}

bool IJWLayer::TamlWrapper::WriteDefaults::get()
{
   if (IsAlive())
      return GetObjectPtr()->getWriteDefaults();
   return false;
}

void IJWLayer::TamlWrapper::ProgenitorUpdate::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setProgenitorUpdate(value);
}

bool IJWLayer::TamlWrapper::ProgenitorUpdate::get()
{
   if (IsAlive())
      return GetObjectPtr()->getProgenitorUpdate();
   return false;
}

void IJWLayer::TamlWrapper::AutoFormatXmlExtension::set(String^ value)
{
   if (!IsAlive())
      return;

   const char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setAutoFormatXmlExtension(_value);
}

String^ IJWLayer::TamlWrapper::AutoFormatXmlExtension::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAutoFormatXmlExtension());
   return nullptr;
}

void IJWLayer::TamlWrapper::AutoFormatBinaryExtension::set(String^ value)
{
   if (!IsAlive())
      return;

   const char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setAutoFormatBinaryExtension(_value);
}

String^ IJWLayer::TamlWrapper::AutoFormatBinaryExtension::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAutoFormatBinaryExtension());
   return nullptr;
}

void IJWLayer::TamlWrapper::BinaryCompression::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setBinaryCompression(value);
}

bool IJWLayer::TamlWrapper::BinaryCompression::get()
{
   if (IsAlive())
      return GetObjectPtr()->getBinaryCompression();
   return false;
}

void IJWLayer::TamlWrapper::JSONStrict::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setJSONStrict(value);
}

bool IJWLayer::TamlWrapper::JSONStrict::get()
{
   if (IsAlive())
      return GetObjectPtr()->getJSONStrict();
   return false;
}

bool IJWLayer::TamlWrapper::write(SimObjectWrapper^ object, String^ filename)
{
   if (!IsAlive())
      return false;
   const char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();

   // Did we find the object?
   if (!object->IsAlive())
   {
      // No, so warn.
      Con::warnf("Taml::write() - Could not find object '%s' to write to file '%s'.", "TODO, implement references", _filename);
      return false;
   }

   return GetObjectPtr()->write(object->GetObjectPtr(), _filename);
}

IJWLayer::SimObjectWrapper^ IJWLayer::TamlWrapper::read(String^ filename)
{
   if (!IsAlive())
      return nullptr;

   const char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();

   // Read object.
   SimObject* pSimObject = GetObjectPtr()->read(_filename);

   // Did we find the object?
   if (pSimObject == NULL)
   {
      // No, so warn.
      Con::warnf("Taml::read() - Could not read object from file '%s'.", _filename);
      return nullptr;
   }

   return SimObjectWrapper::Wrap(pSimObject);
}