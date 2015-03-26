// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "collection/undo.h"

namespace IJWLayer {

   public ref class UndoManagerWrapper : SimObjectWrapper
   {
   public:
      UndoManagerWrapper(int ID) : SimObjectWrapper(ID){};
      UndoManagerWrapper(UndoManager* object) : SimObjectWrapper(object){};

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
      UndoActionWrapper(int ID) : SimObjectWrapper(ID){};
      UndoActionWrapper(UndoAction* object) : SimObjectWrapper(object){};

      UndoAction* GetObjectPtr(){
         return static_cast<UndoAction*>(mObject);
      };

      void addToManager(UndoManagerWrapper^ undoManager);
      void addToManager();
   };

}
