using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class DeclaredAssets : SimObject
   {
      public DeclaredAssets()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.DeclaredAssetsCreateInstance());
      }

      public DeclaredAssets(uint pId) : base(pId)
      {
      }

      public DeclaredAssets(string pName) : base(pName)
      {
      }

      public DeclaredAssets(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public DeclaredAssets(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr DeclaredAssetsCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string DeclaredAssetsGetPath(IntPtr pDeclaredAssetsPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void DeclaredAssetsSetPath(IntPtr pDeclaredAssetsPtr, string pPath);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string DeclaredAssetsGetExtension(IntPtr pDeclaredAssetsPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void DeclaredAssetsSetExtension(IntPtr pDeclaredAssetsPtr, string pExtension);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool DeclaredAssetsGetRecurse(IntPtr pDeclaredAssetsPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void DeclaredAssetsSetRecurse(IntPtr pDeclaredAssetsPtr, bool pRecurse);
      }

      #endregion

      #region Properties

      public string Path
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.DeclaredAssetsGetPath(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.DeclaredAssetsSetPath(ObjectPtr->ObjPtr, value);
         }
      }

      public string Extension
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.DeclaredAssetsGetExtension(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.DeclaredAssetsSetExtension(ObjectPtr->ObjPtr, value);
         }
      }

      public bool Recurse
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.DeclaredAssetsGetRecurse(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.DeclaredAssetsSetRecurse(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion
   }
}