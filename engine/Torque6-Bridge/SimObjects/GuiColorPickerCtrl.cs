using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiColorPickerCtrl : GuiControl
   {
      public GuiColorPickerCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiColorPickerCtrlCreateInstance());
      }

      public GuiColorPickerCtrl(uint pId) : base(pId)
      {
      }

      public GuiColorPickerCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiColorPickerCtrl(string pName) : base(pName)
      {
      }

      public GuiColorPickerCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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