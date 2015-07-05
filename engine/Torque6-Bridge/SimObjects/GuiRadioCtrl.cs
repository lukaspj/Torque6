using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiRadioCtrl : GuiCheckBoxCtrl
   {
      public GuiRadioCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiRadioCtrlCreateInstance());
      }

      public GuiRadioCtrl(uint pId) : base(pId)
      {
      }

      public GuiRadioCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiRadioCtrl(string pName) : base(pName)
      {
      }

      public GuiRadioCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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