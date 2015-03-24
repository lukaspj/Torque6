// This is the main DLL file.

#include "stdafx.h"

#include "IJWLayer.h"

#include "console/consoleBaseType.h"
#include <vcclr.h>
#include "sim/simObjectTimerEvent.h"
#include "string/stringTable.h"

using namespace System::Runtime::InteropServices;

IJWLayer::SimObjectWrapper::SimObjectWrapper(int ID)
{
   mObject = Sim::findObject(ID);
   mPtr = new SimObjectPtr<SimObject>(mObject);
}

IJWLayer::SimObjectWrapper::~SimObjectWrapper()
{
   if (IsAlive())
      delete mPtr;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Query if this object is alive. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <example>
/// <code>
///          SimObjectWrapper wrapper = new SimObjectWrapper(42);
///          if(wrapper.IsAlive())
///              wrapper.call("foo");
///          </code>
///          </example>
/// 
/// <returns>  true if alive, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::SimObjectWrapper::IsAlive()
{
   return !((SimObjectPtr<SimObject>*)mPtr)->isNull();
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

int IJWLayer::SimObjectWrapper::GetID(String^ mName)
{
   IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(mName);
   char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
   SimObject* object = Sim::findObject(nativeString);
   if (object)
      return object->getId();
   return -1;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets the name of the SimObject. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="mNewName">   The new name. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObjectWrapper::SetName(String^ mNewName)
{
   if (IsAlive())
   {
      IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(mNewName);
      char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
      mObject->assignName(nativeString);
   }
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the name. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the name. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObjectWrapper::GetName()
{
   if (IsAlive())
   {
      const char *ret = mObject->getName();
      return ret ? gcnew String(ret) : "";
   }
   return nullptr;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets class namespace. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the class namespace. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObjectWrapper::getClassNamespace()
{
   if (IsAlive())
      return gcnew String(mObject->getClassNamespace());
   return nullptr;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets super class namespace. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the super class namespace. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObjectWrapper::getSuperClassNamespace()
{
   if (IsAlive())
      return gcnew String(mObject->getSuperClassNamespace());
   return nullptr;
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets class namespace. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="namespc"> The namespc. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObjectWrapper::setClassNamespace(String^ namespc)
{
   if (IsAlive()){
      IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(namespc);
      char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
      mObject->setSuperClassNamespace(nativeString);
   }
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Sets super class namespace. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="namespc"> The namespace. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObjectWrapper::setSuperClassNamespace(String ^namespc)
{
   if (IsAlive()){
      IntPtr ptrToNativeString = Marshal::StringToHGlobalAnsi(namespc);
      char* nativeString = static_cast<char*>(ptrToNativeString.ToPointer());
      mObject->setClassNamespace(nativeString);
   }
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

bool IJWLayer::SimObjectWrapper::isMethod(String ^methodName)
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

String^ IJWLayer::SimObjectWrapper::call(String^ name, ...array<String^> ^args)
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

void IJWLayer::SimObjectWrapper::dumpClassHierarchy()
{
   if (IsAlive())
      mObject->dumpClassHierarchy();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Dumps this object. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObjectWrapper::dump()
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

bool IJWLayer::SimObjectWrapper::isMemberOfClass(String^ className)
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
/// <summary>  Gets class name. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  nullptr if it fails, else the class name. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::SimObjectWrapper::getClassName()
{
   if (!IsAlive())
      return nullptr;
   const char * ret = mObject->getClassName();
   return ret ? gcnew String(ret) : "";
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

String^ IJWLayer::SimObjectWrapper::getFieldValue(String^ fieldName)
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

void IJWLayer::SimObjectWrapper::setFieldValue(String^ fieldName, String^ value)
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

int IJWLayer::SimObjectWrapper::getDynamicFieldCount()
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

String^ IJWLayer::SimObjectWrapper::getDynamicField(int index)
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

int IJWLayer::SimObjectWrapper::getFieldCount()
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

String^ IJWLayer::SimObjectWrapper::getField(int index)
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

void IJWLayer::SimObjectWrapper::setProgenitorFile(String^ file)
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

String^ IJWLayer::SimObjectWrapper::getProgenitorFile()
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

int IJWLayer::SimObjectWrapper::getType()
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

String^ IJWLayer::SimObjectWrapper::getFieldType(String^ fieldName)
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

void IJWLayer::SimObjectWrapper::setInternalName(String^ internalName)
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

String^ IJWLayer::SimObjectWrapper::getInternalName()
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

bool IJWLayer::SimObjectWrapper::isChildOfGroup(int groupID)
{
   if (!IsAlive())
      return false;

   SimGroup* pGroup = dynamic_cast<SimGroup*>(Sim::findObject(groupID));
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

int IJWLayer::SimObjectWrapper::getGroup()
{
   if (!IsAlive())
      return -1;
   SimGroup *grp = mObject->getGroup();
   if (!grp)
      return -1;
   return grp->getId();
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Deletes the object. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::SimObjectWrapper::deleteObject()
{
   if (!IsAlive())
      return;
   SimObject * obj = mObject;
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

int IJWLayer::SimObjectWrapper::clone(bool copyDynamicFields)
{
   if (!IsAlive())
      return -1;

   // Clone Object.
   SimObject* pClonedObject = mObject->clone(copyDynamicFields);

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

bool IJWLayer::SimObjectWrapper::startTimer(String^ callbackFunction, float timePeriod, int repeat)
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

void IJWLayer::SimObjectWrapper::stopTimer()
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

bool IJWLayer::SimObjectWrapper::isTimerActive()
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

int IJWLayer::SimObjectWrapper::schedule(int time, String^ command, ...array<String^> ^args)
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