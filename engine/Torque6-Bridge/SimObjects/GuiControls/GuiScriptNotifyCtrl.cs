using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiScriptNotifyCtrl : GuiControl
   {
      
      public GuiScriptNotifyCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiScriptNotifyCtrlCreateInstance());
      }

      public GuiScriptNotifyCtrl(uint pId) : base(pId)
      {
      }

      public GuiScriptNotifyCtrl(string pName) : base(pName)
      {
      }

      public GuiScriptNotifyCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiScriptNotifyCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiScriptNotifyCtrl(SimObject pObj) : base(pObj)
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