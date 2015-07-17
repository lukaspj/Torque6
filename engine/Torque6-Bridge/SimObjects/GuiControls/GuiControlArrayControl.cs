using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiControlArrayControl : GuiControl
   {
      
      public GuiControlArrayControl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiControlArrayControlCreateInstance());
      }

      public GuiControlArrayControl(uint pId) : base(pId)
      {
      }

      public GuiControlArrayControl(string pName) : base(pName)
      {
      }

      public GuiControlArrayControl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiControlArrayControl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiControlArrayControl(SimObject pObj) : base(pObj)
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