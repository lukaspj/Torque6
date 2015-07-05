using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiBubbleTextCtrl : GuiTextCtrl
   {
      public GuiBubbleTextCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiBubbleTextCtrlCreateInstance());
      }

      public GuiBubbleTextCtrl(uint pId) : base(pId)
      {
      }

      public GuiBubbleTextCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiBubbleTextCtrl(string pName) : base(pName)
      {
      }

      public GuiBubbleTextCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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