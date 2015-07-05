using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiButtonCtrl : GuiButtonBaseCtrl
   {
      public GuiButtonCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiButtonCtrlCreateInstance());
      }

      public GuiButtonCtrl(uint pId) : base(pId)
      {
      }

      public GuiButtonCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiButtonCtrl(string pName) : base(pName)
      {
      }

      public GuiButtonCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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