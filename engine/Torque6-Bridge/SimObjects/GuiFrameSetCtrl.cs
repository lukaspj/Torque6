using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiFrameSetCtrl : GuiControl
   {
      public GuiFrameSetCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiFrameSetCtrlCreateInstance());
      }

      public GuiFrameSetCtrl(uint pId) : base(pId)
      {
      }

      public GuiFrameSetCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiFrameSetCtrl(string pName) : base(pName)
      {
      }

      public GuiFrameSetCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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