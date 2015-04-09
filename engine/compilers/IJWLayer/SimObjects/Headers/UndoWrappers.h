// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "collection/undo.h"

// #pragma unmanaged
#pragma managed(pop)

typedef UndoManager EngineUndoManager;
typedef UndoAction EngineUndoAction;

namespace IJWLayer {

   public ref class UndoManager : SimObject
   {
   public:
      static UndoManager^ Wrap(int ID) { return static_cast<UndoManager^>(SimObject::Wrap(ID)); };
      static UndoManager^ Wrap(EngineUndoManager* obj) { return static_cast<UndoManager^>(SimObject::Wrap(obj)); };

      EngineUndoManager* GetObjectPtr(){
         return static_cast<EngineUndoManager*>(mObject);
      };

      property int NumLevels{
         int get();
         void set(int value);
      }

      int getRedoCount();
      void clearAll();
      int getUndoCount();
      String^ getUndoName(int index);
      String^ getRedoName(int index);
      void undo();
      void redo();
      String^ getNextUndoName();
      String^ getNextRedoName();
   };

   public ref class UndoAction : SimObject
   {
   public:
      static UndoAction^ Wrap(int ID) { return static_cast<UndoAction^>(SimObject::Wrap(ID)); };
      static UndoAction^ Wrap(EngineUndoAction* obj) { return static_cast<UndoAction^>(SimObject::Wrap(obj)); };

      EngineUndoAction* GetObjectPtr(){
         return static_cast<EngineUndoAction*>(mObject);
      };

      property String^ ActionName{
         String^ get();
         void set(String^ value);
      }

      void addToManager(UndoManager^ undoManager);
      void addToManager();
   };

}
