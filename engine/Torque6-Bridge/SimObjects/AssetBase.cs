using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class AssetBase : SimObject
   {
      public AssetBase()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AssetBaseCreateInstance());
      }

      public AssetBase(uint pId) : base(pId)
      {
      }

      public AssetBase(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public AssetBase(string pName) : base(pName)
      {
      }

      public AssetBase(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetBaseCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseGetAssetName(IntPtr assetBase);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetBaseSetAssetName(IntPtr assetBase, string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseGetAssetDescription(IntPtr assetBase);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetBaseSetAssetDescription(IntPtr assetBase, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseGetAssetCategory(IntPtr assetBase);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetBaseSetAssetCategory(IntPtr assetBase, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseGetAssetAutoUnload(IntPtr assetBase);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetBaseSetAssetAutoUnload(IntPtr assetBase, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseGetAssetInternal(IntPtr assetBase);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetBaseSetAssetInternal(IntPtr assetBase, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseGetAssetPrivate(IntPtr assetBase);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetBaseRefreshAsset(IntPtr assetBase);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseGetAssetId(IntPtr assetBase);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void GetAssetName()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseGetAssetName(ObjectPtr->ObjPtr);
      }

      public void SetAssetName(string name)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseSetAssetName(ObjectPtr->ObjPtr, name);
      }

      public void GetAssetDescription()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseGetAssetDescription(ObjectPtr->ObjPtr);
      }

      public void SetAssetDescription(string val)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseSetAssetDescription(ObjectPtr->ObjPtr, val);
      }

      public void GetAssetCategory()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseGetAssetCategory(ObjectPtr->ObjPtr);
      }

      public void SetAssetCategory(string val)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseSetAssetCategory(ObjectPtr->ObjPtr, val);
      }

      public void GetAssetAutoUnload()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseGetAssetAutoUnload(ObjectPtr->ObjPtr);
      }

      public void SetAssetAutoUnload(bool val)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseSetAssetAutoUnload(ObjectPtr->ObjPtr, val);
      }

      public void GetAssetInternal()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseGetAssetInternal(ObjectPtr->ObjPtr);
      }

      public void SetAssetInternal(bool val)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseSetAssetInternal(ObjectPtr->ObjPtr, val);
      }

      public void GetAssetPrivate()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseGetAssetPrivate(ObjectPtr->ObjPtr);
      }

      public void RefreshAsset()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseRefreshAsset(ObjectPtr->ObjPtr);
      }

      public void GetAssetId()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseGetAssetId(ObjectPtr->ObjPtr);
      }

      #endregion
   }
}