#include "../../stdafx.h"
#include "../Headers/Globals.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/console.h"
#include "console/consoleExprEvalState.h"
#include "platform/platform.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System::Runtime::InteropServices;

typedef Platform EnginePlatform;
namespace EngineCon = Con;

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

String^ IJWLayer::Globals::getPrefsPath(String^ fileName)
{
   const char *filename;
   if (fileName == nullptr)
      filename = EnginePlatform::getPrefsPath(NULL);
   else
   {
      const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
      filename = EnginePlatform::getPrefsPath(_fileName);
   }
   if (filename == NULL || *filename == 0)
      return "";

   return gcnew String(filename);
}

bool IJWLayer::Globals::execPrefs(String^ fileName, bool noCalls, bool journalScript)
{
   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   const char *filename = EnginePlatform::getPrefsPath(_fileName);
   if (filename == NULL || *filename == 0)
      return false;

   if (!EnginePlatform::isFile(filename))
      return false;

   return EngineCon::executef(2, "exec", filename);
}

DLL_PUBLIC extern ExprEvalState gEvalState;
void IJWLayer::Globals::export(String^ wildCard, String^ fileName, bool append)
{
   const char* _wildCard = (char*)Marshal::StringToHGlobalAnsi(wildCard).ToPointer();
   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   
   // Fetch the filename.
   char* pFilename = NULL;
   if (fileName != nullptr)
   {
      pFilename = EngineCon::getReturnBuffer(512);
      Con::expandPath(pFilename, sizeof(pFilename), _fileName);
   }

   // Export the variables.
   gEvalState.globalVars.exportVariables(_wildCard, pFilename, append);
}

void IJWLayer::Globals::deleteVariables(String^ wildCard)
{
   const char* _wildCard = (char*)Marshal::StringToHGlobalAnsi(wildCard).ToPointer();
   
   gEvalState.globalVars.deleteVariables(_wildCard);
}