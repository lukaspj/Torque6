using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class SimGroup : SimSet
   {
      public SimGroup()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.SimGroupCreateInstance());
      }

      public SimGroup(uint pId) : base(pId)
      {
      }

      public SimGroup(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public SimGroup(string pName) : base(pName)
      {
      }

      public SimGroup(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimGroupCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}