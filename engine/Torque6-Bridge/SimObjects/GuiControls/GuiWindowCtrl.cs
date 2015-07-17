using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiWindowCtrl : GuiTextCtrl
   {
      
      public GuiWindowCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiWindowCtrlCreateInstance());
      }

      public GuiWindowCtrl(uint pId) : base(pId)
      {
      }

      public GuiWindowCtrl(string pName) : base(pName)
      {
      }

      public GuiWindowCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiWindowCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiWindowCtrl(SimObject pObj) : base(pObj)
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