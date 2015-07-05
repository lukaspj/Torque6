using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiImageButtonCtrl : GuiButtonCtrl
   {
      public GuiImageButtonCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiImageButtonCtrlCreateInstance());
      }

      public GuiImageButtonCtrl(uint pId) : base(pId)
      {
      }

      public GuiImageButtonCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiImageButtonCtrl(string pName) : base(pName)
      {
      }

      public GuiImageButtonCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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