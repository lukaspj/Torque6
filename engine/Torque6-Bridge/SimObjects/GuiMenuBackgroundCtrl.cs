using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiMenuBackgroundCtrl : GuiControl
   {
      public GuiMenuBackgroundCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiMenuBackgroundCtrlCreateInstance());
      }

      public GuiMenuBackgroundCtrl(uint pId) : base(pId)
      {
      }

      public GuiMenuBackgroundCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMenuBackgroundCtrl(string pName) : base(pName)
      {
      }

      public GuiMenuBackgroundCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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