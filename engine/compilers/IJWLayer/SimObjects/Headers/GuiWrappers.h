// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "gui/guiTypes.h"
#include "gui/editor/guiImageList.h"
#include "platform/menus/popupMenu.h"

using namespace System;

namespace IJWLayer {

   public ref class GuiControlProfileWrapper : SimObjectWrapper
   {
   public:
      static GuiControlProfileWrapper^ Wrap(int ID) { return static_cast<GuiControlProfileWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static GuiControlProfileWrapper^ Wrap(GuiControlProfile* obj) { return static_cast<GuiControlProfileWrapper^>(SimObjectWrapper::Wrap(obj)); };

      GuiControlProfile* GetObjectPtr(){
         return static_cast<GuiControlProfile*>(mObject);
      };
   };

   public ref class GuiCursorWrapper : SimObjectWrapper
   {
   public:
      static GuiCursorWrapper^ Wrap(int ID) { return static_cast<GuiCursorWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static GuiCursorWrapper^ Wrap(GuiCursor* obj) { return static_cast<GuiCursorWrapper^>(SimObjectWrapper::Wrap(obj)); };

      GuiCursor* GetObjectPtr(){
         return static_cast<GuiCursor*>(mObject);
      };
   };

   public ref class GuiImageListWrapper : SimObjectWrapper
   {
   public:
      static GuiImageListWrapper^ Wrap(int ID) { return static_cast<GuiImageListWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static GuiImageListWrapper^ Wrap(GuiImageList* obj) { return static_cast<GuiImageListWrapper^>(SimObjectWrapper::Wrap(obj)); };

      GuiImageList* GetObjectPtr(){
         return static_cast<GuiImageList*>(mObject);
      };
   };

   public ref class PopupMenuWrapper : SimObjectWrapper
   {
   public:
      static PopupMenuWrapper^ Wrap(int ID) { return static_cast<PopupMenuWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static PopupMenuWrapper^ Wrap(PopupMenu* obj) { return static_cast<PopupMenuWrapper^>(SimObjectWrapper::Wrap(obj)); };

      PopupMenu* GetObjectPtr(){
         return static_cast<PopupMenu*>(mObject);
      };

      int insertItem(int pos, String^ title, String^ accelerator);
      int insertItem(int pos, String^ title);
      int insertItem(int pos);
      void removeItem(int pos);
      int insertSubMenu(int pos, String^ title, PopupMenuWrapper^ menu);
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
