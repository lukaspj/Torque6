#include "../../stdafx.h"
#include "../Headers/Script.h"
#include "console/console.h"
#include "console/consoleExprEvalState.h"

namespace EngineCon = Con;

DLL_PUBLIC extern bool scriptExecutionEcho;
void IJWLayer::Script::setScriptExecEcho(bool echo)
{
   scriptExecutionEcho = echo;
}

DLL_PUBLIC extern ExprEvalState gEvalState;
void IJWLayer::Script::trace(bool enable)
{
   gEvalState.traceOn = enable;
   Con::printf("Console trace is %s", enable ? "on." : "off.");
}