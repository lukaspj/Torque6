using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiControl : SimGroup
   {
      public GuiControl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiControlCreateInstance());
      }

      public GuiControl(uint pId) : base(pId)
      {
      }

      public GuiControl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiControl(string pName) : base(pName)
      {
      }

      public GuiControl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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