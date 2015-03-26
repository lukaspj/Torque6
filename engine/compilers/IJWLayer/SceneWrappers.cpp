#include "Stdafx.h"
#include "SceneWrappers.h"
#include "MarshalHelper.h"

using namespace System::Runtime::InteropServices;

IJWLayer::SimObjectWrapper^ IJWLayer::SceneEntityWrapper::findComponent(String^ name)
{
   if (!IsAlive())
      return nullptr;
   char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   StringTableEntry sName = StringTable->insert(_name);
   SimObject* result = GetObjectPtr()->findComponent(sName);
   if (result)
      return gcnew SimObjectWrapper(result);

   return nullptr;
}

IJWLayer::SimObjectWrapper^ IJWLayer::SceneEntityWrapper::findComponentByType(String^ name)
{
   if (!IsAlive())
      return nullptr;
   char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   SimObject* result = GetObjectPtr()->findComponentByType(_name);
   if (result)
      return gcnew SimObjectWrapper(result);

   return nullptr;
}

String^ IJWLayer::SceneEntityWrapper::getPosition()
{
   if (!IsAlive())
      return nullptr;
   return gcnew String(Con::getData(TypePoint3F, GetObjectPtr()->mPosition, 0));
}

void IJWLayer::SceneEntityWrapper::setPosition(String^ pos)
{
   if (!IsAlive())
      return;
   const char* _pos = (char*)Marshal::StringToHGlobalAnsi(pos).ToPointer();
   Point3F position;
   Con::setData(TypePoint3F, position, 0, 1, &_pos);

   GetObjectPtr()->mPosition = position;
   GetObjectPtr()->refresh();
}

void IJWLayer::SceneCameraWrapper::lookAt(String^ look_at)
{
   if (!IsAlive())
      return;
   const char* _look_at = (char*)Marshal::StringToHGlobalAnsi(look_at).ToPointer();
   Point3F p3f = Utility::mConvertStringToPoint3F(_look_at);
   GetObjectPtr()->lookAt(p3f);
}

void IJWLayer::SceneCameraWrapper::translate(String^ translation)
{
   if (!IsAlive())
      return;
   const char* _translation = (char*)Marshal::StringToHGlobalAnsi(translation).ToPointer();
   Point3F p3f = Utility::mConvertStringToPoint3F(_translation);
   GetObjectPtr()->lookAt(p3f);
}

void IJWLayer::SceneCameraWrapper::pan(String^ pan)
{
   if (!IsAlive())
      return;
   const char* _pan = (char*)Marshal::StringToHGlobalAnsi(pan).ToPointer();
   Point3F p3f = Utility::mConvertStringToPoint3F(_pan);
   GetObjectPtr()->lookAt(p3f);
}

void IJWLayer::SceneCameraWrapper::setPanVelocity(String^ panVel)
{
   if (!IsAlive())
      return;
   const char* _panVel = (char*)Marshal::StringToHGlobalAnsi(panVel).ToPointer();
   Point3F p3f = Utility::mConvertStringToPoint3F(_panVel);
   GetObjectPtr()->lookAt(p3f);
}

void IJWLayer::SceneCameraWrapper::setPosition(String^ position)
{
   if (!IsAlive())
      return;
   const char* _position = (char*)Marshal::StringToHGlobalAnsi(position).ToPointer();
   Point3F p3f = Utility::mConvertStringToPoint3F(_position);
   GetObjectPtr()->lookAt(p3f);
}

void IJWLayer::SceneCameraWrapper::rotate(String^ rotation)
{
   if (!IsAlive())
      return;
   const char* _rotation = (char*)Marshal::StringToHGlobalAnsi(rotation).ToPointer();
   Point3F p3f = Utility::mConvertStringToPoint3F(_rotation);
   GetObjectPtr()->lookAt(p3f);
}

void IJWLayer::SceneCameraWrapper::bindMouse(bool value, bool left, bool right)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setBindMouse(value, left, right);
}

void IJWLayer::SceneCameraWrapper::bindMouse(bool value, bool left)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setBindMouse(value, left);
}

void IJWLayer::SceneCameraWrapper::bindMouse(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setBindMouse(value);
}