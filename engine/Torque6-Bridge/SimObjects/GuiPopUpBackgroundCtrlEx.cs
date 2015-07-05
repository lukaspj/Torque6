using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiPopUpBackgroundCtrlEx : GuiControl
   {
      public GuiPopUpBackgroundCtrlEx()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiPopUpBackgroundCtrlExCreateInstance());
      }

      public GuiPopUpBackgroundCtrlEx(uint pId) : base(pId)
      {
      }

      public GuiPopUpBackgroundCtrlEx(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiPopUpBackgroundCtrlEx(string pName) : base(pName)
      {
      }

      public GuiPopUpBackgroundCtrlEx(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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