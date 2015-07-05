using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiProgressCtrl : GuiTextCtrl
   {
      public GuiProgressCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiProgressCtrlCreateInstance());
      }

      public GuiProgressCtrl(uint pId) : base(pId)
      {
      }

      public GuiProgressCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiProgressCtrl(string pName) : base(pName)
      {
      }

      public GuiProgressCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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