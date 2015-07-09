using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiListBoxCtrl : GuiControl
   {
      public GuiListBoxCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiListBoxCtrlCreateInstance());
      }

      public GuiListBoxCtrl(uint pId) : base(pId)
      {
      }

      public GuiListBoxCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiListBoxCtrl(string pName) : base(pName)
      {
      }

      public GuiListBoxCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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