// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "component/behaviors/behaviorInstance.h"
#include "component/behaviors/behaviorTemplate.h"

using namespace System;

namespace IJWLayer {

   public ref class BehaviorInstanceWrapper : SimObjectWrapper
   {
   public:
      static BehaviorInstanceWrapper^ Wrap(int ID) { return static_cast<BehaviorInstanceWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static BehaviorInstanceWrapper^ Wrap(BehaviorInstance* obj) { return static_cast<BehaviorInstanceWrapper^>(SimObjectWrapper::Wrap(obj)); };

      BehaviorInstance* GetObjectPtr(){
         return static_cast<BehaviorInstance*>(mObject);
      };

      String^ getTemplateName();
   };

   public ref class BehaviorTemplateWrapper : SimObjectWrapper
   {
   public:
      static BehaviorTemplateWrapper^ Wrap(int ID) { return static_cast<BehaviorTemplateWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static BehaviorTemplateWrapper^ Wrap(BehaviorTemplate* obj) { return static_cast<BehaviorTemplateWrapper^>(SimObjectWrapper::Wrap(obj)); };

      BehaviorTemplate* GetObjectPtr(){
         return static_cast<BehaviorTemplate*>(mObject);
      };

      BehaviorInstanceWrapper^ createInstance();
      bool addBehaviorField(String^ fieldName, String^ desc, String^ type, String^ defaultValue, String^ userData);
      bool addBehaviorField(String^ fieldName, String^ desc, String^ type, String^ defaultValue);
      bool addBehaviorField(String^ fieldName, String^ desc, String^ type);
      int getBehaviorFieldCount();
      String^ getBehaviorField(int fieldIndex);
      String^ getBehaviorFieldUserData(int fieldIndex);
      String^ getBehaviorFieldDescription(int fieldIndex);

      bool addBehaviorOutput(String^ outputName, String^ label, String^ description);
      int getBehaviorOutputCount();
      String^ getBehaviorOutput(int outputIndex);
      bool hasBehaviorOutput(String^ outputName);

      bool addBehaviorInput(String^ inputName, String^ label, String^ description);
      int getBehaviorInputCount();
      String^ getBehaviorInput(int inputIndex);
      bool hasBehaviorInput(String^ inputName);
   };
}
