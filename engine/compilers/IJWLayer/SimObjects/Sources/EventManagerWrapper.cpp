#include "../../Stdafx.h"
#include "../Headers/EventManagerWrapper.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::EventManager::registerEvent(String^ eventName)
{
   if (!IsAlive())
      return false;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   return GetObjectPtr()->registerEvent(_eventName);
}

void IJWLayer::EventManager::unregisterEvent(String^ eventName)
{
   if (!IsAlive())
      return;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   GetObjectPtr()->unregisterEvent(_eventName);
}

bool IJWLayer::EventManager::isRegisteredEvent(String^ eventName)
{
   if (!IsAlive())
      return false;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   return GetObjectPtr()->isRegisteredEvent(_eventName);
}

bool IJWLayer::EventManager::postEvent(String^ eventName, String^ data)
{
   if (!IsAlive())
      return false;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   char* _data = (char*)Marshal::StringToHGlobalAnsi(data).ToPointer();
   return GetObjectPtr()->postEvent(_eventName, _data);
}

bool IJWLayer::EventManager::subscribe(SimObject^ listener, String^ eventName, String^ callback)
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


bool IJWLayer::EventManager::subscribe(SimObject^ listener, String^ eventName)
{
   return subscribe(listener, eventName, "on" + eventName);
}

void IJWLayer::EventManager::remove(SimObject^ listener, String^ eventName)
{
   if (!IsAlive())
      return;

   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   GetObjectPtr()->remove(listener->GetObjectPtr(), _eventName);
}

void IJWLayer::EventManager::dumpEvents()
{
   if (IsAlive())
      GetObjectPtr()->dumpEvents();
}

void IJWLayer::EventManager::dumpSubscribers(String^ eventName)
{
   if (!IsAlive())
      return;
   char* _eventName = (char*)Marshal::StringToHGlobalAnsi(eventName).ToPointer();
   GetObjectPtr()->dumpSubscribers(_eventName);
}

void IJWLayer::EventManager::dumpSubscribers()
{
   if (!IsAlive())
      return;
   GetObjectPtr()->dumpSubscribers();
}