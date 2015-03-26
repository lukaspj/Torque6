#include "../../Stdafx.h"
#include "../Headers/GuiWrappers.h"
#include "../Headers/MarshalHelper.h"

using namespace System::Runtime::InteropServices;

int IJWLayer::PopupMenuWrapper::insertItem(int pos, String^ title, String^ accelerator)
{
   if (!IsAlive())
      return -1;
   char* _title = (char*)Marshal::StringToHGlobalAnsi(title).ToPointer();
   char* _accelerator = (char*)Marshal::StringToHGlobalAnsi(accelerator).ToPointer();
   return GetObjectPtr()->insertItem(pos, _title, _accelerator);
}

int IJWLayer::PopupMenuWrapper::insertItem(int pos, String^ title)
{
   return insertItem(pos, title, "");
}

int IJWLayer::PopupMenuWrapper::insertItem(int pos)
{
   return insertItem(pos, nullptr, "");
}

void IJWLayer::PopupMenuWrapper::removeItem(int pos)
{
   if (IsAlive())
      GetObjectPtr()->removeItem(pos);
}

int IJWLayer::PopupMenuWrapper::insertSubMenu(int pos, String^ title, PopupMenuWrapper^ submenu)
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

void IJWLayer::PopupMenuWrapper::enableItem(int pos, bool enable)
{
   if (IsAlive())
      GetObjectPtr()->enableItem(pos, enable);
}

void IJWLayer::PopupMenuWrapper::checkItem(int pos, bool checked)
{
   if (IsAlive())
      GetObjectPtr()->enableItem(pos, checked);
}

void IJWLayer::PopupMenuWrapper::checkRadioItem(int firstPos, int lastPos, int checkPos)
{
   if (IsAlive())
      GetObjectPtr()->checkRadioItem(firstPos, lastPos, checkPos);
}

bool IJWLayer::PopupMenuWrapper::isItemChecked(int pos)
{
   if (IsAlive())
      return GetObjectPtr()->isItemChecked(pos);
   return false;
}

void IJWLayer::PopupMenuWrapper::attachToMenuBar(int pos, String^ title)
{
   if (!IsAlive())
      return;

   char* _title = (char*)Marshal::StringToHGlobalAnsi(title).ToPointer();
   GetObjectPtr()->attachToMenuBar(pos, _title);
}

void IJWLayer::PopupMenuWrapper::removeFromMenuBar()
{
   if (IsAlive())
      GetObjectPtr()->removeFromMenuBar();
}

void IJWLayer::PopupMenuWrapper::showPopup(int x, int y)
{
   if (IsAlive())
      GetObjectPtr()->showPopup(x,y);
}

void IJWLayer::PopupMenuWrapper::showPopup(int x)
{
   showPopup(x, -1);
}

void IJWLayer::PopupMenuWrapper::showPopup()
{
   showPopup(-1, -1);
}


