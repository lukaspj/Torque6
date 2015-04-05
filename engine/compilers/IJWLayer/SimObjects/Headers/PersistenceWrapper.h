// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "persistence/tinyXML/tinyxml.h"
#include "persistence/SimXMLDocument.h"
#include "persistence/taml/taml.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef SimXMLDocument EngineSimXMLDocument;
typedef Taml EngineTaml;

namespace IJWLayer {

   public ref class SimXMLDocument : SimObject
   {
   public:
      static SimXMLDocument^ Wrap(int ID) { return static_cast<SimXMLDocument^>(SimObject::Wrap(ID)); };
      static SimXMLDocument^ Wrap(EngineSimXMLDocument* obj) { return static_cast<SimXMLDocument^>(SimObject::Wrap(obj)); };

      EngineSimXMLDocument* GetObjectPtr(){
         return static_cast<EngineSimXMLDocument*>(mObject);
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

   public ref class Taml : SimObject
   {
   public:
      static Taml^ Wrap(int ID) { return static_cast<Taml^>(SimObject::Wrap(ID)); };
      static Taml^ Wrap(EngineTaml* obj) { return static_cast<Taml^>(SimObject::Wrap(obj)); };

      EngineTaml* GetObjectPtr(){
         return static_cast<EngineTaml*>(mObject);
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
      bool write(SimObject^ object, String^ fileName);
      SimObject^ read(String^ filename);
   };
}
