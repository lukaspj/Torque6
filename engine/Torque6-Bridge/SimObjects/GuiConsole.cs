using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiConsole : GuiArrayCtrl
   {
      public GuiConsole()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiConsoleCreateInstance());
      }

      public GuiConsole(uint pId) : base(pId)
      {
      }

      public GuiConsole(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiConsole(string pName) : base(pName)
      {
      }

      public GuiConsole(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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