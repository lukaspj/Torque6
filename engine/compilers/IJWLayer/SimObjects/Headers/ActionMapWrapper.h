// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

#include "input/actionMap.h"

namespace IJWLayer {

   using namespace System;

   public ref class ActionMapWrapper : SimObjectWrapper
	{
   public:
      ActionMapWrapper()
      {
         mObject = new ActionMap();
         if (!mObject->registerObject())
            throw gcnew Exception("Register object failed");
         mPtr = new SimObjectPtr<SimObject>(mObject);
      };

      static ActionMapWrapper^ Wrap(int ID) { return static_cast<ActionMapWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static ActionMapWrapper^ Wrap(SimObject* obj) { return static_cast<ActionMapWrapper^>(SimObjectWrapper::Wrap(obj)); };

      ActionMap* GetObjectPtr();

      void bind(String^ device, String^ action, String^ command, ...array<String^> ^modifiers);
      void _bindObj(String^ device, String^ action, String^ command, SimObject* objectID, array<String^> ^modifiers);
      void bindObj(String^ device, String^ action, String^ command, int objectID, ...array<String^> ^modifiers);
      void bindObj(String^ device, String^ action, String^ command, SimObjectWrapper ^object, ...array<String^> ^modifiers);
      void bindCmd(String^ device, String^ action, String^ makeCmd, String^ breakCmd);
      void unbind(String^ device, String^ action);
      void _unbindObj(String^ device, String^ action, SimObject* object);
      void unbindObj(String^ device, String^ action, int objectID);
      void unbindObj(String^ device, String^ action, SimObjectWrapper ^object);
      void save(String^ fileName, bool append);
      void save(String^ fileName);
      void save();
      void push();
      void pop();
      String^ getBinding(String^ command);
      String^ getCommand(String^ device, String^ action);
      bool isInverted(String^ device, String^ action);
      float getScale(String^ device, String^ action);
      String^ getDeadZone(String^ device, String^ action);
	};
}
