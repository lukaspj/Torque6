using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiButtonBaseCtrl : GuiControl
   {
      
      public GuiButtonBaseCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiButtonBaseCtrlCreateInstance());
      }

      public GuiButtonBaseCtrl(uint pId) : base(pId)
      {
      }

      public GuiButtonBaseCtrl(string pName) : base(pName)
      {
      }

      public GuiButtonBaseCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiButtonBaseCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiButtonBaseCtrl(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string GuiButtonBaseCtrlGetText(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiButtonBaseCtrlSetText(IntPtr ctrl, string text);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string GuiButtonBaseCtrlGetTextID(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiButtonBaseCtrlSetTextID(IntPtr ctrl, string textId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiButtonBaseCtrlGetGroupNum(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiButtonBaseCtrlSetGroupNum(IntPtr ctrl, int groupNum);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiButtonBaseCtrlGetButtonType(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiButtonBaseCtrlSetButtonType(IntPtr ctrl, int buttonType);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiButtonBaseCtrlGetUseMouseEvents(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiButtonBaseCtrlSetUseMouseEvents(IntPtr ctrl, bool useMouseEvents);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiButtonBaseCtrlCreateInstance();
      }
      
      #endregion

      #region Properties

      public string Text
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiButtonBaseCtrlGetText(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiButtonBaseCtrlSetText(ObjectPtr->ObjPtr, value);
         }
      }
      public string TextID
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiButtonBaseCtrlGetTextID(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiButtonBaseCtrlSetTextID(ObjectPtr->ObjPtr, value);
         }
      }
      public int GroupNum
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiButtonBaseCtrlGetGroupNum(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiButtonBaseCtrlSetGroupNum(ObjectPtr->ObjPtr, value);
         }
      }
      public int ButtonType
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiButtonBaseCtrlGetButtonType(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiButtonBaseCtrlSetButtonType(ObjectPtr->ObjPtr, value);
         }
      }
      public bool UseMouseEvents
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiButtonBaseCtrlGetUseMouseEvents(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiButtonBaseCtrlSetUseMouseEvents(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}