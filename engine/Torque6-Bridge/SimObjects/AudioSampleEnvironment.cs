using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class AudioSampleEnvironment : SimDataBlock
   {
      public AudioSampleEnvironment()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AudioSampleEnvironmentCreateInstance());
      }

      public AudioSampleEnvironment(uint pId) : base(pId)
      {
      }

      public AudioSampleEnvironment(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public AudioSampleEnvironment(string pName) : base(pName)
      {
      }

      public AudioSampleEnvironment(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AudioSampleEnvironmentCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}