// IJWLayer.h

#pragma once

#define TINYXML_INCLUDED
#define TORQUE_DEBUG

class TiXmlElement;

#pragma managed(push, off)
#include "sim/simObject.h"
#include "sim/simBase.h"
#include "sim/simObjectPtr.h"
#pragma managed(pop)

using namespace System;

namespace IJWLayer {


	public ref class SimObjectWrapper
	{
   private:
      SimObject *mObject;
      void *mPtr;
   public:
      SimObjectWrapper(int ID);
      ~SimObjectWrapper();

      bool IsAlive();

      static int GetID(String^ mName);
      void SetName(String^ mNewName);
      String^ GetName();
      String^ getClassNamespace();
      String^ getSuperClassNamespace();
      void setClassNamespace(String^ namespc);
      void setSuperClassNamespace(String^ namespc);
      bool isMethod(String^ name);
      String^ call(String^ name, ...array<String^> ^args);
      void dumpClassHierarchy();
      void dump();
      bool isMemberOfClass(String^ className);
      String^ getClassName();
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