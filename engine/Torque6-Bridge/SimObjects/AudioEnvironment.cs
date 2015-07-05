using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class AudioEnvironment : SimDataBlock
   {
      public AudioEnvironment()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AudioEnvironmentCreateInstance());
      }

      public AudioEnvironment(uint pId) : base(pId)
      {
      }

      public AudioEnvironment(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public AudioEnvironment(string pName) : base(pName)
      {
      }

      public AudioEnvironment(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AudioEnvironmentCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}