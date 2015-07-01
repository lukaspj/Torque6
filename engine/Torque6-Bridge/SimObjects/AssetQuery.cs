using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class AssetQuery : SimObject
   {
      public AssetQuery()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AssetQueryCreateInstance());
      }

      public AssetQuery(uint pId) : base(pId)
      {
      }

      public AssetQuery(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public AssetQuery(string pName) : base(pName)
      {
      }

      public AssetQuery(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetQueryCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetQueryClear(IntPtr assetQuery);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetQuerySet(IntPtr assetQuery, IntPtr setAssetQuery);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetQueryGetCount(IntPtr assetQuery);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetQueryGetAsset(IntPtr assetQuery, int resultIndex);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void Clear()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetQueryClear(ObjectPtr->ObjPtr);
      }

      public void Set(AssetQuery setAssetQuery)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetQuerySet(ObjectPtr->ObjPtr, setAssetQuery.ObjectPtr->ObjPtr);
      }

      public void GetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetQueryGetCount(ObjectPtr->ObjPtr);
      }

      public void GetAsset(int resultIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetQueryGetAsset(ObjectPtr->ObjPtr, resultIndex);
      }

      #endregion
   }
}