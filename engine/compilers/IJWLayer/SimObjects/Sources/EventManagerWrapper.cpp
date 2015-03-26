#include "../../Stdafx.h"
#include "../Headers/EventManagerWrapper.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::EventManagerWrapper::registerEvent(String^ eventName)
{
   if (!IsAlive())
      return false;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   return GetObjectPtr()->registerEvent(_eventName);
}

void IJWLayer::EventManagerWrapper::unregisterEvent(String^ eventName)
{
   if (!IsAlive())
      return;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   GetObjectPtr()->unregisterEvent(_eventName);
}

bool IJWLayer::EventManagerWrapper::isRegisteredEvent(String^ eventName)
{
   if (!IsAlive())
      return false;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   return GetObjectPtr()->isRegisteredEvent(_eventName);
}

bool IJWLayer::EventManagerWrapper::postEvent(String^ eventName, String^ data)
{
   if (!IsAlive())
      return false;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   char* _data = (char*)Marshal::StringToHGlobalAnsi(data).ToPointer();
   return GetObjectPtr()->postEvent(_eventName, _data);
}

bool IJWLayer::EventManagerWrapper::subscribe(SimObjectWrapper^ listener, String^ eventName, String^ callback)
{
   if (!IsAlive())
      return false;

   if (!listener->IsAlive())
   {
      Con::warnf("EventManager::subscribe - Invalid listener.");
      return false;
   }

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   char* _callback = (char*)Marshal::StringToHGlobalAnsi(callback).ToPointer();
   return GetObjectPtr()->subscribe(listener->GetObjectPtr(), _eventName, _callback);
}


bool IJWLayer::EventManagerWrapper::subscribe(SimObjectWrapper^ listener, String^ eventName)
{
   return subscribe(listener, eventName, "on" + eventName);
}

void IJWLayer::EventManagerWrapper::remove(SimObjectWrapper^ listener, String^ eventName)
{
   if (!IsAlive())
      return;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   GetObjectPtr()->remove(listener->GetObjectPtr(), _eventName);
}

void IJWLayer::EventManagerWrapper::dumpEvents()
{
   if (IsAlive())
      GetObjectPtr()->dumpEvents();
}

void IJWLayer::EventManagerWrapper::dumpSubscribers(String^ eventName)
{
   if (!IsAlive())
      return;
   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   GetObjectPtr()->dumpSubscribers(_eventName);
}

void IJWLayer::EventManagerWrapper::dumpSubscribers()
{
   if (!IsAlive())
      return;
   GetObjectPtr()->dumpSubscribers();
}