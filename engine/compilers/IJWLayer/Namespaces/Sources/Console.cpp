#include "../../stdafx.h"
#include "../Headers/Engine.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/console.h"
#include "console/consoleNamespace.h"
#include "io/resource/resourceManager.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System::Runtime::InteropServices;
namespace EngineCon = Con;
typedef Platform EnginePlatform;

void IJWLayer::Engine::Con::setLogMode(int mode)
{
   EngineCon::setLogMode(mode);
}

void IJWLayer::Engine::Con::setEchoFileLoads(bool enable)
{
   ResourceManager->setFileNameEcho(enable);
}

void IJWLayer::Engine::Con::quit()
{
   EnginePlatform::postQuitMessage(0);
}

void IJWLayer::Engine::Con::quitWithErrorMessage(String^ msg)
{
   char* _msg = (char*)Marshal::StringToHGlobalAnsi(msg).ToPointer();
   if (PlatformAssert::processAssert(PlatformAssert::Fatal_ISV, __FILE__, __LINE__, _msg)) 
      EnginePlatform::debugBreak();
}

void IJWLayer::Engine::Con::gotoWebPage(String^ addr)
{
   char* _addr = (char*)Marshal::StringToHGlobalAnsi(addr).ToPointer();

   if (addr->Contains("://"))
   {
      EnginePlatform::openWebBrowser(_addr);
      return;
   }

   char urlBuf[2048];
   if (EnginePlatform::isFile(_addr) || EnginePlatform::isDirectory(_addr))
   {
      dSprintf(urlBuf, sizeof(urlBuf), "file://%s", _addr);
   }
   else
      dSprintf(urlBuf, sizeof(urlBuf), "http://%s", _addr);

   EnginePlatform::openWebBrowser(urlBuf);
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

void IJWLayer::Engine::Con::dumpConsoleClasses(bool dumpScript, bool dumpEngine)
{
   Namespace::dumpClasses(dumpScript, dumpEngine);
}

void IJWLayer::Engine::Con::dumpConsoleFunctions(bool dumpScript, bool dumpEngine)
{
   Namespace::dumpClasses(dumpScript, dumpEngine);
}

void IJWLayer::Engine::Con::echo(String^ text)
{
   char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   EngineCon::printf(_text);
}

void IJWLayer::Engine::Con::echoSeparator()
{
   EngineCon::printSeparator();
}

void IJWLayer::Engine::Con::warn(String^ text)
{
   char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   EngineCon::warnf(ConsoleLogEntry::General, _text);
}

void IJWLayer::Engine::Con::error(String^ text)
{
   char* _text = (char*)Marshal::StringToHGlobalAnsi(text).ToPointer();
   EngineCon::errorf(ConsoleLogEntry::General, _text);
}

String^ IJWLayer::Engine::Con::expandEscape(String^ text)
{
   throw gcnew System::NotImplementedException();
}

String^ IJWLayer::Engine::Con::collapseEscape(String^ text)
{
   throw gcnew System::NotImplementedException();
}