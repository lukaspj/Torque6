#include "../../stdafx.h"
#include "../Headers/Game.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::Game::Scene::addEntity(IJWLayer::SceneEntity^ entity, String^ name)
{
   if (!entity->IsAlive())
      return;

   char* _name = (char*)Marshal::StringToHGlobalAnsi(name).ToPointer();
   EngineScene::addEntity(entity->GetObjectPtr(), _name);
}

void IJWLayer::Game::Scene::addEntity(IJWLayer::SceneEntity^ entity)
{
   if (!entity->IsAlive())
      return;

   EngineScene::addEntity(entity->GetObjectPtr());
}

void IJWLayer::Game::Scene::setDirectionalLight(IJWLayer::VectorF^ dir, String^ col, String^ amb)
{
   const char* _color = (char*)Marshal::StringToHGlobalAnsi(col).ToPointer();
   const char* _ambient = (char*)Marshal::StringToHGlobalAnsi(amb).ToPointer();

   ColorF color;
   Con::setData(TypeColorF, &color, 0, 1, &_color);

   ColorF ambient;
   Con::setData(TypeColorF, &ambient, 0, 1, &_ambient);

   EngineScene::setDirectionalLight(dir->ToEngine(), color, ambient);
}
