using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiAutoScrollCtrl : GuiTickCtrl
   {
      public GuiAutoScrollCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiAutoScrollCtrlCreateInstance());
      }

      public GuiAutoScrollCtrl(uint pId) : base(pId)
      {
      }

      public GuiAutoScrollCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiAutoScrollCtrl(string pName) : base(pName)
      {
      }

      public GuiAutoScrollCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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