using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiPopupTextListCtrl : GuiTextListCtrl
   {
      public GuiPopupTextListCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiPopupTextListCtrlCreateInstance());
      }

      public GuiPopupTextListCtrl(uint pId) : base(pId)
      {
      }

      public GuiPopupTextListCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiPopupTextListCtrl(string pName) : base(pName)
      {
      }

      public GuiPopupTextListCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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