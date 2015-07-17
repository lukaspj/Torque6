using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiDynamicCtrlArrayControl : GuiControl
   {
      
      public GuiDynamicCtrlArrayControl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiDynamicCtrlArrayControlCreateInstance());
      }

      public GuiDynamicCtrlArrayControl(uint pId) : base(pId)
      {
      }

      public GuiDynamicCtrlArrayControl(string pName) : base(pName)
      {
      }

      public GuiDynamicCtrlArrayControl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiDynamicCtrlArrayControl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiDynamicCtrlArrayControl(SimObject pObj) : base(pObj)
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