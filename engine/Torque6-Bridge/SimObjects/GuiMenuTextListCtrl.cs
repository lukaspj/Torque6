using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiMenuTextListCtrl : GuiTextListCtrl
   {
      public GuiMenuTextListCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiMenuTextListCtrlCreateInstance());
      }

      public GuiMenuTextListCtrl(uint pId) : base(pId)
      {
      }

      public GuiMenuTextListCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMenuTextListCtrl(string pName) : base(pName)
      {
      }

      public GuiMenuTextListCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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