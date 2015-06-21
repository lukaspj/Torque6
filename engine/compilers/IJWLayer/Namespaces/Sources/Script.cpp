#include "../../stdafx.h"
#include "../Headers/Engine.h"
#include "../../SimObjects/Headers/MarshalHelper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/console.h"
#include "console/consoleNamespace.h"
#include "console/consoleExprEvalState.h"
#include "platform/platform.h"
#include "io/resource/resourceManager.h"
#include "debug/remote/RemoteDebuggerBridge.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace EngineCon = Con;
typedef Platform EnginePlatform;

static StringTableEntry _getDSOPath(const char *scriptPath)
{
   const char *slash = dStrrchr(scriptPath, '/');
   return StringTable->insertn(scriptPath, (U32)(slash - scriptPath), true);
}

DLL_PUBLIC extern bool scriptExecutionEcho;
void IJWLayer::Engine::Script::setScriptExecEcho(bool echo)
{
   scriptExecutionEcho = echo;
}

DLL_PUBLIC extern ExprEvalState gEvalState;
void IJWLayer::Engine::Script::trace(bool enable)
{
   gEvalState.traceOn = enable;
   EngineCon::printf("Console trace is %s", enable ? "on." : "off.");
}

void IJWLayer::Engine::Script::debug()
{
   EnginePlatform::debugBreak();
}

void IJWLayer::Engine::Script::backtrace()
{
   U32 totalSize = 1;

   for (U32 i = 0; i < (U32)gEvalState.stack.size(); i++)
   {
      totalSize += dStrlen(gEvalState.stack[i]->scopeName) + 3;
      if (gEvalState.stack[i]->scopeNamespace && gEvalState.stack[i]->scopeNamespace->mName)
         totalSize += dStrlen(gEvalState.stack[i]->scopeNamespace->mName) + 2;
   }

   char *buf = EngineCon::getReturnBuffer(totalSize);
   buf[0] = 0;
   for (U32 i = 0; i < (U32)gEvalState.stack.size(); i++)
   {
      dStrcat(buf, "->");
      if (gEvalState.stack[i]->scopeNamespace && gEvalState.stack[i]->scopeNamespace->mName)
      {
         dStrcat(buf, gEvalState.stack[i]->scopeNamespace->mName);
         dStrcat(buf, "::");
      }
      dStrcat(buf, gEvalState.stack[i]->scopeName);
   }
   EngineCon::printf("BackTrace: %s", buf);
}

bool IJWLayer::Engine::Script::isPackage(String^ packageName)
{
   char* _packageName = (char*)Marshal::StringToHGlobalAnsi(packageName).ToPointer();
   StringTableEntry __packageName = StringTable->insert(_packageName);
   return Namespace::isPackage(__packageName);
}

void IJWLayer::Engine::Script::activatePackage(String^ packageName)
{
   char* _packageName = (char*)Marshal::StringToHGlobalAnsi(packageName).ToPointer();
   StringTableEntry __packageName = StringTable->insert(_packageName);
   Namespace::activatePackage(__packageName);
}

void IJWLayer::Engine::Script::deactivatePackage(String^ packageName)
{
   char* _packageName = (char*)Marshal::StringToHGlobalAnsi(packageName).ToPointer();
   StringTableEntry __packageName = StringTable->insert(_packageName);
   Namespace::deactivatePackage(__packageName);
}

String^ IJWLayer::Engine::Script::call(String^ funcName, ...array<String^>^ args)
{
   const char* _funcName = (char*)Marshal::StringToHGlobalAnsi(funcName).ToPointer();

   pin_ptr<const char*> array_pin = &MarshalHelper::MarshalStringArrayToChar(args, 1)[0];
   array_pin[0] = _funcName;
   return gcnew String(EngineCon::execute(args->Length + 1, array_pin));
}

String^ IJWLayer::Engine::Script::getDSOPath(String^ scriptFileName)
{
   const char* _scriptFileName = (char*)Marshal::StringToHGlobalAnsi(scriptFileName).ToPointer();
   
   char* ret = EngineCon::getReturnBuffer(1024);
   EngineCon::expandPath(ret, 1024, _scriptFileName);

   const char *filename = _getDSOPath(ret);
   if (filename == NULL || *filename == 0)
      return "";

   return gcnew String(filename);
}

bool IJWLayer::Engine::Script::compile(String^ fileName)
{
   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   return compile(_fileName, fileName->EndsWith(".ed.cs"));
}

