#include "../../Stdafx.h"
#include "../Headers/SceneWrappers.h"
#include "../Headers/MarshalHelper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "2d/core/Utility.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System::Runtime::InteropServices;

void IJWLayer::SceneEntity::Template::set(String^ templatePath)
{
   if (!IsAlive())
      return;

   char* _templatePath = (char*)Marshal::StringToHGlobalAnsi(templatePath).ToPointer();
   GetObjectPtr()->setTemplate(_templatePath);
}

void IJWLayer::SceneEntity::Position::set(Point3F^ position)
{
   Con::printf("Trying to set entity position to: %f %f %f", position->x, position->y, position->z);
   if (!IsAlive())
      return;
   Con::printf("Object is alive.");
   GetObjectPtr()->mPosition = position->ToEngine();
   GetObjectPtr()->refresh();
}

IJWLayer::Point3F^ IJWLayer::SceneEntity::Position::get()
{
   if (!IsAlive())
      return nullptr;

   return Point3F::FromEngine(GetObjectPtr()->mPosition);
}

void IJWLayer::SceneEntity::Rotation::set(EulerF^ rotation)
{
   if (!IsAlive())
      return;

   GetObjectPtr()->mRotation = rotation->ToEngine();
}

IJWLayer::EulerF^ IJWLayer::SceneEntity::Rotation::get()
{
   if (!IsAlive())
      return nullptr;

   return EulerF::FromEngine(GetObjectPtr()->mRotation);
}

void IJWLayer::SceneEntity::Scale::set(VectorF^ scale)
{
   if (!IsAlive())
      return;

   GetObjectPtr()->mScale = scale->ToEngine();
}

IJWLayer::VectorF^ IJWLayer::SceneEntity::Scale::get()
{
   if (!IsAlive())
      return nullptr;

   return VectorF::FromEngine(GetObjectPtr()->mScale);
}

IJWLayer::SimObject^ IJWLayer::SceneEntity::findComponent(String^ name)
{
   if (!IsAlive())
      return nullptr;
   char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   StringTableEntry sName = StringTable->insert(_name);
   EngineSimObject* result = GetObjectPtr()->findComponent(sName);
   if (result)
      return SimObject::Wrap(result);

   return nullptr;
}

IJWLayer::SimObject^ IJWLayer::SceneEntity::findComponentByType(String^ name)
{
   if (!IsAlive())
      return nullptr;
   char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   EngineSimObject* result = GetObjectPtr()->findComponentByType(_name);
   if (result)
      return SimObject::Wrap(result);

   return nullptr;
}

void IJWLayer::SceneCamera::lookAt(Point3F^ look_at)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->lookAt(look_at->ToEngine());
}

void IJWLayer::SceneCamera::translate(Point3F^ translation)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->lookAt(translation->ToEngine());
}

void IJWLayer::SceneCamera::pan(Point3F^ pan)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->lookAt(pan->ToEngine());
}

void IJWLayer::SceneCamera::setPanVelocity(Point3F^ panVel)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->lookAt(panVel->ToEngine());
}

void IJWLayer::SceneCamera::setPosition(Point3F^ position)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->lookAt(position->ToEngine());
}

void IJWLayer::SceneCamera::rotate(Point3F^ rotation)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->lookAt(rotation->ToEngine());
}

void IJWLayer::SceneCamera::bindMouse(bool value, bool left, bool right)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setBindMouse(value, left, right);
}

void IJWLayer::SceneCamera::bindMouse(bool value, bool left)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setBindMouse(value, left);
}

void IJWLayer::SceneCamera::bindMouse(bool value)
{
   if (!IsAlive())
      return;
   GetObjectPtr()->setBindMouse(value);
}