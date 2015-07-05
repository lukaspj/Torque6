using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiTabPageCtrl : GuiTextCtrl
   {
      public GuiTabPageCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTabPageCtrlCreateInstance());
      }

      public GuiTabPageCtrl(uint pId) : base(pId)
      {
      }

      public GuiTabPageCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTabPageCtrl(string pName) : base(pName)
      {
      }

      public GuiTabPageCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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