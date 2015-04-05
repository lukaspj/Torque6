#include "../../Stdafx.h"
#include "../Headers/PersistenceWrapper.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::SimXMLDocument::reset()
{
   if (IsAlive())
      GetObjectPtr()->reset();
}

bool IJWLayer::SimXMLDocument::loadFile(String^ fileName)
{
   if (!IsAlive())
      return false;

   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return GetObjectPtr()->loadFile(_fileName);
}

bool IJWLayer::SimXMLDocument::saveFile(String^ fileName)
{
   if (!IsAlive())
      return false;

   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return GetObjectPtr()->saveFile(_fileName);
}

bool IJWLayer::SimXMLDocument::parse(String^ textXML)
{
   if (!IsAlive())
      return false;

   const char* _textXML = (char*)Marshal::StringToHGlobalAnsi(textXML).ToPointer();
   return GetObjectPtr()->loadFile(_textXML);
}

void IJWLayer::SimXMLDocument::clear()
{
   if (IsAlive())
      GetObjectPtr()->clear();
}

String^ IJWLayer::SimXMLDocument::getErrorDesc()
{
   if (IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->getErrorDesc());
}

void IJWLayer::SimXMLDocument::clearError()
{
   if (IsAlive())
      GetObjectPtr()->clearError();
}

bool IJWLayer::SimXMLDocument::pushFirstChildElement(String^ name)
{
   if (!IsAlive())
      return false;

   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   return GetObjectPtr()->pushFirstChildElement(_name);
}

bool IJWLayer::SimXMLDocument::pushChildElement(int index)
{
   if (!IsAlive())
      return false;

   return GetObjectPtr()->pushChildElement(index);
}

bool IJWLayer::SimXMLDocument::nextSiblingElement(String^ name)
{
   if (!IsAlive())
      return false;

   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   return GetObjectPtr()->nextSiblingElement(_name);
}

String^ IJWLayer::SimXMLDocument::elementValue()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->elementValue());
   return nullptr;
}

void IJWLayer::SimXMLDocument::popElement()
{
   if (IsAlive())
      GetObjectPtr()->popElement();
}

String^ IJWLayer::SimXMLDocument::attribute(String^ attribute)
{
   if (!IsAlive())
      return nullptr;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   return gcnew String(GetObjectPtr()->attribute(_attribute));
}

float IJWLayer::SimXMLDocument::attributeF32(String^ attribute)
{
   if (!IsAlive())
      return -1;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   return dAtof(GetObjectPtr()->attribute(_attribute));
}

int IJWLayer::SimXMLDocument::attributeS32(String^ attribute)
{
   if (!IsAlive())
      return -1;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   return dAtoi(GetObjectPtr()->attribute(_attribute));
}

bool IJWLayer::SimXMLDocument::attributeExists(String^ attribute)
{
   if (!IsAlive())
      return -1;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   return GetObjectPtr()->attributeExists(_attribute);
}

String^ IJWLayer::SimXMLDocument::firstAttribute()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->firstAttribute());
}

String^ IJWLayer::SimXMLDocument::lastAttribute()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->lastAttribute());
}

String^ IJWLayer::SimXMLDocument::nextAttribute()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->nextAttribute());
}

String^ IJWLayer::SimXMLDocument::prevAttribute()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->prevAttribute());
}

void IJWLayer::SimXMLDocument::setAttribute(String^ attribute, String^ attributeValue)
{
   if (!IsAlive())
      return;

   const char* _attribute = (char*)Marshal::StringToHGlobalAnsi(attribute).ToPointer();
   const char* _attributeValue = (char*)Marshal::StringToHGlobalAnsi(attributeValue).ToPointer();
   return GetObjectPtr()->setAttribute(_attribute, _attributeValue);
}

void IJWLayer::SimXMLDocument::setObjectAttributes(String^ attributeValue)
{
   if (!IsAlive())
      return;

   const char* _attributeValue = (char*)Marshal::StringToHGlobalAnsi(attributeValue).ToPointer();
   return GetObjectPtr()->setObjectAttributes(_attributeValue);
}

void IJWLayer::SimXMLDocument::pushNewElement(String^ name)
{
   if (!IsAlive())
      return;

   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   return GetObjectPtr()->pushNewElement(_name);
}

void IJWLayer::SimXMLDocument::addNewElement(String^ name)
{
   if (!IsAlive())
      return;

   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   return GetObjectPtr()->addNewElement(_name);
}

void IJWLayer::SimXMLDocument::addHeader()
{
   if (!IsAlive())
      return;

   return GetObjectPtr()->addHeader();
}

