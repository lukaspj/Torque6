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
      InputDeviceWrapper(int ID) : SimObjectWrapper(ID){};

      InputDevice* GetObjectPtr(){
         return static_cast<InputDevice*>(mObject);
      };
   };

   public ref class InputManagerWrapper : SimGroupWrapper
   {
   public:
      InputManagerWrapper(int ID) : SimGroupWrapper(ID){};

      InputManager* GetObjectPtr(){
         return static_cast<InputManager*>(mObject);
      };
   };
}
