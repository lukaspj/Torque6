using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiEditCtrl : GuiControl
   {
      
      public GuiEditCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiEditCtrlCreateInstance());
      }

      public GuiEditCtrl(uint pId) : base(pId)
      {
      }

      public GuiEditCtrl(string pName) : base(pName)
      {
      }

      public GuiEditCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiEditCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiEditCtrl(SimObject pObj) : base(pObj)
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