using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiSpriteCtrl : GuiControl
   {
      public GuiSpriteCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiSpriteCtrlCreateInstance());
      }

      public GuiSpriteCtrl(uint pId) : base(pId)
      {
      }

      public GuiSpriteCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiSpriteCtrl(string pName) : base(pName)
      {
      }

      public GuiSpriteCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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