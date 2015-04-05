// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "gui/guiTypes.h"
#include "gui/editor/guiImageList.h"
#include "platform/menus/popupMenu.h"

// #pragma unmanaged
#pragma managed(pop)

using namespace System;

typedef GuiControlProfile EngineGuiControlProfile;
typedef GuiCursor EngineGuiCursor;
typedef GuiImageList EngineGuiImageList;
typedef PopupMenu EnginePopupMenu;

namespace IJWLayer {

   public ref class GuiControlProfile : SimObject
   {
   public:
      static GuiControlProfile^ Wrap(int ID) { return static_cast<GuiControlProfile^>(SimObject::Wrap(ID)); };
      static GuiControlProfile^ Wrap(EngineGuiControlProfile* obj) { return static_cast<GuiControlProfile^>(SimObject::Wrap(obj)); };

      EngineGuiControlProfile* GetObjectPtr(){
         return static_cast<EngineGuiControlProfile*>(mObject);
      };
   };

   public ref class GuiCursor : SimObject
   {
   public:
      static GuiCursor^ Wrap(int ID) { return static_cast<GuiCursor^>(SimObject::Wrap(ID)); };
      static GuiCursor^ Wrap(EngineGuiCursor* obj) { return static_cast<GuiCursor^>(SimObject::Wrap(obj)); };

      EngineGuiCursor* GetObjectPtr(){
         return static_cast<EngineGuiCursor*>(mObject);
      };
   };

   public ref class GuiImageList : SimObject
   {
   public:
      static GuiImageList^ Wrap(int ID) { return static_cast<GuiImageList^>(SimObject::Wrap(ID)); };
      static GuiImageList^ Wrap(EngineGuiImageList* obj) { return static_cast<GuiImageList^>(SimObject::Wrap(obj)); };

      EngineGuiImageList* GetObjectPtr(){
         return static_cast<EngineGuiImageList*>(mObject);
      };
   };

   public ref class PopupMenu : SimObject
   {
   public:
      static PopupMenu^ Wrap(int ID) { return static_cast<PopupMenu^>(SimObject::Wrap(ID)); };
      static PopupMenu^ Wrap(EnginePopupMenu* obj) { return static_cast<PopupMenu^>(SimObject::Wrap(obj)); };

      EnginePopupMenu* GetObjectPtr(){
         return static_cast<EnginePopupMenu*>(mObject);
      };

      int insertItem(int pos, String^ title, String^ accelerator);
      int insertItem(int pos, String^ title);
      int insertItem(int pos);
      void removeItem(int pos);
      int insertSubMenu(int pos, String^ title, PopupMenu^ menu);
      void enableItem(int pos, bool enabled);
      void checkItem(int pos, bool checked);
      void checkRadioItem(int firstPos, int lastPos, int checkPos);
      bool isItemChecked(int pos);
      void attachToMenuBar(int pos, String^ title);
      void removeFromMenuBar();
      void showPopup(int x, int y);
      void showPopup(int x);
      void showPopup();
   };
}
