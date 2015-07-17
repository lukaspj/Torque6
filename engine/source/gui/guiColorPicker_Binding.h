//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#include "c-interface/c-interface.h"

extern "C"{
   DLL_PUBLIC GuiColorPickerCtrl* GuiColorPickerCtrlCreateInstance()
   {
      return new GuiColorPickerCtrl();
   }

   DLL_PUBLIC void GuiColorPickerCtrlGetBaseColor(GuiColorPickerCtrl* ctrl, CInterface::ColorParam* outColor)
   {
      *outColor = ctrl->getBaseColor();
   }

   DLL_PUBLIC void GuiColorPickerCtrlSetBaseColor(GuiColorPickerCtrl* ctrl, CInterface::ColorParam color)
   {
      ctrl->setBaseColor(color);
   }

   DLL_PUBLIC void GuiColorPickerCtrlGetPickColor(GuiColorPickerCtrl* ctrl, CInterface::ColorParam* outColor)
   {
      *outColor = ctrl->getPickColor();
   }

   DLL_PUBLIC void GuiColorPickerCtrlSetPickColor(GuiColorPickerCtrl* ctrl, CInterface::ColorParam color)
   {
      ctrl->setPickColor(color);
   }

   DLL_PUBLIC S32 GuiColorPickerCtrlGetSelectorGap(GuiColorPickerCtrl* ctrl)
   {
      return ctrl->getSelectorGap();
   }

   DLL_PUBLIC void GuiColorPickerCtrlSetSelectorGap(GuiColorPickerCtrl* ctrl, S32 gap)
   {
      ctrl->setSelectorGap(gap);
   }

   DLL_PUBLIC S32 GuiColorPickerCtrlGetDisplayMode(GuiColorPickerCtrl* ctrl)
   {
      return ctrl->getDisplayMode();
   }

   DLL_PUBLIC void GuiColorPickerCtrlSetDisplayMode(GuiColorPickerCtrl* ctrl, S32 mode)
   {
      ctrl->setDisplayMode((GuiColorPickerCtrl::PickMode)mode);
   }

   DLL_PUBLIC bool GuiColorPickerCtrlGetActionOnMove(GuiColorPickerCtrl* ctrl)
   {
      return ctrl->getActionOnMove();
   }

   DLL_PUBLIC void GuiColorPickerCtrlSetActionOnMove(GuiColorPickerCtrl* ctrl, bool actionOnMove)
   {
      ctrl->setActionOnMove(actionOnMove);
   }

   DLL_PUBLIC bool GuiColorPickerCtrlGetShowSelector(GuiColorPickerCtrl* ctrl)
   {
      return ctrl->getShowSelector();
   }

   DLL_PUBLIC void GuiColorPickerCtrlSetShowSelector(GuiColorPickerCtrl* ctrl, bool showSelector)
   {
      ctrl->setShowSelector(showSelector);
   }
}