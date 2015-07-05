using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiMLTextEditCtrl : GuiMLTextCtrl
   {
      public GuiMLTextEditCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiMLTextEditCtrlCreateInstance());
      }

      public GuiMLTextEditCtrl(uint pId) : base(pId)
      {
      }

      public GuiMLTextEditCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMLTextEditCtrl(string pName) : base(pName)
      {
      }

      public GuiMLTextEditCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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