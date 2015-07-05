using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiBitmapCtrl : GuiControl
   {
      public GuiBitmapCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiBitmapCtrlCreateInstance());
      }

      public GuiBitmapCtrl(uint pId) : base(pId)
      {
      }

      public GuiBitmapCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiBitmapCtrl(string pName) : base(pName)
      {
      }

      public GuiBitmapCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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