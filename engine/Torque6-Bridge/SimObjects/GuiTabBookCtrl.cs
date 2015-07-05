using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiTabBookCtrl : GuiControl
   {
      public GuiTabBookCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTabBookCtrlCreateInstance());
      }

      public GuiTabBookCtrl(uint pId) : base(pId)
      {
      }

      public GuiTabBookCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTabBookCtrl(string pName) : base(pName)
      {
      }

      public GuiTabBookCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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