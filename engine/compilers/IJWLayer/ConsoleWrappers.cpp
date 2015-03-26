#include "Stdafx.h"
#include "ConsoleWrappers.h"
#include "MarshalHelper.h"

using namespace System::Runtime::InteropServices;

bool IJWLayer::ConsoleLoggerWrapper::attach()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->attach();
}

bool IJWLayer::ConsoleLoggerWrapper::detach()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->detach();
}