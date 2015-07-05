using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiConsoleTextCtrl : GuiControl
   {
      public GuiConsoleTextCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiConsoleTextCtrlCreateInstance());
      }

      public GuiConsoleTextCtrl(uint pId) : base(pId)
      {
      }

      public GuiConsoleTextCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiConsoleTextCtrl(string pName) : base(pName)
      {
      }

      public GuiConsoleTextCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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