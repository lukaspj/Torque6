using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiToolboxButtonCtrl : GuiButtonCtrl
   {
      public GuiToolboxButtonCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiToolboxButtonCtrlCreateInstance());
      }

      public GuiToolboxButtonCtrl(uint pId) : base(pId)
      {
      }

      public GuiToolboxButtonCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiToolboxButtonCtrl(string pName) : base(pName)
      {
      }

      public GuiToolboxButtonCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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