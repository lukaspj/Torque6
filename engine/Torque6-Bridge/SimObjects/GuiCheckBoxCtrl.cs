using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiCheckBoxCtrl : GuiButtonBaseCtrl
   {
      public GuiCheckBoxCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiCheckBoxCtrlCreateInstance());
      }

      public GuiCheckBoxCtrl(uint pId) : base(pId)
      {
      }

      public GuiCheckBoxCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiCheckBoxCtrl(string pName) : base(pName)
      {
      }

      public GuiCheckBoxCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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