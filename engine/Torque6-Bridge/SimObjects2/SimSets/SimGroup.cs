﻿using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.SimSets
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

      public SimGroup(string pName) : base(pName)
      {
      }

      public SimGroup(IntPtr pPtr)
         : base(pPtr)
      {
      }

      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimGroupCreateInstance();
      }

      #endregion
   }
}