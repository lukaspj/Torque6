using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiPopupTextListCtrlEx : GuiTextListCtrl
   {
      public GuiPopupTextListCtrlEx()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiPopupTextListCtrlExCreateInstance());
      }

      public GuiPopupTextListCtrlEx(uint pId) : base(pId)
      {
      }

      public GuiPopupTextListCtrlEx(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiPopupTextListCtrlEx(string pName) : base(pName)
      {
      }

      public GuiPopupTextListCtrlEx(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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