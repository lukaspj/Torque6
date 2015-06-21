#include "../../Stdafx.h"
#include "../Headers/Engine.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "platform/platformInput.h"

// #pragma unmanaged
#pragma managed(pop)

typedef Input EngineInput;

void IJWLayer::Engine::Input::activateDirectInput()
{
   if (!EngineInput::isActive())
      EngineInput::activate();
}

void IJWLayer::Engine::Input::deactivateDirectInput()
{
   if (EngineInput::isActive())
      EngineInput::deactivate();
}