bool IJWLayer::Engine::Script::compile(const char* fileName, bool editorScript)
{
   const char* extension;
   if (editorScript)
      extension = ".edso";
   else
      extension = ".dso";

   char nameBuffer[512];
   char* script = NULL;
   U32 scriptSize = 0;

   FileTime comModifyTime, scrModifyTime;

   char* ret = EngineCon::getReturnBuffer(1024);
   EngineCon::expandPath(ret, 1024, fileName);

   const char *filenameOnly = dStrrchr(ret, '/');
   if (filenameOnly)
      ++filenameOnly;
   else
      filenameOnly = ret;

   // Figure out where to put DSOs
   StringTableEntry dsoPath = _getDSOPath(ret);

   if (editorScript)
      dStrcpyl(nameBuffer, sizeof(nameBuffer), dsoPath, "/", filenameOnly, ".edso", NULL);
   else
      dStrcpyl(nameBuffer, sizeof(nameBuffer), dsoPath, "/", filenameOnly, ".dso", NULL);

   ResourceObject *rScr = ResourceManager->find(ret);
   ResourceObject *rCom = ResourceManager->find(nameBuffer);

   if (rCom)
      rCom->getFileTimes(NULL, &comModifyTime);
   if (rScr)
      rScr->getFileTimes(NULL, &scrModifyTime);

   Stream *s = ResourceManager->openStream(ret);
   if (s)
   {
      scriptSize = ResourceManager->getSize(ret);
      script = new char[scriptSize + 1];
      s->read(scriptSize, script);
      ResourceManager->closeStream(s);
      script[scriptSize] = 0;
   }

   if (!scriptSize || !script)
   {
      delete[] script;
      EngineCon::errorf(ConsoleLogEntry::Script, "compile: invalid script file %s.", ret);
      return false;
   }

   return true;
}

String^ IJWLayer::Engine::Script::compilePath(String^ path)
{
   const char* _path = (char*)Marshal::StringToHGlobalAnsi(path).ToPointer();
   
   char* ret = EngineCon::getReturnBuffer(1024);
   if (!EngineCon::expandPath(ret, sizeof(ret), _path))
      return "-1 0";

   const char *curFile;

   S32 failedScripts = 0;
   S32 totalScripts = 0;
   ResourceObject *match = NULL;

   while ((match = ResourceManager->findMatch(ret, &curFile, match)))
   {
      size_t str_len = strlen(curFile);

      bool edcs = 0 == strncmp(curFile + str_len - 6, ".ed.cs", 6);
      if (!compile(curFile, edcs))
         failedScripts++;
      totalScripts++;
   }

   char* result = EngineCon::getReturnBuffer(32);
   dSprintf(result, 32, "%d %d", failedScripts, totalScripts);
   return gcnew String(failedScripts + " " + totalScripts);
}

bool IJWLayer::Engine::Script::exec(String^ fileName, bool noCalls, bool journalScript)
{
   return call("exec", fileName, noCalls.ToString(), journalScript.ToString())->ToLower() == "true";
}

String^ IJWLayer::Engine::Script::eval(String^ script)
{
   const char* _script = (char*)Marshal::StringToHGlobalAnsi(script).ToPointer();
   
   return gcnew String(EngineCon::evaluate(_script));
}

bool IJWLayer::Engine::Script::isFunction(String^ funcName)
{
   const char* _funcName = (char*)Marshal::StringToHGlobalAnsi(funcName).ToPointer();

   return EngineCon::isFunction(_funcName);
}

bool IJWLayer::Engine::Script::isMethod(String^ pNamespace, String^ pMethod)
{
   const char* _Namespace = (char*)Marshal::StringToHGlobalAnsi(pNamespace).ToPointer();
   const char* _Method = (char*)Marshal::StringToHGlobalAnsi(pMethod).ToPointer();

   Namespace* ns = Namespace::find(StringTable->insert(_Namespace));
   Namespace::Entry* nse = ns->lookup(StringTable->insert(_Method));
   return nse;
}

String^ IJWLayer::Engine::Script::getModNameFromPath(String^ path)
{
   const char* _path = (char*)Marshal::StringToHGlobalAnsi(path).ToPointer();

   StringTableEntry modPath = EngineCon::getModNameFromPath(_path);
   return modPath ? gcnew String(modPath) : "";
}

bool IJWLayer::Engine::Script::OpenRemoteDebugger(int debuggerVersion, int port, String^ password)
{
   const char* _password = (char*)Marshal::StringToHGlobalAnsi(password).ToPointer();

   return RemoteDebuggerBridge::open(debuggerVersion, port, _password);
}