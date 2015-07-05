using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiPopUpMenuCtrlEx : GuiTextCtrl
   {
      public GuiPopUpMenuCtrlEx()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiPopUpMenuCtrlExCreateInstance());
      }

      public GuiPopUpMenuCtrlEx(uint pId) : base(pId)
      {
      }

      public GuiPopUpMenuCtrlEx(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiPopUpMenuCtrlEx(string pName) : base(pName)
      {
      }

      public GuiPopUpMenuCtrlEx(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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