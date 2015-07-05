using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiGridControl : GuiControl
   {
      public GuiGridControl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiGridControlCreateInstance());
      }

      public GuiGridControl(uint pId) : base(pId)
      {
      }

      public GuiGridControl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiGridControl(string pName) : base(pName)
      {
      }

      public GuiGridControl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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