using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiPopUpBackgroundCtrl : GuiControl
   {
      public GuiPopUpBackgroundCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiPopUpBackgroundCtrlCreateInstance());
      }

      public GuiPopUpBackgroundCtrl(uint pId) : base(pId)
      {
      }

      public GuiPopUpBackgroundCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiPopUpBackgroundCtrl(string pName) : base(pName)
      {
      }

      public GuiPopUpBackgroundCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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