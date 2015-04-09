// IJWLayer.h

#pragma once

#include "SimObjectWrapper.h"
#include "AssetWrappers.h"
#include "../../ConsoleTypes/Headers/Points.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "gui/guiTypes.h"
#include "gui/editor/guiImageList.h"
#include "platform/menus/popupMenu.h"

// #pragma unmanaged
#pragma managed(pop)

#using <system.drawing.dll>
using System::String;
using System::Drawing::Color;

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

      property bool Tab {
         bool get();
         void set(bool value);
      }
      property bool CanKeyFocus {
         bool get();
         void set(bool value);
      }
      property bool MouseOverSelected {
         bool get();
         void set(bool value);
      }
      property bool Modal {
         bool get();
         void set(bool value);
      }
      property bool Opaque {
         bool get();
         void set(bool value);
      }
      property Color^ FillColor {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ FillColorHL {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ FillColorNA {
         Color^ get();
         void set(Color^ value);
      }
      property int Border {
         int get();
         void set(int value);
      }
      property int BorderThickness {
         int get();
         void set(int value);
      }
      property Color^ BorderColor {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ BorderColorHL {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ BorderColorNA {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ BevelColorHL {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ BevelColorLL {
         Color^ get();
         void set(Color^ value);
      }
      property String^ FontType {
         String^ get();
         void set(String^ value);
      }
      property int FontSize {
         int get();
         void set(int value);
      }
      property int FontCharset {
         int get();
         void set(int value);
      }
      property Color^ FontColors[int] {
         Color^ get(int index);
         void set(int index, Color^ value);
      }
      property Color^ FontColor {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ FontColorHL {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ FontColorNA {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ FontColorSEL {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ FontColorLink {
         Color^ get();
         void set(Color^ value);
      }
      property Color^ FontColorLinkHL {
         Color^ get();
         void set(Color^ value);
      }
      property int Justify {
         int get();
         void set(int value);
      }
      property IJWLayer::Point2I^ TextOffset {
         Point2I^ get();
         void set(Point2I^ value);
      }
      property bool AutoSizeWidth {
         bool get();
         void set(bool value);
      }
      property bool AutoSizeHeight {
         bool get();
         void set(bool value);
      }
      property bool ReturnTab {
         bool get();
         void set(bool value);
      }
      property bool NumbersOnly {
         bool get();
         void set(bool value);
      }
      property Color^ CursorColor {
         Color^ get();
         void set(Color^ value);
      }
      property String^ Bitmap {
         String^ get();
         void set(String^ value);
      }
      property AudioAsset^ SoundButtonDown {
         AudioAsset^ get();
         void set(AudioAsset^ value);
      }
      property AudioAsset^ SoundButtonOver {
         AudioAsset^ get();
         void set(AudioAsset^ value);
      }
      property GuiControlProfile^ ProfileForChildren {
         GuiControlProfile^ get();
         void set(GuiControlProfile^ value);
      }
   };

   public ref class GuiCursor : SimObject
   {
   public:
      static GuiCursor^ Wrap(int ID) { return static_cast<GuiCursor^>(SimObject::Wrap(ID)); };
      static GuiCursor^ Wrap(EngineGuiCursor* obj) { return static_cast<GuiCursor^>(SimObject::Wrap(obj)); };

      EngineGuiCursor* GetObjectPtr(){
         return static_cast<EngineGuiCursor*>(mObject);
      };

      property IJWLayer::Point2I^ HotSpot {
         Point2I^ get();
         void set(Point2I^ value);
      }
      property IJWLayer::Point2F^ RenderOffset {
         Point2F^ get();
         void set(Point2F^ value);
      }
      property String^ BitmapName {
         String^ get();
         void set(String^ value);
      }

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

      property bool IsPopup {
         bool get();
         void set(bool value);
      }

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
