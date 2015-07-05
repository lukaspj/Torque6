using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiSubmenuBackgroundCtrl : GuiMenuBackgroundCtrl
   {
      public GuiSubmenuBackgroundCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiSubmenuBackgroundCtrlCreateInstance());
      }

      public GuiSubmenuBackgroundCtrl(uint pId) : base(pId)
      {
      }

      public GuiSubmenuBackgroundCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiSubmenuBackgroundCtrl(string pName) : base(pName)
      {
      }

      public GuiSubmenuBackgroundCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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