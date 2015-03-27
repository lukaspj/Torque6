// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "collection/undo.h"

namespace IJWLayer {

   public ref class UndoManagerWrapper : SimObjectWrapper
   {
   public:
      static UndoManagerWrapper^ Wrap(int ID) { return static_cast<UndoManagerWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static UndoManagerWrapper^ Wrap(UndoManager* obj) { return static_cast<UndoManagerWrapper^>(SimObjectWrapper::Wrap(obj)); };

      UndoManager* GetObjectPtr(){
         return static_cast<UndoManager*>(mObject);
      };

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

   public ref class UndoActionWrapper : SimObjectWrapper
   {
   public:
      static UndoActionWrapper^ Wrap(int ID) { return static_cast<UndoActionWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static UndoActionWrapper^ Wrap(UndoAction* obj) { return static_cast<UndoActionWrapper^>(SimObjectWrapper::Wrap(obj)); };

      UndoAction* GetObjectPtr(){
         return static_cast<UndoAction*>(mObject);
      };

      void addToManager(UndoManagerWrapper^ undoManager);
      void addToManager();
   };

}
