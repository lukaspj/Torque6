using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiTickCtrl : GuiControl
   {
      
      public GuiTickCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTickCtrlCreateInstance());
      }

      public GuiTickCtrl(uint pId) : base(pId)
      {
      }

      public GuiTickCtrl(string pName) : base(pName)
      {
      }

      public GuiTickCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTickCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTickCtrl(SimObject pObj) : base(pObj)
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