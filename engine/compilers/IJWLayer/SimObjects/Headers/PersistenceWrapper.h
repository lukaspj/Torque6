// IJWLayer.h

#pragma once

#include "persistence/tinyXML/tinyxml.h"
#include "SimObjectWrapper.h"
#include "persistence/SimXMLDocument.h"
#include "persistence/taml/taml.h"

using namespace System;

namespace IJWLayer {

   public ref class SimXMLDocumentWrapper : SimObjectWrapper
   {
   public:
      static SimXMLDocumentWrapper^ Wrap(int ID) { return static_cast<SimXMLDocumentWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static SimXMLDocumentWrapper^ Wrap(SimXMLDocument* obj) { return static_cast<SimXMLDocumentWrapper^>(SimObjectWrapper::Wrap(obj)); };

      SimXMLDocument* GetObjectPtr(){
         return static_cast<SimXMLDocument*>(mObject);
      };

      void reset();
      bool loadFile(String^ fileName);
      bool saveFile(String^ fileName);
      bool parse(String^ textXML);
      void clear();
      String^ getErrorDesc();
      void clearError();
      bool pushFirstChildElement(String^ name);
      bool pushChildElement(int index);
      bool nextSiblingElement(String^ name);
      String^ elementValue();
      void popElement();
      String^ attribute(String^ attributeName);
      float attributeF32(String^ attributeName);
      int attributeS32(String^ attributeName);
      bool attributeExists(String^ attributeName);
      String^ firstAttribute();
      String^ lastAttribute();
      String^ nextAttribute();
      String^ prevAttribute();
      void setAttribute(String^ attributeName, String^ attributeValue);
      void setObjectAttributes(String^ attributeValue);
      void pushNewElement(String^ name);
      void addNewElement(String^ name);
      void addHeader();
      void addComment(String^ name);
      String^ readComment(int index);
      void addText(String^ text);
      String^ getText();
      void removeText();
      void addData(String^ text);
      String^ getData();
   };

   public ref class TamlWrapper : SimObjectWrapper
   {
   public:
      static TamlWrapper^ Wrap(int ID) { return static_cast<TamlWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static TamlWrapper^ Wrap(Taml* obj) { return static_cast<TamlWrapper^>(SimObjectWrapper::Wrap(obj)); };

      Taml* GetObjectPtr(){
         return static_cast<Taml*>(mObject);
      };

      property String^ Format{
         String^ get();
         void set(String^ value);
      }
      property bool AutoFormat{
         bool get();
         void set(bool value);
      }
      property bool WriteDefaults{
         bool get();
         void set(bool value);
      }
      property bool ProgenitorUpdate{
         bool get();
         void set(bool value);
      }
      property String^ AutoFormatXmlExtension{
         String^ get();
         void set(String^ value);
      }
      property String^ AutoFormatBinaryExtension{
         String^ get();
         void set(String^ value);
      }
      property bool BinaryCompression{
         bool get();
         void set(bool value);
      }
      property bool JSONStrict{
         bool get();
         void set(bool value);
      }
      bool write(SimObjectWrapper^ object, String^ fileName);
      SimObjectWrapper^ read(String^ filename);
   };
}
