// IJWLayer.h

#pragma once


// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "sim/simObject.h"
#include "sim/simBase.h"
#include "sim/simObjectPtr.h"

// #pragma unmanaged
#pragma managed(pop)

typedef SimObject EngineSimObject;

using System::String;
using System::Exception;

namespace IJWLayer {
   ref class SimGroup;
	public ref class SimObject
   {
   protected:
      void *mPtr;
      EngineSimObject *mObject;
   public:
      SimObject()
      {
         SimObject(new EngineSimObject());
      };
      SimObject(EngineSimObject* object)
      {
         mObject = object;
         mPtr = new SimObjectPtr<EngineSimObject>(mObject);
      }
      ~SimObject();

      bool IsAlive();

      EngineSimObject* GetObjectPtr();

      static SimObject^ Wrap(int ID);
      static SimObject^ Wrap(String^ Name);
      static SimObject^ Wrap(EngineSimObject* obj);
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
      property SimGroup^ ParentGroup{
         void set(SimGroup^ group);
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
