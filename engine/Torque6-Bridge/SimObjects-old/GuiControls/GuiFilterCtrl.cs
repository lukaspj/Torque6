using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiFilterCtrl : GuiControl
   {
      
      public GuiFilterCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiFilterCtrlCreateInstance());
      }

      public GuiFilterCtrl(uint pId) : base(pId)
      {
      }

      public GuiFilterCtrl(string pName) : base(pName)
      {
      }

      public GuiFilterCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiFilterCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiFilterCtrl(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiFilterCtrlGetControlPoints(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiFilterCtrlSetControlPoints(IntPtr ctrl, int points);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiFilterCtrlCreateInstance();
      }
      
      #endregion

      #region Properties

      public int ControlPoints
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiFilterCtrlGetControlPoints(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiFilterCtrlSetControlPoints(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}