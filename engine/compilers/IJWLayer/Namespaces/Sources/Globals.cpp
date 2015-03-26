#include "../../stdafx.h"
#include "../Headers/Globals.h"
#include "console/console.h"

using namespace System::Runtime::InteropServices;

String^ IJWLayer::Global::GetString(String^ name)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   return gcnew String(Con::getVariable(_name));
}

void IJWLayer::Global::SetString(String^ name, String^ value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   char* _value = (char*)Marshal::StringToHGlobalAnsi(value).ToPointer();
   Con::setVariable(_name, _value);
}

void IJWLayer::Global::SetString(String^ name, const char* value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   Con::setVariable(_name, value);
}

int IJWLayer::Global::GetInt(String^ name)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   return Con::getIntVariable(_name);
}

void IJWLayer::Global::SetInt(String^ name, int value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   Con::setIntVariable(_name, value);
}

bool IJWLayer::Global::GetBool(String^ name)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   return Con::getBoolVariable(_name);
}

void IJWLayer::Global::SetBool(String^ name, bool value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   Con::setBoolVariable(_name, value);
}

float IJWLayer::Global::GetFloat(String^ name)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   return Con::getFloatVariable(_name);
}

void IJWLayer::Global::SetFloat(String^ name, float value)
{
   char* _name = (char*)Marshal::StringToHGlobalAnsi("$" + name).ToPointer();
   Con::setFloatVariable(_name, value);
}