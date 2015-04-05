#include "../../stdafx.h"
#include "../Headers/Engine.h"
#include "../Headers/Globals.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/console.h"
#include "game/version.h"
#include "string/stringTable.h"
#include "io/resource/resourceManager.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System::Runtime::InteropServices;
typedef Platform EnginePlatform;

void IJWLayer::Engine::Version::setCompanyAndProduct(String^ company, String^ product)
{
   char* _company = (char*)Marshal::StringToHGlobalAnsi(company).ToPointer();
   char* _product = (char*)Marshal::StringToHGlobalAnsi(product).ToPointer();

   setCompanyName(StringTable->insert(_company));
   setProductName(StringTable->insert(_product));

   Globals::SetString("$Game::CompanyName", getCompanyName());
   Globals::SetString("$Game::ProductName", getProductName());

   char appDataPath[1024];
   dSprintf(appDataPath, sizeof(appDataPath), "%s/%s/%s", EnginePlatform::getUserDataDirectory(), getCompanyName(), getProductName());

   ResourceManager->addPath(appDataPath);
}