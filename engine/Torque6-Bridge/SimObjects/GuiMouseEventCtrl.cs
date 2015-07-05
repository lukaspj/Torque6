using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiMouseEventCtrl : GuiControl
   {
      public GuiMouseEventCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiMouseEventCtrlCreateInstance());
      }

      public GuiMouseEventCtrl(uint pId) : base(pId)
      {
      }

      public GuiMouseEventCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMouseEventCtrl(string pName) : base(pName)
      {
      }

      public GuiMouseEventCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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