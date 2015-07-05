using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiBackgroundCtrl : GuiControl
   {
      public GuiBackgroundCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiBackgroundCtrlCreateInstance());
      }

      public GuiBackgroundCtrl(uint pId) : base(pId)
      {
      }

      public GuiBackgroundCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiBackgroundCtrl(string pName) : base(pName)
      {
      }

      public GuiBackgroundCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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