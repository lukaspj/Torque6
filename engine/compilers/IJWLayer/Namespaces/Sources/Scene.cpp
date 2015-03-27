#include "../../stdafx.h"
#include "../Headers/Script.h"
#include "console/console.h"
#include "../Headers/Scene.h"
#include "3d/scene/core.h"

using namespace System::Runtime::InteropServices;
namespace EngineScene = Scene;

void IJWLayer::Scene::addEntity(SceneEntityWrapper^ entity, String^ name)
{
   if (!entity->IsAlive())
      return;

   char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   EngineScene::addEntity(entity->GetObjectPtr(), _name);
}

void IJWLayer::Scene::addEntity(SceneEntityWrapper^ entity)
{
   if (!entity->IsAlive())
      return;

   EngineScene::addEntity(entity->GetObjectPtr());
}

void IJWLayer::Scene::setDirectionalLight(String^ dir, String^ col, String^ amb)
{
   const char* _direction = (char*)Marshal::StringToHGlobalAnsi(dir).ToPointer();
   const char* _color = (char*)Marshal::StringToHGlobalAnsi(col).ToPointer();
   const char* _ambient = (char*)Marshal::StringToHGlobalAnsi(amb).ToPointer();

   Point3F direction;
   Con::setData(TypePoint3F, direction, 0, 1, &_direction);

   ColorF color;
   Con::setData(TypeColorF, &color, 0, 1, &_color);

   ColorF ambient;
   Con::setData(TypeColorF, &ambient, 0, 1, &_ambient);

   EngineScene::setDirectionalLight(direction, color, ambient);
}
