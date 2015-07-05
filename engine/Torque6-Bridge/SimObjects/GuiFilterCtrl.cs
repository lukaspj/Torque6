using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiFilterCtrl : GuiControl
   {
      public GuiFilterCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiFilterCtrlCreateInstance());
      }

      public GuiFilterCtrl(uint pId) : base(pId)
      {
      }

      public GuiFilterCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiFilterCtrl(string pName) : base(pName)
      {
      }

      public GuiFilterCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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