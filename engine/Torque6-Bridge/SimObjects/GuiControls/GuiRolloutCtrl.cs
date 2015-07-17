using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiRolloutCtrl : GuiTickCtrl
   {
      
      public GuiRolloutCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiRolloutCtrlCreateInstance());
      }

      public GuiRolloutCtrl(uint pId) : base(pId)
      {
      }

      public GuiRolloutCtrl(string pName) : base(pName)
      {
      }

      public GuiRolloutCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiRolloutCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiRolloutCtrl(SimObject pObj) : base(pObj)
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