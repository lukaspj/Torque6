// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "../../ConsoleTypes/Headers/Points.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "network/netObject.h"
#include "network/netConnection.h"
#include "3d/scene/entity.h"
#include "3d/scene/camera.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;
namespace EngineScene = Scene;

namespace IJWLayer {

   public ref class SceneEntity : SimObject
   {
   public:
      SceneEntity() : SimObject(new EngineScene::SceneEntity()) {}

      static SceneEntity^ Wrap(int ID) { return static_cast<SceneEntity^>(SimObject::Wrap(ID)); };
      static SceneEntity^ Wrap(EngineScene::SceneEntity* obj) { return static_cast<SceneEntity^>(SimObject::Wrap(obj)); };

      EngineScene::SceneEntity* GetObjectPtr(){
         return static_cast<EngineScene::SceneEntity*>(mObject);
      };

      SimObject^ findComponent(String^ name);
      SimObject^ findComponentByType(String^ type);

      property String^ Template{
         void set(String^ value);
      }
      property Point3F^ Position{
         Point3F^ get();
         void set(Point3F^ value);
      }
      property EulerF^ Rotation{
         EulerF^ get();
         void set(EulerF^ value);
      }
      property VectorF^ Scale{
         VectorF^ get();
         void set(VectorF^ value);
      }
   };

   public ref class SceneCamera : SimObject
   {
   public:
      static SceneCamera^ Wrap(int ID) { return static_cast<SceneCamera^>(SimObject::Wrap(ID)); };
      static SceneCamera^ Wrap(EngineScene::SceneCamera* obj) { return static_cast<SceneCamera^>(SimObject::Wrap(obj)); };

      EngineScene::SceneCamera* GetObjectPtr(){
         return static_cast<EngineScene::SceneCamera*>(mObject);
      };

      void lookAt(Point3F^ look_at);
      void translate(Point3F^ translation);
      void pan(Point3F^ pan);
      void setPanVelocity(Point3F^ panVel);
      void setPosition(Point3F^ position);
      void rotate(Point3F^ rotation);
      void bindMouse(bool value, bool left, bool right);
      void bindMouse(bool value, bool left);
      void bindMouse(bool value);
   };
}
