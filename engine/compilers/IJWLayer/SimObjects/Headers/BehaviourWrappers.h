// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "component/behaviors/behaviorInstance.h"
#include "component/behaviors/behaviorTemplate.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef BehaviorInstance EngineBehaviorInstance;
typedef BehaviorTemplate EngineBehaviorTemplate;

namespace IJWLayer {

   ref class BehaviorTemplate;
   public ref class BehaviorInstance : SimObject
   {
   public:
      static BehaviorInstance^ Wrap(int ID) { return static_cast<BehaviorInstance^>(SimObject::Wrap(ID)); };
      static BehaviorInstance^ Wrap(EngineBehaviorInstance* obj) { return static_cast<BehaviorInstance^>(SimObject::Wrap(obj)); };

      EngineBehaviorInstance* GetObjectPtr(){
         return static_cast<EngineBehaviorInstance*>(mObject);
      };

      property BehaviorTemplate^ Template{
         BehaviorTemplate^ get();
      }
      //TODO should be BehaviorComponent
      property SimObject^ Owner{
         SimObject^ get();
         void set(SimObject^ val);
      }

      String^ getTemplateName();
   };

   public ref class BehaviorTemplate : SimObject
   {
   public:
      static BehaviorTemplate^ Wrap(int ID) { return static_cast<BehaviorTemplate^>(SimObject::Wrap(ID)); };
      static BehaviorTemplate^ Wrap(EngineBehaviorTemplate* obj) { return static_cast<BehaviorTemplate^>(SimObject::Wrap(obj)); };

      EngineBehaviorTemplate* GetObjectPtr(){
         return static_cast<EngineBehaviorTemplate*>(mObject);
      };

      property String^ FriendlyName{
         String^ get();
      }
      property String^ Description{
         String^ get();
      }
      property String^ BehaviorType{
         String^ get();
      }

      BehaviorInstance^ createInstance();
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
