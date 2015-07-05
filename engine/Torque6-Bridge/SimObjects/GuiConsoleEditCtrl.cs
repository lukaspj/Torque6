using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiConsoleEditCtrl : GuiTextEditCtrl
   {
      public GuiConsoleEditCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiConsoleEditCtrlCreateInstance());
      }

      public GuiConsoleEditCtrl(uint pId) : base(pId)
      {
      }

      public GuiConsoleEditCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiConsoleEditCtrl(string pName) : base(pName)
      {
      }

      public GuiConsoleEditCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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