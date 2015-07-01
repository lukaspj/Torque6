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

      #region Properties

      public int Count
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetQueryGetCount(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetQuerySetCount(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion

      #region UnsafeNativeMethods

      internal new struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetQueryCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetQueryClear(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetQuerySet(IntPtr pObjectPtr, IntPtr pAssetQuery);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetQueryGetCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetQuerySetCount(IntPtr pObjectPtr, int val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetQueryGetAsset(IntPtr pObjectPtr, int resultIndex);
      }

      #endregion

      #region Methods

      public void Clear()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetQueryClear(ObjectPtr->ObjPtr);
      }

      public void Set(AssetQuery assetQuery)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetQuerySet(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr);
      }

      public string GetAsset(int resultIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetQueryGetAsset(ObjectPtr->ObjPtr, resultIndex);
      }

      #endregion
   }
}