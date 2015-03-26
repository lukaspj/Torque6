#include "../../stdafx.h"
#include "../Headers/Platform.h"
#include "platform/platform.h"

using namespace System::Runtime::InteropServices;
typedef Platform EnginePlatform;

void IJWLayer::Platform::setMainDotCsDir(String^ Dir)
{
   char* _Dir = (char*)Marshal::StringToHGlobalAnsi(Dir).ToPointer();
   EnginePlatform::setMainDotCsDir(_Dir);
}

bool IJWLayer::Platform::setCurrentDirectory(String^ Dir)
{
   char* _Dir = (char*)Marshal::StringToHGlobalAnsi(Dir).ToPointer();
   return EnginePlatform::setCurrentDirectory(_Dir);
}