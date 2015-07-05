using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiSliderCtrl : GuiControl
   {
      public GuiSliderCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiSliderCtrlCreateInstance());
      }

      public GuiSliderCtrl(uint pId) : base(pId)
      {
      }

      public GuiSliderCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiSliderCtrl(string pName) : base(pName)
      {
      }

      public GuiSliderCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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