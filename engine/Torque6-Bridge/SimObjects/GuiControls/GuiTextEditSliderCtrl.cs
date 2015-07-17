using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiTextEditSliderCtrl : GuiTextEditCtrl
   {
      
      public GuiTextEditSliderCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTextEditSliderCtrlCreateInstance());
      }

      public GuiTextEditSliderCtrl(uint pId) : base(pId)
      {
      }

      public GuiTextEditSliderCtrl(string pName) : base(pName)
      {
      }

      public GuiTextEditSliderCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTextEditSliderCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTextEditSliderCtrl(SimObject pObj) : base(pObj)
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