// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "network/netObject.h"
#include "network/netConnection.h"
#include "3d/scene/entity.h"
#include "3d/scene/camera.h"

using namespace System;

namespace IJWLayer {

   public ref class SceneEntityWrapper : SimObjectWrapper
   {
   public:
      SceneEntityWrapper(int ID) : SimObjectWrapper(ID){};

      Scene::SceneEntity* GetObjectPtr(){
         return static_cast<Scene::SceneEntity*>(mObject);
      };

      SimObjectWrapper^ findComponent(String^ name);
      SimObjectWrapper^ findComponentByType(String^ type);
      String^ getPosition();
      void setPosition(String^ pos);
   };

   public ref class SceneCameraWrapper : SimObjectWrapper
   {
   public:
      SceneCameraWrapper(int ID) : SimObjectWrapper(ID){};

      Scene::SceneCamera* GetObjectPtr(){
         return static_cast<Scene::SceneCamera*>(mObject);
      };

      void lookAt(String^ look_at);
      void translate(String^ translation);
      void pan(String^ pan);
      void setPanVelocity(String^ panVel);
      void setPosition(String^ position);
      void rotate(String^ rotation);
      void bindMouse(bool value, bool left, bool right);
      void bindMouse(bool value, bool left);
      void bindMouse(bool value);
   };
}
