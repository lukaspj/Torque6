using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiBitmapButtonCtrl : GuiButtonCtrl
   {
      public GuiBitmapButtonCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiBitmapButtonCtrlCreateInstance());
      }

      public GuiBitmapButtonCtrl(uint pId) : base(pId)
      {
      }

      public GuiBitmapButtonCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiBitmapButtonCtrl(string pName) : base(pName)
      {
      }

      public GuiBitmapButtonCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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