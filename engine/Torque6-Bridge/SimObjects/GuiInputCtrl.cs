using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInputCtrl : GuiControl
   {
      public GuiInputCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInputCtrlCreateInstance());
      }

      public GuiInputCtrl(uint pId) : base(pId)
      {
      }

      public GuiInputCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInputCtrl(string pName) : base(pName)
      {
      }

      public GuiInputCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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