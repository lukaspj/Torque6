using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiSeparatorCtrl : GuiControl
   {
      
      public GuiSeparatorCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiSeparatorCtrlCreateInstance());
      }

      public GuiSeparatorCtrl(uint pId) : base(pId)
      {
      }

      public GuiSeparatorCtrl(string pName) : base(pName)
      {
      }

      public GuiSeparatorCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiSeparatorCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiSeparatorCtrl(SimObject pObj) : base(pObj)
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