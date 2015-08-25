using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiScrollCtrl : GuiControl
   {
      
      public GuiScrollCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiScrollCtrlCreateInstance());
      }

      public GuiScrollCtrl(uint pId) : base(pId)
      {
      }

      public GuiScrollCtrl(string pName) : base(pName)
      {
      }

      public GuiScrollCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiScrollCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiScrollCtrl(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiScrollCtrlGetWillFirstRespond(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiScrollCtrlSetWillFirstRespond(IntPtr ctrl, bool enable);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiScrollCtrlGetHScrollBar(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiScrollCtrlSetHScrollBar(IntPtr ctrl, int forceHScrollbar);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiScrollCtrlGetVScrollBar(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiScrollCtrlSetVScrollBar(IntPtr ctrl, int forceVScrollbar);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiScrollCtrlGetConstantThumbHeight(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiScrollCtrlSetConstantThumbHeight(IntPtr ctrl, bool useConstantThumbHeight);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiScrollCtrlGetChildMargin(IntPtr ctrl, out Point2I outMargin);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiScrollCtrlSetChildMargin(IntPtr ctrl, Point2I margin);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiScrollCtrlCreateInstance();
      }
      
      #endregion

      #region Properties

      public bool WillFirstRespond
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiScrollCtrlGetWillFirstRespond(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiScrollCtrlSetWillFirstRespond(ObjectPtr->ObjPtr, value);
         }
      }
      public int HScrollBar
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiScrollCtrlGetHScrollBar(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiScrollCtrlSetHScrollBar(ObjectPtr->ObjPtr, value);
         }
      }
      public int VScrollBar
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiScrollCtrlGetVScrollBar(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiScrollCtrlSetVScrollBar(ObjectPtr->ObjPtr, value);
         }
      }
      public bool ConstantThumbHeight
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiScrollCtrlGetConstantThumbHeight(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiScrollCtrlSetConstantThumbHeight(ObjectPtr->ObjPtr, value);
         }
      }
      public Point2I ChildMargin
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            Point2I outVal;
            InternalUnsafeMethods.GuiScrollCtrlGetChildMargin(ObjectPtr->ObjPtr, out outVal);
            return outVal;
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiScrollCtrlSetChildMargin(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}