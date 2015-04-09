// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "input/actionMap.h"

// #pragma unmanaged
#pragma managed(pop)

typedef ActionMap EngineActionMap;

namespace IJWLayer {

   using System::String;

   public ref class ActionMap : SimObject
	{
   public:
      ActionMap();

      static ActionMap^ Wrap(int ID) { return static_cast<ActionMap^>(SimObject::Wrap(ID)); };
      static ActionMap^ Wrap(EngineSimObject* obj) { return static_cast<ActionMap^>(SimObject::Wrap(obj)); };

      EngineActionMap* GetObjectPtr();

      void bind(String^ device, String^ action, String^ command, ...array<String^> ^modifiers);
      void _bindObj(String^ device, String^ action, String^ command, EngineSimObject* objectID, array<String^> ^modifiers);
      void bindObj(String^ device, String^ action, String^ command, int objectID, ...array<String^> ^modifiers);
      void bindObj(String^ device, String^ action, String^ command, SimObject ^object, ...array<String^> ^modifiers);
      void bindCmd(String^ device, String^ action, String^ makeCmd, String^ breakCmd);
      void unbind(String^ device, String^ action);
      void _unbindObj(String^ device, String^ action, EngineSimObject* object);
      void unbindObj(String^ device, String^ action, int objectID);
      void unbindObj(String^ device, String^ action, SimObject ^object);
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
