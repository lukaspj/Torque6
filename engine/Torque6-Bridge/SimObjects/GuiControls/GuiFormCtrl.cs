using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiFormCtrl : GuiControl
   {
      
      public GuiFormCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiFormCtrlCreateInstance());
      }

      public GuiFormCtrl(uint pId) : base(pId)
      {
      }

      public GuiFormCtrl(string pName) : base(pName)
      {
      }

      public GuiFormCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiFormCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiFormCtrl(SimObject pObj) : base(pObj)
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