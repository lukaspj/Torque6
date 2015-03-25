#include "Stdafx.h"
#include "SimSetWrapper.h"
#include "MarshalHelper.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::SimSetWrapper::listObjects()
{
   if (!IsAlive())
      return;

   GetObjectPtr()->lock();
   SimSet::iterator itr;
   for (itr = GetObjectPtr()->begin(); itr != GetObjectPtr()->end(); itr++)
   {
      SimObject *obj = *itr;
      bool isSet = dynamic_cast<SimSet *>(obj) != 0;
      const char *name = obj->getName();
      if (name)
         Con::printf("   %d,\"%s\": %s %s", obj->getId(), name,
         obj->getClassName(), isSet ? "(g)" : "");
      else
         Con::printf("   %d: %s %s", obj->getId(), obj->getClassName(),
         isSet ? "(g)" : "");
   }
   GetObjectPtr()->unlock();
}

void IJWLayer::SimSetWrapper::add(...array<SimObjectWrapper^>^ objects)
{
   if (!IsAlive())
      return;
   for (int ii = 0; ii < objects->Length; ii++)
   {
      if (objects[ii]->IsAlive())
         GetObjectPtr()->addObject(objects[ii]->GetObjectPtr());
      else
         Con::printf("Set::add: Object \"%s\" doesn't exist", "TODO, add object reference");
   }
}

void IJWLayer::SimSetWrapper::remove(...array<SimObjectWrapper^>^ objects)
{
   if (!IsAlive())
      return;
   for (int ii = 0; ii < objects->Length; ii++)
   {
      GetObjectPtr()->lock();
      if (objects[ii]->IsAlive() && GetObjectPtr()->find(GetObjectPtr()->begin(), GetObjectPtr()->end(), objects[ii]->GetObjectPtr()) != GetObjectPtr()->end())
         GetObjectPtr()->removeObject(objects[ii]->GetObjectPtr());
      else
         Con::printf("Set::remove: Object \"%s\" does not exist in set", "TODO, add object reference");
      GetObjectPtr()->unlock();
   }
}

void IJWLayer::SimSetWrapper::deleteObjects()
{
   if (IsAlive())
      GetObjectPtr()->deleteObjects();
}

void IJWLayer::SimSetWrapper::clear()
{
   if (IsAlive())
      GetObjectPtr()->clear();
}

void IJWLayer::SimSetWrapper::callOnChildren(String^ method, ...array<String^>^ args)
{
   if (!IsAlive())
      return;
   const char* _method = (char*)Marshal::StringToHGlobalAnsi(method).ToPointer();

   pin_ptr<const char*> array_pin = &MarshalHelper::MarshalStringArrayToChar(args, 0)[0];
   GetObjectPtr()->callOnChildren(_method, args->Length, array_pin);
}

void IJWLayer::SimSetWrapper::reorderChild(SimObjectWrapper^ obj1, SimObjectWrapper^ obj2)
{
   if (!IsAlive())
      return;
   if (obj1->IsAlive() && obj2->IsAlive())
      GetObjectPtr()->reOrder(obj1->GetObjectPtr(), obj2->GetObjectPtr());
}

int IJWLayer::SimSetWrapper::getCount()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->size();
}

IJWLayer::SimObjectWrapper^ IJWLayer::SimSetWrapper::getObject(int index)
{
   if (!IsAlive())
      return nullptr;
   if (index < 0 || index >= S32(getCount()))
   {
      Con::printf("Set::getObject index out of range.");
      return nullptr;
   }
   return gcnew SimObjectWrapper((*GetObjectPtr())[index]);
}

bool IJWLayer::SimSetWrapper::isMember(SimObjectWrapper^ object)
{
   if (!object->IsAlive())
   {
      Con::printf("SimSet::isMember: %s is not an object.", "TODO: Implement object references");
      return false;
   }

   GetObjectPtr()->lock();
   for (SimSet::iterator i = GetObjectPtr()->begin(); i != GetObjectPtr()->end(); i++)
   {
      if (*i == object->GetObjectPtr())
      {
         GetObjectPtr()->unlock();
         return true;
      }
   }
   GetObjectPtr()->unlock();

   return false;
}

IJWLayer::SimObjectWrapper^ IJWLayer::SimSetWrapper::findObjectByInternalName(String^ name, bool searchChildren)
{
   if (!IsAlive())
      return nullptr;
   const char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();

   StringTableEntry pcName = StringTable->insert(_name);

   SimObject* child = GetObjectPtr()->findObjectByInternalName(pcName, searchChildren);
   if (child)
      return gcnew SimObjectWrapper(child);
   return nullptr;
}
IJWLayer::SimObjectWrapper^ IJWLayer::SimSetWrapper::findObjectByInternalName(String^ name)
{
   return findObjectByInternalName(name, false);
}

void IJWLayer::SimSetWrapper::bringToFront(IJWLayer::SimObjectWrapper^ object)
{
   if (!IsAlive() || !object->IsAlive())
      return;
   GetObjectPtr()->bringObjectToFront(object->GetObjectPtr());
}

void IJWLayer::SimSetWrapper::pushToBack(IJWLayer::SimObjectWrapper^ object)
{
   if (!IsAlive() || !object->IsAlive())
      return;
   GetObjectPtr()->pushObjectToBack(object->GetObjectPtr());
}