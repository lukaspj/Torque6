using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiMLTextCtrl : GuiControl
   {
      
      public GuiMLTextCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiMLTextCtrlCreateInstance());
      }

      public GuiMLTextCtrl(uint pId) : base(pId)
      {
      }

      public GuiMLTextCtrl(string pName) : base(pName)
      {
      }

      public GuiMLTextCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMLTextCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMLTextCtrl(SimObject pObj) : base(pObj)
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