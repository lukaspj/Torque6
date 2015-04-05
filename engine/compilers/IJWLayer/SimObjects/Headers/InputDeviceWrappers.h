// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "CollectionsWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "platform/platformInput.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef InputDevice EngineInputDevice;
typedef InputManager EngineInputManager;

namespace IJWLayer {

   public ref class Input{
   public:
      //static bool activateKeyboard();
      //static void deactivateKeyboard();
      //static bool enableMouse();
      //static void disableMouse();
      //static bool enableJoystick();
      //static void disableJoystick();
      //static void echoInputState();
      //static void enableXInput();
      //static void disableXInput();
      //static void resetXInput();
      //static void isXInputConnected(int controllerID);
      //static void getXInputState(int controllerID, String^ action, bool current);
      //static void rumble(String^ device, float xRumble, float yRumble);

   };

   public ref class InputDevice : SimObject
   {
   public:
      static InputDevice^ Wrap(int ID) { return static_cast<InputDevice^>(SimObject::Wrap(ID)); };
      static InputDevice^ Wrap(EngineInputDevice* obj) { return static_cast<InputDevice^>(SimObject::Wrap(obj)); };

      EngineInputDevice* GetObjectPtr(){
         return static_cast<EngineInputDevice*>(mObject);
      };
   };

   public ref class InputManager : SimGroup
   {
   public:
      static InputManager^ Wrap(int ID) { return static_cast<InputManager^>(SimObject::Wrap(ID)); };
      static InputManager^ Wrap(EngineInputManager* obj) { return static_cast<InputManager^>(SimObject::Wrap(obj)); };

      EngineInputManager* GetObjectPtr(){
         return static_cast<EngineInputManager*>(mObject);
      };
   };
}
