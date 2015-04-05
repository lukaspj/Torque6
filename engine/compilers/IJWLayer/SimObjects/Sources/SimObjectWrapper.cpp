// This is the main DLL file.

#include "../../stdafx.h"

#include "../Headers/SimObjectWrapper.h"
#include "../Headers/CollectionsWrapper.h"
#include <vcclr.h>

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/consoleBaseType.h"
#include "sim/simObjectTimerEvent.h"
#include "string/stringTable.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;

IJWLayer::SimObject^ IJWLayer::SimObject::Wrap(int ID)
{
   SimObject^ wrapper = gcnew SimObject();
   wrapper->mObject = Sim::findObject(ID);
   wrapper->mPtr = new SimObjectPtr<EngineSimObject>(wrapper->mObject);
   return wrapper;
}

IJWLayer::SimObject^ IJWLayer::SimObject::Wrap(String^ Name)
{
   SimObject^ wrapper = gcnew SimObject();
   char* _Name = (char*)Marshal::StringToHGlobalAnsi(Name).ToPointer();
   wrapper->mObject = Sim::findObject(_Name);
   wrapper->mPtr = new SimObjectPtr<EngineSimObject>(wrapper->mObject);
   return wrapper;
}

IJWLayer::SimObject^ IJWLayer::SimObject::Wrap(EngineSimObject* object)
{
   SimObject^ wrapper = gcnew SimObject();
   wrapper->mObject = object;
   wrapper->mPtr = new SimObjectPtr<EngineSimObject>(wrapper->mObject);
   return wrapper;
}

IJWLayer::SimObject::~SimObject()
{
   if (IsAlive())
      delete mPtr;
}

bool IJWLayer::SimObject::CanSaveDynamicFields::get()
{
   if (IsAlive())
      return GetObjectPtr()->getCanSaveDynamicFields();
   return false;
}

void IJWLayer::SimObject::CanSaveDynamicFields::set(bool val)
{
   if (IsAlive())
      GetObjectPtr()->setCanSaveDynamicFields(val);
}

String^ IJWLayer::SimObject::InternalName::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getInternalName());
   return nullptr;
}

void IJWLayer::SimObject::InternalName::set(String^ val)
{
   if (!IsAlive())
      return;

   char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setCanSaveDynamicFields(_val);
}

void IJWLayer::SimObject::ParentGroup::set(SimGroup^ val)
{
   if (!IsAlive() || !val->IsAlive())
      return;

   val->add(this);
}

String^ IJWLayer::SimObject::SuperClass::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getSuperClassNamespace());
   return nullptr;
}

void IJWLayer::SimObject::SuperClass::set(String^ val)
{
   if (!IsAlive())
      return;

   char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setSuperClassNamespace(_val);
}

String^ IJWLayer::SimObject::Class::get()
{
   if (IsAlive())
      return gcnew String(GetObjectPtr()->getClassNamespace());
   return nullptr;
}

void IJWLayer::SimObject::Class::set(String^ val)
{
   if (!IsAlive())
      return;

   char* _val = (char*)Marshal::StringToHGlobalAnsi(val).ToPointer();
   GetObjectPtr()->setClassNamespace(_val);
}

String^ IJWLayer::SimObject::Name::get()
{
   if (IsAlive())
   {
      const char *ret = mObject->getName();
      return ret ? gcnew String(ret) : "";
   }
   return nullptr;
}

void IJWLayer::SimObject::Name::set(String^ mNewName)
{
   if (IsAlive())
   {
      IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(mNewName);
      char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
      mObject->assignName(nativeString);
   }
}

