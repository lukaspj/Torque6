﻿using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class PluginAsset : AssetBase
   {
      public PluginAsset()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.PluginAssetCreateInstance());
      }

      public PluginAsset(uint pId)
         : base(pId)
      {
      }

      public PluginAsset(IntPtr pObjPtr)
         : base(pObjPtr)
      {
      }

      public PluginAsset(string pName)
         : base(pName)
      {
      }

      public PluginAsset(Sim.SimObjectPtr* pObjPtr)
         : base(pObjPtr)
      {
      }

      #region Properties

      public string PluginFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.PluginAssetGetPluginFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.PluginAssetSetPluginFile(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion

      #region UnsafeNativeMethods

      internal new struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr PluginAssetCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string PluginAssetGetPluginFile(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string PluginAssetSetPluginFile(IntPtr pObjectPtr, string val);
      }

      #endregion

      #region Methods

      #endregion
   }
}