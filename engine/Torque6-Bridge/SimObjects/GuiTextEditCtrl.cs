using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiTextEditCtrl : GuiTextCtrl
   {
      public GuiTextEditCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTextEditCtrlCreateInstance());
      }

      public GuiTextEditCtrl(uint pId) : base(pId)
      {
      }

      public GuiTextEditCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTextEditCtrl(string pName) : base(pName)
      {
      }

      public GuiTextEditCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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