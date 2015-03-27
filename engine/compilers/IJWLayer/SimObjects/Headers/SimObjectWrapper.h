// IJWLayer.h

#pragma once

#define TINYXML_INCLUDED

class TiXmlElement;

#pragma managed(push, off)
#include "sim/simObject.h"
#include "sim/simBase.h"
#include "sim/simObjectPtr.h"
#pragma managed(pop)

using System::String;

namespace IJWLayer {
   ref class SimGroupWrapper;
	public ref class SimObjectWrapper
   {
   protected:
      void *mPtr;
      SimObject *mObject;
   public:
      SimObjectWrapper() 
      {
         SimObjectWrapper(new SimObject());
      };
      SimObjectWrapper(SimObject* object)
      {
         mObject = object;
         mPtr = new SimObjectPtr<SimObject>(mObject);
      }
      ~SimObjectWrapper();

      bool IsAlive();

      SimObject* GetObjectPtr();

      static SimObjectWrapper^ Wrap(int ID);
      static SimObjectWrapper^ Wrap(SimObject* obj);
      bool registerObject() { return mObject->registerObject(); };

      // --

      property bool CanSaveDynamicFields{
         bool get();
         void set(bool value);
      }
      property String^ InternalName{
         String^ get();
         void set(String^ newName);
      }
      property SimGroupWrapper^ ParentGroup{
         void set(SimGroupWrapper^ group);
      }
      property String^ SuperClass{
         String^ get();
         void set(String^ value);
      }
      property String^ Class{
         String^ get();
         void set(String^ value);
      }
      property String^ Name{
         String^ get();
         void set(String^ value);
      }
      property int ID{
         int get();
      }

      static int GetID(String^ mName);
      bool isMethod(String^ name);
      String^ call(String^ name, ...array<String^> ^args);
      void dumpClassHierarchy();
      void dump();
      bool isMemberOfClass(String^ className);
      String^ getFieldValue(String^ fieldName);
      void setFieldValue(String^ fieldName, String^ value);
      int getDynamicFieldCount();
      String^ getDynamicField(int index);
      int getFieldCount();
      String^ getField(int index);
      void setProgenitorFile(String^ file);
      String^ getProgenitorFile();
      int getType();
      String^ getFieldType(String^ fieldName);
      void setInternalName(String^ internalName);
      String^ getInternalName();
      bool isChildOfGroup(int groupID);
      int getGroup();
      void deleteObject();
      int clone(bool copyDynamicFields);
      int clone() { return clone(false); };
      bool startTimer(String^ callbackFunction, float timePeriod, int repeat);
      bool startTimer(String^ callbackFunction, float timePeriod) {
         return startTimer(callbackFunction, timePeriod, 0);
      };
      void stopTimer();
      bool isTimerActive();
      int schedule(int time, String^ command, ...array<String^> ^args);
	};
}
