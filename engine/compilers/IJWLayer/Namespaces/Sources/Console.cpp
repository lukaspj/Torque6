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

void IJWLayer::Con::print(String^ str)
{
   char* _str = (char*)Marshal::StringToHGlobalAnsi(str).ToPointer();
   EngineCon::printf(_str);
}

String^ IJWLayer::Con::expandPath(String^ str)
{
   char* _str = (char*)Marshal::StringToHGlobalAnsi(str).ToPointer();
   char* ret = EngineCon::getReturnBuffer(1024);
   EngineCon::expandPath(ret, 1024, _str);
   return gcnew String(ret);
}