using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiPaneControl : GuiControl
   {
      
      public GuiPaneControl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiPaneControlCreateInstance());
      }

      public GuiPaneControl(uint pId) : base(pId)
      {
      }

      public GuiPaneControl(string pName) : base(pName)
      {
      }

      public GuiPaneControl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiPaneControl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiPaneControl(SimObject pObj) : base(pObj)
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