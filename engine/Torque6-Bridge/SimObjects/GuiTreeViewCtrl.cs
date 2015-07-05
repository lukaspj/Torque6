using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiTreeViewCtrl : GuiArrayCtrl
   {
      public GuiTreeViewCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTreeViewCtrlCreateInstance());
      }

      public GuiTreeViewCtrl(uint pId) : base(pId)
      {
      }

      public GuiTreeViewCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTreeViewCtrl(string pName) : base(pName)
      {
      }

      public GuiTreeViewCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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