// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "CollectionsWrapper.h"
#include "platform/platformInput.h"

using namespace System;

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

   public ref class InputDeviceWrapper : SimObjectWrapper
   {
   public:
      static InputDeviceWrapper^ Wrap(int ID) { return static_cast<InputDeviceWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static InputDeviceWrapper^ Wrap(InputDevice* obj) { return static_cast<InputDeviceWrapper^>(SimObjectWrapper::Wrap(obj)); };

      InputDevice* GetObjectPtr(){
         return static_cast<InputDevice*>(mObject);
      };
   };

   public ref class InputManagerWrapper : SimGroupWrapper
   {
   public:
      static InputManagerWrapper^ Wrap(int ID) { return static_cast<InputManagerWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static InputManagerWrapper^ Wrap(InputManager* obj) { return static_cast<InputManagerWrapper^>(SimObjectWrapper::Wrap(obj)); };

      InputManager* GetObjectPtr(){
         return static_cast<InputManager*>(mObject);
      };
   };
}
