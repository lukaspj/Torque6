using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class AssetTagsManifest : SimObject
   {
      public AssetTagsManifest()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AssetTagsManifestCreateInstance());
      }

      public AssetTagsManifest(uint pId) : base(pId)
      {
      }

      public AssetTagsManifest(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public AssetTagsManifest(string pName) : base(pName)
      {
      }

      public AssetTagsManifest(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      #region UnsafeNativeMethods

      internal new struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetTagsManifestCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetTagsManifestCreateTag(IntPtr pObjectPtr, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestRenameTag(IntPtr pObjectPtr, string oldTagName,
            string newTagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestDeleteTag(IntPtr pObjectPtr, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestIsTag(IntPtr pObjectPtr, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetTagsManifestGetTagCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetTagsManifestGetTag(IntPtr pObjectPtr, int tagIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetTagsManifestGetAssetTagCount(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetTagsManifestGetAssetTag(IntPtr pObjectPtr, string assetId, int tagIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestTag(IntPtr pObjectPtr, string assetId, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestUntag(IntPtr pObjectPtr, string assetId, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestHasTag(IntPtr pObjectPtr, string assetId, string tagName);
      }

      #endregion

      #region Properties

      #endregion

      #region Methods

      public void CreateTag(string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestCreateTag(ObjectPtr->ObjPtr, tagName);
      }

      public bool RenameTag(string oldTagName, string newTagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestRenameTag(ObjectPtr->ObjPtr, oldTagName, newTagName);
      }

      public bool DeleteTag(string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestDeleteTag(ObjectPtr->ObjPtr, tagName);
      }

      public bool IsTag(string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestIsTag(ObjectPtr->ObjPtr, tagName);
      }

      public int GetTagCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestGetTagCount(ObjectPtr->ObjPtr);
      }

      public string GetTag(int tagIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestGetTag(ObjectPtr->ObjPtr, tagIndex);
      }

      public int GetAssetTagCount(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestGetAssetTagCount(ObjectPtr->ObjPtr, assetId);
      }

      public string GetAssetTag(string assetId, int tagIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestGetAssetTag(ObjectPtr->ObjPtr, assetId, tagIndex);
      }

      public bool Tag(string assetId, string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestTag(ObjectPtr->ObjPtr, assetId, tagName);
      }

      public bool Untag(string assetId, string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestUntag(ObjectPtr->ObjPtr, assetId, tagName);
      }

      public bool HasTag(string assetId, string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetTagsManifestHasTag(ObjectPtr->ObjPtr, assetId, tagName);
      }

      #endregion
   }
}