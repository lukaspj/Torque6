#include "../../stdafx.h"
#include "../Headers/Globals.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/console.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System::Runtime::InteropServices;

String^ IJWLayer::Globals::GetString(String^ name)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   return gcnew String(Con::getVariable(_name));
}

void IJWLayer::Globals::SetString(String^ name, String^ value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   Con::setVariable(_name, _value);
}

void IJWLayer::Globals::SetString(String^ name, const char* value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   Con::setVariable(_name, value);
}

int IJWLayer::Globals::GetInt(String^ name)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   return Con::getIntVariable(_name);
}

void IJWLayer::Globals::SetInt(String^ name, int value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   Con::setIntVariable(_name, value);
}

bool IJWLayer::Globals::GetBool(String^ name)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   return Con::getBoolVariable(_name);
}

void IJWLayer::Globals::SetBool(String^ name, bool value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   Con::setBoolVariable(_name, value);
}

float IJWLayer::Globals::GetFloat(String^ name)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   return Con::getFloatVariable(_name);
}

void IJWLayer::Globals::SetFloat(String^ name, float value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   Con::setFloatVariable(_name, value);
}