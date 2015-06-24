using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class DeclaredAssets : SimObject
   {
      public DeclaredAssets()
      {
         ObjectPtr = Sim.WrapObject(Internal.DeclaredAssetsCreateInstance());
      }

      public DeclaredAssets(uint pId) : base(pId)
      {
      }

      public DeclaredAssets(string pName) : base(pName)
      {
      }

      public DeclaredAssets(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public DeclaredAssets(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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
         internal static extern IntPtr DeclaredAssetsCreateInstance();
      }

      #endregion
   }
}
