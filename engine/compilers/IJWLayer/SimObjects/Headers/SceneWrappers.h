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
      SceneEntityWrapper() : SimObjectWrapper(new Scene::SceneEntity()) {}

      static SceneEntityWrapper^ Wrap(int ID) { return static_cast<SceneEntityWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static SceneEntityWrapper^ Wrap(Scene::SceneEntity* obj) { return static_cast<SceneEntityWrapper^>(SimObjectWrapper::Wrap(obj)); };

      Scene::SceneEntity* GetObjectPtr(){
         return static_cast<Scene::SceneEntity*>(mObject);
      };

      SimObjectWrapper^ findComponent(String^ name);
      SimObjectWrapper^ findComponentByType(String^ type);
      String^ getPosition();
      void setPosition(String^ pos);

      property String^ Template{
         void set(String^ value);
      }
      property String^ Position{
         String^ get();
         void set(String^ value);
      }
      property String^ Rotation{
         String^ get();
         void set(String^ value);
      }
      property String^ Scale{
         String^ get();
         void set(String^ value);
      }
   };

   public ref class SceneCameraWrapper : SimObjectWrapper
   {
   public:
      static SceneCameraWrapper^ Wrap(int ID) { return static_cast<SceneCameraWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static SceneCameraWrapper^ Wrap(Scene::SceneCamera* obj) { return static_cast<SceneCameraWrapper^>(SimObjectWrapper::Wrap(obj)); };

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
