#include "../../stdafx.h"
#include "../Headers/Version.h"
#include "../Headers/Globals.h"
#include "console/console.h"
#include "game/version.h"
#include "string/stringTable.h"
#include "io/resource/resourceManager.h"

using namespace System::Runtime::InteropServices;

void IJWLayer::EngineVersion::setCompanyAndProduct(String^ company, String^ product)
{
   char* _company = (char*)Marshal::StringToHGlobalAnsi(company).ToPointer();
   char* _product = (char*)Marshal::StringToHGlobalAnsi(product).ToPointer();

   setCompanyName(StringTable->insert(_company));
   setProductName(StringTable->insert(_product));

   Global::SetString("$Game::CompanyName", getCompanyName());
   Global::SetString("$Game::ProductName", getProductName());

   char appDataPath[1024];
   dSprintf(appDataPath, sizeof(appDataPath), "%s/%s/%s", Platform::getUserDataDirectory(), getCompanyName(), getProductName());

   ResourceManager->addPath(appDataPath);
}