using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiGraphCtrl : GuiControl
   {
      
      public GuiGraphCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiGraphCtrlCreateInstance());
      }

      public GuiGraphCtrl(uint pId) : base(pId)
      {
      }

      public GuiGraphCtrl(string pName) : base(pName)
      {
      }

      public GuiGraphCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiGraphCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiGraphCtrl(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiGraphCtrlCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}