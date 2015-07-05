using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiBitmapButtonTextCtrl : GuiBitmapButtonCtrl
   {
      public GuiBitmapButtonTextCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiBitmapButtonTextCtrlCreateInstance());
      }

      public GuiBitmapButtonTextCtrl(uint pId) : base(pId)
      {
      }

      public GuiBitmapButtonTextCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiBitmapButtonTextCtrl(string pName) : base(pName)
      {
      }

      public GuiBitmapButtonTextCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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