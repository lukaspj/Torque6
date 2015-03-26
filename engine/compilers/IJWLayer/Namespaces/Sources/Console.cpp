#include "../../stdafx.h"
#include "../Headers/Console.h"
#include "console/console.h"

using namespace System::Runtime::InteropServices;
namespace EngineCon = Con;

void IJWLayer::Con::setLogMode(int mode)
{
   EngineCon::setLogMode(mode);
}

void IJWLayer::Con::quit()
{
   Platform::postQuitMessage(0);
}