int IJWLayer::SimObject::ID::get()
{
   if (IsAlive())
      return mObject->getId();
   return -1;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Query if this object is alive. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <example>
/// <code>
///          SimObject  = new SimObject(42);
///          if(.IsAlive())
///              .call("foo");
///          </code>
///          </example>
/// 
/// <returns>  true if alive, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::SimObject::IsAlive()
{
   return !((SimObjectPtr<EngineSimObject>*)mPtr)->isNull();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets object pointer. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  null if it fails, else the object pointer. </returns>
///-------------------------------------------------------------------------------------------------

SimObject* IJWLayer::SimObject::GetObjectPtr()
{
   return mObject;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Get the unique numeric ID -- or "handle" -- of this object. </summary>
///
/// <remarks>
///   The id is provided for you by the simulator upon object creation.  You can not change it
///   and it likely will not be reused by any other object after this object is deleted.
/// </remarks>
///
/// <param name="mName">   Name of the new. </param>
///
/// <returns>  The identifier. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::SimObject::GetID(String^ mName)
{
   IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(mName);
   char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
   EngineSimObject* object = Sim::findObject(nativeString);
   if (object)
      return object->getId();
   return -1;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Query if 'methodName' is defined. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="methodName"> Name of the method. </param>
///
/// <returns>  true if defined, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::SimObject::isMethod(String ^methodName)
{
   if (IsAlive()){
      IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(methodName);
      char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
      return mObject->isMethod(nativeString);
   }
   return false;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Calls a consolemethod. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="name"> The name of the method. </param>
/// <param name="args"> The arguments. </param>
///
/// <returns>  nullptr if it fails, else a String^. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObject::call(String^ name, ...array<String^> ^args)
{
   if (IsAlive())
   {
      const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();

      array<const char*> ^nativeArray = gcnew array<const char*>(args->Length+2);
      nativeArray[0] = _name;
      nativeArray[1] = _name;
      for (int i = 2; i < args->Length + 2; i++)
      {
         nativeArray[i] = (char*)Marshal::StringToHGlobalAnsi(args[i]).ToPointer();
      }
      pin_ptr<const char*> array_pin = &nativeArray[0];
      const char** nativePtr = array_pin;
      return gcnew String(Con::execute(mObject, args->Length + 2, nativePtr));
   }
   return nullptr;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Dumps the class hierarchy. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObject::dumpClassHierarchy()
{
   if (IsAlive())
      mObject->dumpClassHierarchy();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Dumps this object. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObject::dump()
{
   if (IsAlive())
      mObject->dump();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Query if 'className' is member of class. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="className">  Name of the class. </param>
///
/// <returns>  true if member of class, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::SimObject::isMemberOfClass(String^ className)
{
   if (!IsAlive())
      return false;

   AbstractClassRep* pRep = mObject->getClassRep();
   while (pRep)
   {
      char* _className = (char*)Marshal::StringToHGlobalAnsi(className).ToPointer();
      if (!dStricmp(pRep->getClassName(), _className))
      {
         //matches
         return true;
      }

      pRep = pRep->getParentClass();
   }

   return false;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets field value. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="fieldName">  Name of the field. </param>
///
/// <returns>  nullptr if it fails, else the field value. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObject::getFieldValue(String^ fieldName)
{
   if (!IsAlive())
      return nullptr;
   char* _fieldName = (char*)Marshal::StringToHGlobalAnsi(fieldName).ToPointer();
   const char *fieldTableEntry = StringTable->insert(_fieldName);
   return gcnew String(mObject->getDataField(fieldTableEntry, NULL));
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets field value. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="fieldName">  Name of the field. </param>
/// <param name="value">      The value. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObject::setFieldValue(String^ fieldName, String^ value)
{
   if (!IsAlive())
      return;
   char* _fieldName = (char*)Marshal::StringToHGlobalAnsi(fieldName).ToPointer();
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   mObject->setDataField(_fieldName, NULL, _value);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets dynamic field count. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  The dynamic field count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::SimObject::getDynamicFieldCount()
{
   if (!IsAlive())
      return -1;
   int count = 0;
   SimFieldDictionary *fieldDictionary = mObject->getFieldDictionary();
   for (SimFieldDictionaryIterator itr(fieldDictionary); *itr; ++itr)
      count++;
   return count;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets dynamic field. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="index">   Zero-based index of the. </param>
///
/// <returns>  nullptr if it fails, else the dynamic field. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObject::getDynamicField(int index)
{
   if (!IsAlive())
      return nullptr;
   SimFieldDictionary *fieldDictionary = mObject->getFieldDictionary();
   SimFieldDictionaryIterator itr(fieldDictionary);
   for (S32 i = 0; i < index; i++)
   {
      if (!(*itr))
      {
         Con::warnf("Invalid dynamic field index passed to SimObject::getDynamicField!");
         return nullptr;
      }
      ++itr;
   }

   char* buffer = Con::getReturnBuffer(256);
   if (*itr)
   {
      SimFieldDictionary::Entry* entry = *itr;
      dSprintf(buffer, 256, "%s", entry->slotName);
      return gcnew String(buffer);
   }

   Con::warnf("Invalid dynamic field index passed to SimObject::getDynamicField!");
   return nullptr;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets field count. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  The field count. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::SimObject::getFieldCount()
{
   if (!IsAlive())
      return -1;
   const AbstractClassRep::FieldList &list = mObject->getFieldList();
   const AbstractClassRep::Field* f;
   U32 numDummyEntries = 0;
   for (int i = 0; i < list.size(); i++)
   {
      f = &list[i];

      if (f->type == AbstractClassRep::DepricatedFieldType ||
         f->type == AbstractClassRep::StartGroupFieldType ||
         f->type == AbstractClassRep::EndGroupFieldType)
      {
         numDummyEntries++;
      }
   }

   return list.size() - numDummyEntries;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets a field. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="index">   Zero-based index of the field. </param>
///
/// <returns>  nullptr if it fails, else the field. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObject::getField(int index)
{
   if (!IsAlive())
      return nullptr;
   const AbstractClassRep::FieldList &list = mObject->getFieldList();
   if ((index < 0) || (index >= list.size()))
      return "";

   const AbstractClassRep::Field* f;
   S32 currentField = 0;
   for (int i = 0; i < list.size() && currentField <= index; i++)
   {
      f = &list[i];

      // skip any dummy fields   
      if (f->type == AbstractClassRep::DepricatedFieldType ||
         f->type == AbstractClassRep::StartGroupFieldType ||
         f->type == AbstractClassRep::EndGroupFieldType)
      {
         continue;
      }

      if (currentField == index)
         return gcnew String(f->pFieldname);

      currentField++;
   }

   // if we found nada, return nada.
   return String::Empty;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets progenitor file. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="file"> The file. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObject::setProgenitorFile(String^ file)
{
   if (!IsAlive())
      return;
   char* _file = (char*)Marshal::StringToHGlobalAnsi(file).ToPointer();
   mObject->setProgenitorFile(_file);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets progenitor file. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the progenitor file. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObject::getProgenitorFile()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(mObject->getProgenitorFile());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the typemask. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  The typemask. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::SimObject::getType()
{
   if (!IsAlive())
      return -1;
   return mObject->getType();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets type of field. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="fieldName">  Name of the field. </param>
///
/// <returns>  nullptr if it fails, else the field type. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObject::getFieldType(String^ fieldName)
{
   if (!mObject)
      return nullptr;
   char* _fieldName = (char*)Marshal::StringToHGlobalAnsi(fieldName).ToPointer();
   const char *__fieldName = StringTable->insert(_fieldName);
   U32 typeID = mObject->getDataFieldType(__fieldName, NULL);
   ConsoleBaseType* type = ConsoleBaseType::getType(typeID);

   if (type)
      return gcnew String(type->getTypeClassName());

   return String::Empty;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets internal name. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="internalName">  Name of the internal. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObject::setInternalName(String^ internalName)
{
   if (!IsAlive())
      return;
   char* _internalName = (char*)Marshal::StringToHGlobalAnsi(internalName).ToPointer();
   mObject->setInternalName(_internalName);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets internal name. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the internal name. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObject::getInternalName()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(mObject->getInternalName());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Query if this object is child of group 'groupID'. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="groupID"> Identifier for the group. </param>
///
/// <returns>  true if child of group, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::SimObject::isChildOfGroup(int groupID)
{
   if (!IsAlive())
      return false;

   EngineSimGroup* pGroup = dynamic_cast<EngineSimGroup*>(Sim::findObject(groupID));
   if (pGroup)
   {
      return mObject->isChildOfGroup(pGroup);
   }

   return false;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the group. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  The group. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::SimObject::getGroup()
{
   if (!IsAlive())
      return -1;
   EngineSimGroup *grp = mObject->getGroup();
   if (!grp)
      return -1;
   return grp->getId();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Deletes the object. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObject::deleteObject()
{
   if (!IsAlive())
      return;
   EngineSimObject * obj = mObject;
   obj->deleteObject();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Makes a deep copy of this object. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="copyDynamicFields">   true to copy dynamic fields. </param>
///
/// <returns>  A copy of this object. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::SimObject::clone(bool copyDynamicFields)
{
   if (!IsAlive())
      return -1;

   // Clone Object.
   EngineSimObject* pClonedObject = mObject->clone(copyDynamicFields);

   // Finish if object was not cloned.
   if (pClonedObject == NULL)
      return 0;

   return pClonedObject->getId();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Starts a timer. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="callbackFunction"> The callback function. </param>
/// <param name="timePeriod">       The time period. </param>
/// <param name="repeat">           How many times to repeat (0 for infinite). </param>
///
/// <returns>  true if it succeeds, false if it fails. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::SimObject::startTimer(String^ callbackFunction, float timePeriod, int repeat)
{
   if (!IsAlive())
      return false;
   // Is the periodic timer running?
   if (mObject->getPeriodicTimerID() != 0)
   {
      // Yes, so cancel it.
      Sim::cancelEvent(mObject->getPeriodicTimerID());

      // Reset Timer ID.
      mObject->setPeriodicTimerID(0);
   }

   char* _callbackFunction = (char*)Marshal::StringToHGlobalAnsi(callbackFunction).ToPointer();

   // Fetch the callback function.
   StringTableEntry __callbackFunction = StringTable->insert(_callbackFunction);

   // Does the function exist?
   if (!mObject->isMethod(__callbackFunction))
   {
      // No, so warn.
      Con::warnf("SimObject::startTimer() - The callback function of '%s' does not exist.", callbackFunction);
      return false;
   }

   // Is the time period valid?
   if (timePeriod < 1)
   {
      // No, so warn.
      Con::warnf("SimObject::startTimer() - The time period of '%d' is invalid.", timePeriod);
      return false;
   }

   // Create Timer Event.
   SimObjectTimerEvent* pEvent = new SimObjectTimerEvent(_callbackFunction, (U32)timePeriod, (U32)repeat);

   // Post Event.
   mObject->setPeriodicTimerID(Sim::postEvent(mObject, pEvent, Sim::getCurrentTime() + timePeriod));

   return true;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Stops a timer. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObject::stopTimer()
{
   if (!IsAlive())
      return;
   // Finish if the periodic timer isn't running.
   if (mObject->getPeriodicTimerID() == 0)
      return;

   // Cancel It.
   Sim::cancelEvent(mObject->getPeriodicTimerID());

   // Reset Timer ID.
   mObject->setPeriodicTimerID(0);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Queries if a timer is active. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  true if a timer is active, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::SimObject::isTimerActive()
{
   if (IsAlive())
      return mObject->isPeriodicTimerActive();
   return false;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Schedules a call to a consolemethod. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="time">    The time before the method is called. </param>
/// <param name="command"> The method to call. </param>
/// <param name="args">    The arguments. </param>
///
/// <returns>  The ID of the schedule. </returns>
///-------------------------------------------------------------------------------------------------

int IJWLayer::SimObject::schedule(int time, String^ command, ...array<String^> ^args)
{
   if (!IsAlive())
      return -1;

   const char* _command = (char*)Marshal::StringToHGlobalAnsi(command).ToPointer();

   array<const char*> ^nativeArray = gcnew array<const char*>(args->Length + 2);
   nativeArray[0] = _command;
   nativeArray[1] = mObject->getIdString();
   for (int i = 2; i < args->Length + 2; i++)
   {
      nativeArray[i] = (char*)Marshal::StringToHGlobalAnsi(args[i]).ToPointer();
   }
   pin_ptr<const char*> array_pin = &nativeArray[0];
   const char** nativePtr = array_pin;

   SimConsoleEvent *evt = new SimConsoleEvent(args->Length + 2, nativePtr, true);
   S32 ret = Sim::postEvent(mObject, evt, Sim::getCurrentTime() + time);
   // #ifdef DEBUG
   //    Con::printf("obj %s schedule(%s) = %d", argv[3], argv[2], ret);
   //    Con::executef(1, "backtrace");
   // #endif
   return ret;
}