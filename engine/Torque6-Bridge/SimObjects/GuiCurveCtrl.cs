using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiCurveCtrl : GuiControl
   {
      public GuiCurveCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiCurveCtrlCreateInstance());
      }

      public GuiCurveCtrl(uint pId) : base(pId)
      {
      }

      public GuiCurveCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiCurveCtrl(string pName) : base(pName)
      {
      }

      public GuiCurveCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}