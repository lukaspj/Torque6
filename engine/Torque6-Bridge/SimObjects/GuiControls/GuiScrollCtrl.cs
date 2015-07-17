using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiScrollCtrl : GuiControl
   {
      
      public GuiScrollCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiScrollCtrlCreateInstance());
      }

      public GuiScrollCtrl(uint pId) : base(pId)
      {
      }

      public GuiScrollCtrl(string pName) : base(pName)
      {
      }

      public GuiScrollCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiScrollCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiScrollCtrl(SimObject pObj) : base(pObj)
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