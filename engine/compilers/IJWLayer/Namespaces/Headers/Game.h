using System::String;

#include "../../SimObjects/Headers/SceneWrappers.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/console.h"
#include "3d/scene/core.h"

// #pragma unmanaged
#pragma managed(pop)

namespace EngineScene = Scene;

namespace IJWLayer {
   public ref class Game
   {
   public:
      ref class Scene
      {
      public:
         static void addEntity(IJWLayer::SceneEntity^ entity, String^ name);
         static void addEntity(IJWLayer::SceneEntity^ entity);
         static void setDirectionalLight(IJWLayer::VectorF^ direction, String^ color, String^ ambient);
      };
   };
}