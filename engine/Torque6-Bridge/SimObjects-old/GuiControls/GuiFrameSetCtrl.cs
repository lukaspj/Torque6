using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiFrameSetCtrl : GuiControl
   {
      
      public GuiFrameSetCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiFrameSetCtrlCreateInstance());
      }

      public GuiFrameSetCtrl(uint pId) : base(pId)
      {
      }

      public GuiFrameSetCtrl(string pName) : base(pName)
      {
      }

      public GuiFrameSetCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiFrameSetCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiFrameSetCtrl(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiFrameSetCtrlGetBorderWidth(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiFrameSetCtrlSetBorderWidth(IntPtr ctrl, int width);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiFrameSetCtrlGetBorderColor(IntPtr ctrl, out Color outCol);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiFrameSetCtrlSetBorderColor(IntPtr ctrl, Color color);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiFrameSetCtrlGetBorderEnable(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiFrameSetCtrlSetBorderEnable(IntPtr ctrl, int enable);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiFrameSetCtrlGetBorderMovable(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiFrameSetCtrlSetBorderMovable(IntPtr ctrl, int movable);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiFrameSetCtrlGetAutoBalance(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiFrameSetCtrlSetAutoBalance(IntPtr ctrl, bool enable);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiFrameSetCtrlGetFudgeFactor(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiFrameSetCtrlSetFudgeFactor(IntPtr ctrl, int fudgeFactor);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiFrameSetCtrlCreateInstance();
      }
      
      #endregion

      #region Properties

      public int BorderWidth
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiFrameSetCtrlGetBorderWidth(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiFrameSetCtrlSetBorderWidth(ObjectPtr->ObjPtr, value);
         }
      }
      public Color BorderColor
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            Color outVal;
            InternalUnsafeMethods.GuiFrameSetCtrlGetBorderColor(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiFrameSetCtrlSetBorderColor(ObjectPtr->ObjPtr, value);
         }
      }
      public int BorderEnable
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiFrameSetCtrlGetBorderEnable(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiFrameSetCtrlSetBorderEnable(ObjectPtr->ObjPtr, value);
         }
      }
      public int BorderMovable
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiFrameSetCtrlGetBorderMovable(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiFrameSetCtrlSetBorderMovable(ObjectPtr->ObjPtr, value);
         }
      }
      public bool AutoBalance
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiFrameSetCtrlGetAutoBalance(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiFrameSetCtrlSetAutoBalance(ObjectPtr->ObjPtr, value);
         }
      }
      public int FudgeFactor
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiFrameSetCtrlGetFudgeFactor(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiFrameSetCtrlSetFudgeFactor(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}