using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiGraphCtrl : GuiControl
   {
      public GuiGraphCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiGraphCtrlCreateInstance());
      }

      public GuiGraphCtrl(uint pId) : base(pId)
      {
      }

      public GuiGraphCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiGraphCtrl(string pName) : base(pName)
      {
      }

      public GuiGraphCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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