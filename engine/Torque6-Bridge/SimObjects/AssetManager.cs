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

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetEchoInfo(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerSetEchoInfo(IntPtr assetManager, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetIgnoreAutoUnload(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerSetIgnoreAutoUnload(IntPtr assetManager, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetManagerCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerCompileReferencedAssets(IntPtr assetManager, IntPtr moduleDefinition);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerAddModuleDeclaredAssets(IntPtr assetManager, IntPtr moduleDefinition);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerAddDeclaredAsset(IntPtr assetManager, IntPtr moduleDefinition, string assetFilePath);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerAddPrivateAsset(IntPtr assetManager, IntPtr assetObject);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRemoveDeclaredAssets(IntPtr assetManager, IntPtr moduleDefinition);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRemoveDeclaredAsset(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetName(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetDescription(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetCategory(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetType(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetFilePath(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerGetAssetPath(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetManagerGetAssetModule(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsAssetInternal(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsAssetPrivate(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsAssetAutoUnload(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsAssetLoaded(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsDeclaredAsset(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerIsReferencedAsset(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRenameDeclaredAsset(IntPtr assetManager, string assetIdFrom, string assetIdTo);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRenameReferencedAsset(IntPtr assetManager, string assetIdFrom, string assetIdTo);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AssetManagerAcquireAsset(IntPtr assetManager, string assetId, bool asPrivate);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerReleaseAsset(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerPurgeAssets(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerDeleteAsset(IntPtr assetManager, string assetId, bool deleteLooseFiles, bool deleteDependencies);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerRefreshAsset(IntPtr assetManager, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerRefreshAllAssets(IntPtr assetManager, bool includeUnloaded);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerSaveAssetTags(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerRestoreAssetTags(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AssetManagerGetAssetTags(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAllAssets(IntPtr assetManager, IntPtr assetQuery, bool ignoreInternal, bool ignorePrivate);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetName(IntPtr assetManager, IntPtr assetQuery, string assetName, bool partialName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetCategory(IntPtr assetManager, IntPtr assetQuery, string assetName, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetAutoUnload(IntPtr assetManager, IntPtr assetQuery, bool assetAutoUnload, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetInternal(IntPtr assetManager, IntPtr assetQuery, bool assetInternal, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetPrivate(IntPtr assetManager, IntPtr assetQuery, bool assetPrivate, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetType(IntPtr assetManager, IntPtr assetQuery, string assetType, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetDependsOn(IntPtr assetManager, IntPtr assetQuery, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetIsDependedOn(IntPtr assetManager, IntPtr assetQuery, string assetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindInvalidAssetReferences(IntPtr assetManager, IntPtr assetQuery);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindTaggedAssets(IntPtr assetManager, IntPtr assetQuery, string assetTagNames, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int AssetManagerFindAssetLooseFile(IntPtr assetManager, IntPtr assetQuery, string assetLooseFile, bool assetQueryAsSource);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetDeclaredAssetCount(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetReferencedAssetCount(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetLoadedInternalAssetCount(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetMaxLoadedInternalAssetCount(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetLoadedExternalAssetCount(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool AssetManagerGetMaxLoadedExternalAssetCount(IntPtr assetManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AssetManagerDumpDeclaredAssets(IntPtr assetManager);


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

      public void CompileReferencedAssets(ModuleDefinition moduleDefinition)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerCompileReferencedAssets(ObjectPtr->ObjPtr, moduleDefinition.ObjectPtr->ObjPtr);
      }

      public void AddModuleDeclaredAssets(ModuleDefinition moduleDefinition)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerAddModuleDeclaredAssets(ObjectPtr->ObjPtr, moduleDefinition.ObjectPtr->ObjPtr);
      }

      public void AddDeclaredAsset(ModuleDefinition moduleDefinition, string assetFilePath)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerAddDeclaredAsset(ObjectPtr->ObjPtr, moduleDefinition.ObjectPtr->ObjPtr, assetFilePath);
      }

      public void AddPrivateAsset(AssetBase assetObject)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerAddPrivateAsset(ObjectPtr->ObjPtr, assetObject.ObjectPtr->ObjPtr);
      }

      public void RemoveDeclaredAssets(ModuleDefinition moduleDefinition)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerRemoveDeclaredAssets(ObjectPtr->ObjPtr, moduleDefinition.ObjectPtr->ObjPtr);
      }

      public void RemoveDeclaredAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerRemoveDeclaredAsset(ObjectPtr->ObjPtr, assetId);
      }

      public void GetAssetName(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetAssetName(ObjectPtr->ObjPtr, assetId);
      }

      public void GetAssetDescription(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetAssetDescription(ObjectPtr->ObjPtr, assetId);
      }

      public void GetAssetCategory(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetAssetCategory(ObjectPtr->ObjPtr, assetId);
      }

      public void GetAssetType(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetAssetType(ObjectPtr->ObjPtr, assetId);
      }

      public void GetAssetFilePath(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetAssetFilePath(ObjectPtr->ObjPtr, assetId);
      }

      public void GetAssetPath(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetAssetPath(ObjectPtr->ObjPtr, assetId);
      }

      public void GetAssetModule(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetAssetModule(ObjectPtr->ObjPtr, assetId);
      }

      public void IsAssetInternal(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerIsAssetInternal(ObjectPtr->ObjPtr, assetId);
      }

      public void IsAssetPrivate(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerIsAssetPrivate(ObjectPtr->ObjPtr, assetId);
      }

      public void IsAssetAutoUnload(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerIsAssetAutoUnload(ObjectPtr->ObjPtr, assetId);
      }

      public void IsAssetLoaded(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerIsAssetLoaded(ObjectPtr->ObjPtr, assetId);
      }

      public void IsDeclaredAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerIsDeclaredAsset(ObjectPtr->ObjPtr, assetId);
      }

      public void IsReferencedAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerIsReferencedAsset(ObjectPtr->ObjPtr, assetId);
      }

      public void RenameDeclaredAsset(string assetIdFrom, string assetIdTo)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerRenameDeclaredAsset(ObjectPtr->ObjPtr, assetIdFrom, assetIdTo);
      }

      public void RenameReferencedAsset(string assetIdFrom, string assetIdTo)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerRenameReferencedAsset(ObjectPtr->ObjPtr, assetIdFrom, assetIdTo);
      }

      public void AcquireAsset(string assetId, bool asPrivate)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerAcquireAsset(ObjectPtr->ObjPtr, assetId, asPrivate);
      }

      public void ReleaseAsset(string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerReleaseAsset(ObjectPtr->ObjPtr, assetId);
      }

      public void PurgeAssets()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerPurgeAssets(ObjectPtr->ObjPtr);
      }

      public void DeleteAsset(string assetId, bool deleteLooseFiles, bool deleteDependencies)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerDeleteAsset(ObjectPtr->ObjPtr, assetId, deleteLooseFiles, deleteDependencies);
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

      public void SaveAssetTags()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerSaveAssetTags(ObjectPtr->ObjPtr);
      }

      public void RestoreAssetTags()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerRestoreAssetTags(ObjectPtr->ObjPtr);
      }

      public void GetAssetTags()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetAssetTags(ObjectPtr->ObjPtr);
      }

      public void FindAllAssets(AssetQuery assetQuery, bool ignoreInternal, bool ignorePrivate)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAllAssets(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, ignoreInternal, ignorePrivate);
      }

      public void FindAssetName(AssetQuery assetQuery, string assetName, bool partialName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetName(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetName, partialName);
      }

      public void FindAssetCategory(AssetQuery assetQuery, string assetName, bool assetQueryAsSource)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetCategory(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetName, assetQueryAsSource);
      }

      public void FindAssetAutoUnload(AssetQuery assetQuery, bool assetAutoUnload, bool assetQueryAsSource)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetAutoUnload(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetAutoUnload, assetQueryAsSource);
      }

      public void FindAssetInternal(AssetQuery assetQuery, bool assetInternal, bool assetQueryAsSource)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetInternal(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetInternal, assetQueryAsSource);
      }

      public void FindAssetPrivate(AssetQuery assetQuery, bool assetPrivate, bool assetQueryAsSource)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetPrivate(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetPrivate, assetQueryAsSource);
      }

      public void FindAssetType(AssetQuery assetQuery, string assetType, bool assetQueryAsSource)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetType(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetType, assetQueryAsSource);
      }

      public void FindAssetDependsOn(AssetQuery assetQuery, string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetDependsOn(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetId);
      }

      public void FindAssetIsDependedOn(AssetQuery assetQuery, string assetId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetIsDependedOn(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetId);
      }

      public void FindInvalidAssetReferences(AssetQuery assetQuery)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindInvalidAssetReferences(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr);
      }

      public void FindTaggedAssets(AssetQuery assetQuery, string assetTagNames, bool assetQueryAsSource)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindTaggedAssets(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetTagNames, assetQueryAsSource);
      }

      public void FindAssetLooseFile(AssetQuery assetQuery, string assetLooseFile, bool assetQueryAsSource)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerFindAssetLooseFile(ObjectPtr->ObjPtr, assetQuery.ObjectPtr->ObjPtr, assetLooseFile, assetQueryAsSource);
      }

      public void GetDeclaredAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetDeclaredAssetCount(ObjectPtr->ObjPtr);
      }

      public void GetReferencedAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetReferencedAssetCount(ObjectPtr->ObjPtr);
      }

      public void GetLoadedInternalAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetLoadedInternalAssetCount(ObjectPtr->ObjPtr);
      }

      public void GetMaxLoadedInternalAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetMaxLoadedInternalAssetCount(ObjectPtr->ObjPtr);
      }

      public void GetLoadedExternalAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetLoadedExternalAssetCount(ObjectPtr->ObjPtr);
      }

      public void GetMaxLoadedExternalAssetCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerGetMaxLoadedExternalAssetCount(ObjectPtr->ObjPtr);
      }

      public void DumpDeclaredAssets()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.AssetManagerDumpDeclaredAssets(ObjectPtr->ObjPtr);
      }

      #endregion
   }
}