void IJWLayer::SimXMLDocument::addComment(String^ comment)
{
   if (!IsAlive())
      return;

   const char* _comment = (char*)Marshal::StringToHGlobalAnsi(comment).ToPointer();
   GetObjectPtr()->addComment(_comment);
}

String^ IJWLayer::SimXMLDocument::readComment(int index)
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->readComment(index));
}

void IJWLayer::SimXMLDocument::addText(String^ text)
{
   if (!IsAlive())
      return;

   const char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   GetObjectPtr()->addText(_text);
}

String^ IJWLayer::SimXMLDocument::getText()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->getText());
}

void IJWLayer::SimXMLDocument::removeText()
{
   if (IsAlive())
      GetObjectPtr()->removeText();
}

void IJWLayer::SimXMLDocument::addData(String^ text)
{
   if (!IsAlive())
      return;

   const char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   GetObjectPtr()->addData(_text);
}

String^ IJWLayer::SimXMLDocument::getData()
{
   if (!IsAlive())
      return nullptr;

   return gcnew String(GetObjectPtr()->getData());
}

void IJWLayer::Taml::Format::set(String^ value)
{
   if (!IsAlive())
      return;

   const char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();

   // Fetch format mode.
   const EngineTaml::TamlFormatMode formatMode = EngineTaml::getFormatModeEnum(_value);

   // Was the format valid?
   if (formatMode == EngineTaml::InvalidFormat)
   {
      // No, so warn.
      Con::warnf("Taml::setFormat() - Invalid format mode used: '%s'.", _value);
      return;
   }

   // Set format mode.
   GetObjectPtr()->setFormatMode(formatMode);
}

String^ IJWLayer::Taml::Format::get()
{
   if (IsAlive())
      return gcnew String(EngineTaml::getFormatModeDescription(GetObjectPtr()->getFormatMode()));
   return nullptr;
}

void IJWLayer::Taml::AutoFormat::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setAutoFormat(value);
}

bool IJWLayer::Taml::AutoFormat::get()
{
   if (IsAlive())
      return GetObjectPtr()->getAutoFormat();
   return false;
}

void IJWLayer::Taml::WriteDefaults::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setWriteDefaults(value);
}

bool IJWLayer::Taml::WriteDefaults::get()
{
   if (IsAlive())
      return GetObjectPtr()->getWriteDefaults();
   return false;
}

void IJWLayer::Taml::ProgenitorUpdate::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setProgenitorUpdate(value);
}

bool IJWLayer::Taml::ProgenitorUpdate::get()
{
   if (IsAlive())
      return GetObjectPtr()->getProgenitorUpdate();
   return false;
}

void IJWLayer::Taml::AutoFormatXmlExtension::set(String^ value)
{
   if (!IsAlive())
      return;

   const char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setAutoFormatXmlExtension(_value);
}

String^ IJWLayer::Taml::AutoFormatXmlExtension::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAutoFormatXmlExtension());
   return nullptr;
}

void IJWLayer::Taml::AutoFormatBinaryExtension::set(String^ value)
{
   if (!IsAlive())
      return;

   const char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   GetObjectPtr()->setAutoFormatBinaryExtension(_value);
}

String^ IJWLayer::Taml::AutoFormatBinaryExtension::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getAutoFormatBinaryExtension());
   return nullptr;
}

void IJWLayer::Taml::BinaryCompression::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setBinaryCompression(value);
}

bool IJWLayer::Taml::BinaryCompression::get()
{
   if (IsAlive())
      return GetObjectPtr()->getBinaryCompression();
   return false;
}

void IJWLayer::Taml::JSONStrict::set(bool value)
{
   if (IsAlive())
      GetObjectPtr()->setJSONStrict(value);
}

bool IJWLayer::Taml::JSONStrict::get()
{
   if (IsAlive())
      return GetObjectPtr()->getJSONStrict();
   return false;
}

bool IJWLayer::Taml::write(SimObject^ object, String^ filename)
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

IJWLayer::SimObject^ IJWLayer::Taml::read(String^ filename)
{
   if (!IsAlive())
      return nullptr;

   const char* _filename = (char*)Marshal::StringToHGlobalAnsi(filename).ToPointer();

   // Read object.
   EngineSimObject* pSimObject = GetObjectPtr()->read(_filename);

   // Did we find the object?
   if (pSimObject == NULL)
   {
      // No, so warn.
      Con::warnf("Taml::read() - Could not read object from file '%s'.", _filename);
      return nullptr;
   }

   return SimObject::Wrap(pSimObject);
}