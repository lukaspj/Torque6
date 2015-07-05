using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiTextListCtrl : GuiArrayCtrl
   {
      public GuiTextListCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTextListCtrlCreateInstance());
      }

      public GuiTextListCtrl(uint pId) : base(pId)
      {
      }

      public GuiTextListCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTextListCtrl(string pName) : base(pName)
      {
      }

      public GuiTextListCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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