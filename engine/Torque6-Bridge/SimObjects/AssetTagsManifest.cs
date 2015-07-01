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

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetTagsManifestCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetTagsManifestCreateTag(IntPtr assetTagsManifest, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestRenameTag(IntPtr assetTagsManifest, string oldTagName, string newTagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestDeleteTag(IntPtr assetTagsManifest, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestIsTag(IntPtr assetTagsManifest, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetTagsManifestGetTagCount(IntPtr assetTagsManifest);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetTagsManifestGetTag(IntPtr assetTagsManifest, int tagIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetTagsManifestGetAssetTagCount(IntPtr assetTagsManifest, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetTagsManifestGetAssetTag(IntPtr assetTagsManifest, string assetId, int tagIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestTag(IntPtr assetTagsManifest, string assetId, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestUntag(IntPtr assetTagsManifest, string assetId, string tagName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetTagsManifestHasTag(IntPtr assetTagsManifest, string assetId, string tagName);


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

      public void RenameTag(string oldTagName, string newTagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestRenameTag(ObjectPtr->ObjPtr, oldTagName, newTagName);
      }

      public void DeleteTag(string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestDeleteTag(ObjectPtr->ObjPtr, tagName);
      }

      public void IsTag(string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestIsTag(ObjectPtr->ObjPtr, tagName);
      }

      public void GetTagCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestGetTagCount(ObjectPtr->ObjPtr);
      }

      public void GetTag(int tagIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestGetTag(ObjectPtr->ObjPtr, tagIndex);
      }

      public void GetAssetTagCount(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestGetAssetTagCount(ObjectPtr->ObjPtr, assetId);
      }

      public void GetAssetTag(string assetId, int tagIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestGetAssetTag(ObjectPtr->ObjPtr, assetId, tagIndex);
      }

      public void Tag(string assetId, string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestTag(ObjectPtr->ObjPtr, assetId, tagName);
      }

      public void Untag(string assetId, string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestUntag(ObjectPtr->ObjPtr, assetId, tagName);
      }

      public void HasTag(string assetId, string tagName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetTagsManifestHasTag(ObjectPtr->ObjPtr, assetId, tagName);
      }

      #endregion
   }
}