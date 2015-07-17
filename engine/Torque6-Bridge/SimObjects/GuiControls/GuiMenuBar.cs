using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiMenuBar : GuiTickCtrl
   {
      
      public GuiMenuBar()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiMenuBarCreateInstance());
      }

      public GuiMenuBar(uint pId) : base(pId)
      {
      }

      public GuiMenuBar(string pName) : base(pName)
      {
      }

      public GuiMenuBar(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMenuBar(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMenuBar(SimObject pObj) : base(pObj)
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