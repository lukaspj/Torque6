using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.GuiMessageVectorCtrl
{
   public unsafe class SimObjects.GuiControls : GuiControl
   {
      public SimObjects.GuiControls()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.SimObjects.GuiControlsCreateInstance());
      }

      public SimObjects.GuiControls(uint pId) : base(pId)
      {
      }

      public SimObjects.GuiControls(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public SimObjects.GuiControls(string pName) : base(pName)
      {
      }

      public SimObjects.GuiControls(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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