using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class DInputManager : InputManager
   {
      public DInputManager()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.DInputManagerCreateInstance());
      }

      public DInputManager(uint pId) : base(pId)
      {
      }

      public DInputManager(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public DInputManager(string pName) : base(pName)
      {
      }

      public DInputManager(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr DInputManagerCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}