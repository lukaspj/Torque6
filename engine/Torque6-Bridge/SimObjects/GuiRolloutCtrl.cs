using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
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

      public GuiRolloutCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiRolloutCtrl(string pName) : base(pName)
      {
      }

      public GuiRolloutCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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