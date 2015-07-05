using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiIconButtonCtrl : GuiButtonCtrl
   {
      public GuiIconButtonCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiIconButtonCtrlCreateInstance());
      }

      public GuiIconButtonCtrl(uint pId) : base(pId)
      {
      }

      public GuiIconButtonCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiIconButtonCtrl(string pName) : base(pName)
      {
      }

      public GuiIconButtonCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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