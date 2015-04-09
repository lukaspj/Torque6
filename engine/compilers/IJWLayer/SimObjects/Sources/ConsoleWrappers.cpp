#include "../../Stdafx.h"
#include "../Headers/ConsoleWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

int IJWLayer::ConsoleLogger::Level::get()
{
   if (IsAlive())
      return GetObjectPtr()->getLogLevel();
   else
      return -1;
}

void IJWLayer::ConsoleLogger::Level::set(int value)
{
   if (IsAlive())
      GetObjectPtr()->setLogLevel((ConsoleLogEntry::Level)value);
}

bool IJWLayer::ConsoleLogger::attach()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->attach();
}

bool IJWLayer::ConsoleLogger::detach()
{
   if (!IsAlive())
      return false;
   return GetObjectPtr()->detach();
}