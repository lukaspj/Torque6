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
      GuiControlProfileWrapper(int ID) : SimObjectWrapper(ID){};

      GuiControlProfile* GetObjectPtr(){
         return static_cast<GuiControlProfile*>(mObject);
      };
   };

   public ref class GuiCursorWrapper : SimObjectWrapper
   {
   public:
      GuiCursorWrapper(int ID) : SimObjectWrapper(ID){};

      GuiCursor* GetObjectPtr(){
         return static_cast<GuiCursor*>(mObject);
      };
   };

   public ref class GuiImageListWrapper : SimObjectWrapper
   {
   public:
      GuiImageListWrapper(int ID) : SimObjectWrapper(ID){};

      GuiImageList* GetObjectPtr(){
         return static_cast<GuiImageList*>(mObject);
      };
   };

   public ref class PopupMenuWrapper : SimObjectWrapper
   {
   public:
      PopupMenuWrapper(int ID) : SimObjectWrapper(ID){};

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
