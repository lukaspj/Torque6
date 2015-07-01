using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class MeshAsset : AssetBase
   {
      public MeshAsset()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.MeshAssetCreateInstance());
      }

      public MeshAsset(uint pId) : base(pId)
      {
      }

      public MeshAsset(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public MeshAsset(string pName) : base(pName)
      {
      }

      public MeshAsset(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MeshAssetGetMeshFile(IntPtr meshAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MeshAssetSetMeshFile(IntPtr meshAsset, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr MeshAssetCreateInstance();


      }
      #endregion

      #region Properties

      public string MeshFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.MeshAssetGetMeshFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.MeshAssetSetMeshFile(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion
      
      #region Methods

      #endregion
   }
}