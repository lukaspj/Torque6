#include "../../stdafx.h"
#include "../Headers/Engine.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "platform/platform.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System::Runtime::InteropServices;
typedef Platform EnginePlatform;

void IJWLayer::Engine::Platform::setMainDotCsDir(String^ Dir)
{
   char* _Dir = (char*)Marshal::StringToHGlobalAnsi(Dir).ToPointer();
   EnginePlatform::setMainDotCsDir(_Dir);
}

bool IJWLayer::Engine::Platform::setCurrentDirectory(String^ Dir)
{
   char* _Dir = (char*)Marshal::StringToHGlobalAnsi(Dir).ToPointer();
   return EnginePlatform::setCurrentDirectory(_Dir);
}