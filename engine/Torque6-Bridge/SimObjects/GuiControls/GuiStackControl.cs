using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiStackControl : GuiControl
   {
      
      public GuiStackControl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiStackControlCreateInstance());
      }

      public GuiStackControl(uint pId) : base(pId)
      {
      }

      public GuiStackControl(string pName) : base(pName)
      {
      }

      public GuiStackControl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiStackControl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiStackControl(SimObject pObj) : base(pObj)
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