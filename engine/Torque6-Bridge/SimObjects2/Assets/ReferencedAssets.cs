﻿using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class ReferencedAssets : SimObject
   {
      public ReferencedAssets()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.ReferencedAssetsCreateInstance());
      }

      public ReferencedAssets(uint pId) : base(pId)
      {
      }

      public ReferencedAssets(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public ReferencedAssets(string pName) : base(pName)
      {
      }

      public ReferencedAssets(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ReferencedAssetsCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ReferencedAssetsGetPath(IntPtr pReferencedAssetsPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ReferencedAssetsSetPath(IntPtr pReferencedAssetsPtr, string pPath);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ReferencedAssetsGetExtension(IntPtr pReferencedAssetsPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ReferencedAssetsSetExtension(IntPtr pReferencedAssetsPtr, string pExtension);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ReferencedAssetsGetRecurse(IntPtr pReferencedAssetsPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ReferencedAssetsSetRecurse(IntPtr pReferencedAssetsPtr, bool pRecurse);
      }

      #endregion

      #region Properties

      public string Path
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ReferencedAssetsGetPath(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ReferencedAssetsSetPath(ObjectPtr->ObjPtr, value);
         }
      }

      public string Extension
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ReferencedAssetsGetExtension(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ReferencedAssetsSetExtension(ObjectPtr->ObjPtr, value);
         }
      }

      public bool Recurse
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ReferencedAssetsGetRecurse(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ReferencedAssetsSetRecurse(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion
   }
}