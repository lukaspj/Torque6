using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiPopUpMenuCtrl : GuiTextCtrl
   {
      public GuiPopUpMenuCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiPopUpMenuCtrlCreateInstance());
      }

      public GuiPopUpMenuCtrl(uint pId) : base(pId)
      {
      }

      public GuiPopUpMenuCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiPopUpMenuCtrl(string pName) : base(pName)
      {
      }

      public GuiPopUpMenuCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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