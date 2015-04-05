#include "../../Stdafx.h"
#include "../Headers/GuiWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

int IJWLayer::PopupMenu::insertItem(int pos, String^ title, String^ accelerator)
{
   if (!IsAlive())
      return -1;
   char* _title = (char*)Marshal::StringToHGlobalAnsi(title).ToPointer();
   char* _accelerator = (char*)Marshal::StringToHGlobalAnsi(accelerator).ToPointer();
   return GetObjectPtr()->insertItem(pos, _title, _accelerator);
}

int IJWLayer::PopupMenu::insertItem(int pos, String^ title)
{
   return insertItem(pos, title, "");
}

int IJWLayer::PopupMenu::insertItem(int pos)
{
   return insertItem(pos, nullptr, "");
}

void IJWLayer::PopupMenu::removeItem(int pos)
{
   if (IsAlive())
      GetObjectPtr()->removeItem(pos);
}

int IJWLayer::PopupMenu::insertSubMenu(int pos, String^ title, PopupMenu^ submenu)
{
   if (!IsAlive())
      return -1;
   if (!submenu->IsAlive())
   {
      Con::errorf("PopupMenu::insertSubMenu - Invalid PopupMenu object specified for submenu");
      return -1;
   }
   char* _title = (char*)Marshal::StringToHGlobalAnsi(title).ToPointer();
   return GetObjectPtr()->insertSubMenu(pos, _title, submenu->GetObjectPtr());
}

void IJWLayer::PopupMenu::enableItem(int pos, bool enable)
{
   if (IsAlive())
      GetObjectPtr()->enableItem(pos, enable);
}

void IJWLayer::PopupMenu::checkItem(int pos, bool checked)
{
   if (IsAlive())
      GetObjectPtr()->enableItem(pos, checked);
}

void IJWLayer::PopupMenu::checkRadioItem(int firstPos, int lastPos, int checkPos)
{
   if (IsAlive())
      GetObjectPtr()->checkRadioItem(firstPos, lastPos, checkPos);
}

bool IJWLayer::PopupMenu::isItemChecked(int pos)
{
   if (IsAlive())
      return GetObjectPtr()->isItemChecked(pos);
   return false;
}

void IJWLayer::PopupMenu::attachToMenuBar(int pos, String^ title)
{
   if (!IsAlive())
      return;

   char* _title = (char*)Marshal::StringToHGlobalAnsi(title).ToPointer();
   GetObjectPtr()->attachToMenuBar(pos, _title);
}

void IJWLayer::PopupMenu::removeFromMenuBar()
{
   if (IsAlive())
      GetObjectPtr()->removeFromMenuBar();
}

void IJWLayer::PopupMenu::showPopup(int x, int y)
{
   if (IsAlive())
      GetObjectPtr()->showPopup(x,y);
}

void IJWLayer::PopupMenu::showPopup(int x)
{
   showPopup(x, -1);
}

void IJWLayer::PopupMenu::showPopup()
{
   showPopup(-1, -1);
}


