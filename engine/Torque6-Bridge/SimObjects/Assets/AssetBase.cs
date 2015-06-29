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
         internal static extern string AssetBaseGetAssetName(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseSetAssetName(IntPtr pObjectPtr, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseGetAssetDescription(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseSetAssetDescription(IntPtr pObjectPtr, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseGetAssetCategory(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseSetAssetCategory(IntPtr pObjectPtr, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseGetAutoUnload(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseSetAutoUnload(IntPtr pObjectPtr, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseGetInternal(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseSetInternal(IntPtr pObjectPtr, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseGetPrivate(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetBaseSetPrivate(IntPtr pObjectPtr, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetBaseRefreshAsset(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetBaseGetAssetId(IntPtr pObjectPtr);
      }

      #endregion

      #region Properties

      public string AssetName
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetBaseGetAssetName(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetBaseSetAssetName(ObjectPtr->ObjPtr, value);
         }
      }

      public string AssetDescription
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetBaseGetAssetDescription(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetBaseSetAssetDescription(ObjectPtr->ObjPtr, value);
         }
      }

      public string AssetCategory
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetBaseGetAssetCategory(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetBaseSetAssetCategory(ObjectPtr->ObjPtr, value);
         }
      }

      public bool AutoUnload
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetBaseGetAutoUnload(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetBaseSetAutoUnload(ObjectPtr->ObjPtr, value);
         }
      }

      public bool Internal
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetBaseGetInternal(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetBaseSetInternal(ObjectPtr->ObjPtr, value);
         }
      }

      public bool Private
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetBaseGetPrivate(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetBaseSetPrivate(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion

      #region Methods

      public void RefreshAsset()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetBaseRefreshAsset(ObjectPtr->ObjPtr);
      }

      public string GetAssetId()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetBaseGetAssetId(ObjectPtr->ObjPtr);
      }

      #endregion
   }
}