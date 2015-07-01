using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class AssetManager : SimObject
   {
      public AssetManager()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AssetManagerCreateInstance());
      }

      public AssetManager(uint pId) : base(pId)
      {
      }

      public AssetManager(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public AssetManager(string pName) : base(pName)
      {
      }

      public AssetManager(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      #region UnsafeNativeMethods

      internal new struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetManagerCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetEchoInfo(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerSetEchoInfo(IntPtr pObjectPtr, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetIgnoreAutoUnload(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerSetIgnoreAutoUnload(IntPtr pObjectPtr, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerCompileReferencedAssets(IntPtr pObjectPtr,
            ModuleDefinition moduleDefinition);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerAddModuleDeclaredAssets(IntPtr pObjectPtr,
            ModuleDefinition moduleDefinition);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerAddDeclaredAsset(IntPtr pObjectPtr, IntPtr moduleDefinition,
            string assetFilePath);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerAddPrivateAsset(IntPtr pObjectPtr, IntPtr assetObject);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRemoveDeclaredAssets(IntPtr pObjectPtr,
            ModuleDefinition moduleDefinition);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRemoveDeclaredAsset(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetName(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetDescription(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetCategory(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetType(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetFilePath(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetPath(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetManagerGetAssetModule(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsAssetInternal(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsAssetPrivate(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsAssetAutoUnload(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsAssetLoaded(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsDeclaredAsset(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsReferencedAsset(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRenameDeclaredAsset(IntPtr pObjectPtr, string assetIdFrom,
            string assetIdTo);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRenameReferencedAsset(IntPtr pObjectPtr, string assetIdFrom,
            string assetIdTo);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerAcquireAsset(IntPtr pObjectPtr, string assetId, bool asPrivate);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerReleaseAsset(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerPurgeAssets(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerDeleteAsset(IntPtr pObjectPtr, string assetId, bool deleteLooseFiles,
            bool deleteDependencies);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerRefreshAsset(IntPtr pObjectPtr, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerRefreshAllAssets(IntPtr pObjectPtr, bool includeUnloaded);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerSaveAssetTags(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRestoreAssetTags(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetManagerGetAssetTags(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAllAssets(IntPtr pObjectPtr, IntPtr assetQuery,
            bool ignoreInternal, bool ignorePrivate);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetName(IntPtr pObjectPtr, IntPtr assetQuery, string assetName,
            bool partialName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetCategory(IntPtr pObjectPtr, IntPtr assetQuery,
            string assetName, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetAutoUnload(IntPtr pObjectPtr, IntPtr assetQuery,
            bool assetAutoUnload, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetInternal(IntPtr pObjectPtr, IntPtr assetQuery,
            bool assetInternal, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetPrivate(IntPtr pObjectPtr, IntPtr assetQuery,
            bool assetPrivate, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetType(IntPtr pObjectPtr, IntPtr assetQuery, string assetType,
            bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetDependsOn(IntPtr pObjectPtr, IntPtr assetQuery,
            string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetIsDependedOn(IntPtr pObjectPtr, IntPtr assetQuery,
            string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindInvalidAssetReferences(IntPtr pObjectPtr, IntPtr assetQuery);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindTaggedAssets(IntPtr pObjectPtr, IntPtr assetQuery,
            string assetTagNames, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetLooseFile(IntPtr pObjectPtr, IntPtr assetQuery,
            string assetLooseFile, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetDeclaredAssetCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetReferencedAssetCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetLoadedInternalAssetCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetMaxLoadedInternalAssetCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetLoadedExternalAssetCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetMaxLoadedExternalAssetCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerDumpDeclaredAssets(IntPtr pObjectPtr);
      }

      #endregion

      #region Properties

      public bool EchoInfo
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetManagerGetEchoInfo(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetManagerSetEchoInfo(ObjectPtr->ObjPtr, value);
         }
      }

      public bool IgnoreAutoUnload
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AssetManagerGetIgnoreAutoUnload(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AssetManagerSetIgnoreAutoUnload(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion

      #region Methods

      public bool CompileReferencedAssets(ModuleDefinition moduleDefinition)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerCompileReferencedAssets(ObjectPtr->ObjPtr, moduleDefinition);
      }

      public bool AddModuleDeclaredAssets(ModuleDefinition moduleDefinition)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerAddModuleDeclaredAssets(ObjectPtr->ObjPtr, moduleDefinition);
      }

      public bool AddDeclaredAsset(ModuleDefinition moduleDefinition, string assetFilePath)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerAddDeclaredAsset(ObjectPtr->ObjPtr, /*moduleDefinition*/ IntPtr.Zero, assetFilePath);
      }

      public string AddPrivateAsset(AssetBase assetObject)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerAddPrivateAsset(ObjectPtr->ObjPtr, assetObject.ObjectPtr->ObjPtr);
      }

      public bool RemoveDeclaredAssets(ModuleDefinition moduleDefinition)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerRemoveDeclaredAssets(ObjectPtr->ObjPtr, moduleDefinition);
      }

      public bool RemoveDeclaredAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerRemoveDeclaredAsset(ObjectPtr->ObjPtr, assetId);
      }

      public string GetAssetName(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetAssetName(ObjectPtr->ObjPtr, assetId);
      }

      public string GetAssetDescription(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetAssetDescription(ObjectPtr->ObjPtr, assetId);
      }

      public string GetAssetCategory(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetAssetCategory(ObjectPtr->ObjPtr, assetId);
      }

      public string GetAssetType(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetAssetType(ObjectPtr->ObjPtr, assetId);
      }

      public string GetAssetFilePath(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetAssetFilePath(ObjectPtr->ObjPtr, assetId);
      }

      public string GetAssetPath(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetAssetPath(ObjectPtr->ObjPtr, assetId);
      }

      public IntPtr GetAssetModule(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetAssetModule(ObjectPtr->ObjPtr, assetId);
      }

      public bool IsAssetInternal(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerIsAssetInternal(ObjectPtr->ObjPtr, assetId);
      }

      public bool IsAssetPrivate(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerIsAssetPrivate(ObjectPtr->ObjPtr, assetId);
      }

      public bool IsAssetAutoUnload(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerIsAssetAutoUnload(ObjectPtr->ObjPtr, assetId);
      }

      public bool IsAssetLoaded(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerIsAssetLoaded(ObjectPtr->ObjPtr, assetId);
      }

      public bool IsDeclaredAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerIsDeclaredAsset(ObjectPtr->ObjPtr, assetId);
      }

      public bool IsReferencedAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerIsReferencedAsset(ObjectPtr->ObjPtr, assetId);
      }

      public bool RenameDeclaredAsset(string assetIdFrom, string assetIdTo)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerRenameDeclaredAsset(ObjectPtr->ObjPtr, assetIdFrom, assetIdTo);
      }

      public bool RenameReferencedAsset(string assetIdFrom, string assetIdTo)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerRenameReferencedAsset(ObjectPtr->ObjPtr, assetIdFrom, assetIdTo);
      }

      public string AcquireAsset(string assetId, bool asPrivate = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerAcquireAsset(ObjectPtr->ObjPtr, assetId, asPrivate);
      }

      public bool ReleaseAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerReleaseAsset(ObjectPtr->ObjPtr, assetId);
      }

      public void PurgeAssets()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerPurgeAssets(ObjectPtr->ObjPtr);
      }

      public bool DeleteAsset(string assetId, bool deleteLooseFiles, bool deleteDependencies)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerDeleteAsset(ObjectPtr->ObjPtr, assetId, deleteLooseFiles,
            deleteDependencies);
      }

      public void RefreshAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerRefreshAsset(ObjectPtr->ObjPtr, assetId);
      }

      public void RefreshAllAssets(bool includeUnloaded)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerRefreshAllAssets(ObjectPtr->ObjPtr, includeUnloaded);
      }

      public bool SaveAssetTags()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerSaveAssetTags(ObjectPtr->ObjPtr);
      }

      public bool RestoreAssetTags()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerRestoreAssetTags(ObjectPtr->ObjPtr);
      }

      public IntPtr GetAssetTags()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetAssetTags(ObjectPtr->ObjPtr);
      }

      public int FindAllAssets(AssetQuery assetQuery, bool ignoreInternal = true, bool ignorePrivate = true)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAllAssets(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, ignoreInternal,
            ignorePrivate);
      }

      public int FindAssetName(AssetQuery assetQuery, string assetName, bool partialName = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetName(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetName, partialName);
      }

      public int FindAssetCategory(AssetQuery assetQuery, string assetName, bool assetQueryAsSource = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetCategory(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetName,
            assetQueryAsSource);
      }

      public int FindAssetAutoUnload(AssetQuery assetQuery, bool assetAutoUnload, bool assetQueryAsSource = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetAutoUnload(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetAutoUnload,
            assetQueryAsSource);
      }

      public int FindAssetInternal(AssetQuery assetQuery, bool assetInternal, bool assetQueryAsSource = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetInternal(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetInternal,
            assetQueryAsSource);
      }

      public int FindAssetPrivate(AssetQuery assetQuery, bool assetPrivate, bool assetQueryAsSource = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetPrivate(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetPrivate,
            assetQueryAsSource);
      }

      public int FindAssetType(AssetQuery assetQuery, string assetType, bool assetQueryAsSource = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetType(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetType,
            assetQueryAsSource);
      }

      public int FindAssetDependsOn(AssetQuery assetQuery, string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetDependsOn(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetId);
      }

      public int FindAssetIsDependedOn(AssetQuery assetQuery, string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetIsDependedOn(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetId);
      }

      public int FindInvalidAssetReferences(AssetQuery assetQuery)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindInvalidAssetReferences(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr);
      }

      public int FindTaggedAssets(AssetQuery assetQuery, string assetTagNames, bool assetQueryAsSource = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindTaggedAssets(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetTagNames,
            assetQueryAsSource);
      }

      public int FindAssetLooseFile(AssetQuery assetQuery, string assetLooseFile, bool assetQueryAsSource = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerFindAssetLooseFile(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetLooseFile,
            assetQueryAsSource);
      }

      public bool GetDeclaredAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetDeclaredAssetCount(ObjectPtr->ObjPtr);
      }

      public bool GetReferencedAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetReferencedAssetCount(ObjectPtr->ObjPtr);
      }

      public bool GetLoadedInternalAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetLoadedInternalAssetCount(ObjectPtr->ObjPtr);
      }

      public bool GetMaxLoadedInternalAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetMaxLoadedInternalAssetCount(ObjectPtr->ObjPtr);
      }

      public bool GetLoadedExternalAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetLoadedExternalAssetCount(ObjectPtr->ObjPtr);
      }

      public bool GetMaxLoadedExternalAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return InternalUnsafeMethods.AssetManagerGetMaxLoadedExternalAssetCount(ObjectPtr->ObjPtr);
      }

      public void DumpDeclaredAssets()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerDumpDeclaredAssets(ObjectPtr->ObjPtr);
      }

      #endregion
   }
}