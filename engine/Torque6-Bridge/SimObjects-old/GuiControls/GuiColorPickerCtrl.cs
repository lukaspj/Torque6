using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiColorPickerCtrl : GuiControl
   {
      
      public GuiColorPickerCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiColorPickerCtrlCreateInstance());
      }

      public GuiColorPickerCtrl(uint pId) : base(pId)
      {
      }

      public GuiColorPickerCtrl(string pName) : base(pName)
      {
      }

      public GuiColorPickerCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiColorPickerCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiColorPickerCtrl(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiColorPickerCtrlGetBaseColor(IntPtr ctrl, out Color outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiColorPickerCtrlSetBaseColor(IntPtr ctrl, Color color);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiColorPickerCtrlGetPickColor(IntPtr ctrl, out Color outColor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiColorPickerCtrlSetPickColor(IntPtr ctrl, Color color);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiColorPickerCtrlGetSelectorGap(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiColorPickerCtrlSetSelectorGap(IntPtr ctrl, int gap);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiColorPickerCtrlGetDisplayMode(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiColorPickerCtrlSetDisplayMode(IntPtr ctrl, int mode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiColorPickerCtrlGetActionOnMove(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiColorPickerCtrlSetActionOnMove(IntPtr ctrl, bool actionOnMove);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiColorPickerCtrlGetShowSelector(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiColorPickerCtrlSetShowSelector(IntPtr ctrl, bool showSelector);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiColorPickerCtrlCreateInstance();
      }
      
      #endregion

      #region Properties

      public Color BaseColor
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            Color outVal;
            InternalUnsafeMethods.GuiColorPickerCtrlGetBaseColor(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiColorPickerCtrlSetBaseColor(ObjectPtr->ObjPtr, value);
         }
      }
      public Color PickColor
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            Color outVal;
            InternalUnsafeMethods.GuiColorPickerCtrlGetPickColor(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiColorPickerCtrlSetPickColor(ObjectPtr->ObjPtr, value);
         }
      }
      public int SelectorGap
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiColorPickerCtrlGetSelectorGap(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiColorPickerCtrlSetSelectorGap(ObjectPtr->ObjPtr, value);
         }
      }
      public int DisplayMode
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiColorPickerCtrlGetDisplayMode(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiColorPickerCtrlSetDisplayMode(ObjectPtr->ObjPtr, value);
         }
      }
      public bool ActionOnMove
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiColorPickerCtrlGetActionOnMove(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiColorPickerCtrlSetActionOnMove(ObjectPtr->ObjPtr, value);
         }
      }
      public bool ShowSelector
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiColorPickerCtrlGetShowSelector(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiColorPickerCtrlSetShowSelector(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}