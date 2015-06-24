using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class ReferencedAssets : SimObject
   {
      public ReferencedAssets()
      {
         ObjectPtr = Sim.WrapObject(Internal.ReferencedAssetsCreateInstance());
      }

      public ReferencedAssets(uint pId) : base(pId)
      {
      }

      public ReferencedAssets(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public ReferencedAssets(string pName) : base(pName)
      {
      }

      public ReferencedAssets(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      #region Properties
      public string Path { get; set; }
      public string Extension { get; set; }
      public bool Recurse { get; set; }
      #endregion

      #region UnsafeNativeMethods

      new internal struct Internal
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ReferencedAssetsCreateInstance();
      }

      #endregion
   }
}