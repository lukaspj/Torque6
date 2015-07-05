using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiMessageVectorCtrl : GuiControl
   {
      public GuiMessageVectorCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiMessageVectorCtrlCreateInstance());
      }

      public GuiMessageVectorCtrl(uint pId) : base(pId)
      {
      }

      public GuiMessageVectorCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMessageVectorCtrl(string pName) : base(pName)
      {
      }

      public GuiMessageVectorCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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