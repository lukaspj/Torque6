using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiTextCtrl : GuiControl
   {
      
      public GuiTextCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTextCtrlCreateInstance());
      }

      public GuiTextCtrl(uint pId) : base(pId)
      {
      }

      public GuiTextCtrl(string pName) : base(pName)
      {
      }

      public GuiTextCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTextCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTextCtrl(SimObject pObj) : base(pObj)
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