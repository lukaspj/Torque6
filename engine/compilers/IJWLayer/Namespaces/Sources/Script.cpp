#include "../../stdafx.h"
#include "../Headers/Engine.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "console/console.h"
#include "console/consoleExprEvalState.h"

// #pragma unmanaged
#pragma managed(pop)

namespace EngineCon = Con;

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