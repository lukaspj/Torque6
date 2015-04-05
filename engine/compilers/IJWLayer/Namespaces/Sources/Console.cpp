#include "../../stdafx.h"
#include "../Headers/Engine.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/console.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System::Runtime::InteropServices;
namespace EngineCon = Con;
typedef Platform EnginePlatform;

void IJWLayer::Engine::Con::setLogMode(int mode)
{
   EngineCon::setLogMode(mode);
}

void IJWLayer::Engine::Con::quit()
{
   EnginePlatform::postQuitMessage(0);
}

void IJWLayer::Engine::Con::print(String^ str)
{
   char* _str = (char*)Marshal::StringToHGlobalAnsi(str).ToPointer();
   EngineCon::printf(_str);
}

String^ IJWLayer::Engine::Con::expandPath(String^ str)
{
   char* _str = (char*)Marshal::StringToHGlobalAnsi(str).ToPointer();
   char* ret = EngineCon::getReturnBuffer(1024);
   EngineCon::expandPath(ret, 1024, _str);
   return gcnew String(ret);
}