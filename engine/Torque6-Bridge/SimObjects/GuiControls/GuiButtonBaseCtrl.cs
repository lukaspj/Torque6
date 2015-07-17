using System;
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
         
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}