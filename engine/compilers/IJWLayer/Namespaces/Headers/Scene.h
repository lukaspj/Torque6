using System::String;

#include "../../SimObjects/Headers/SceneWrappers.h"

namespace IJWLayer
{
   public ref class Scene
   {
   public: 
      static void addEntity(SceneEntityWrapper^ entity, String^ name);
      static void addEntity(SceneEntityWrapper^ entity);
      static void setDirectionalLight(String^ direction, String^ color, String^ ambient);
   };
}