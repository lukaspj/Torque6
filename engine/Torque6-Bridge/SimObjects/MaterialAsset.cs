using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class MaterialAsset : AssetBase
   {
      public MaterialAsset()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.MaterialAssetCreateInstance());
      }

      public MaterialAsset(uint pId) : base(pId)
      {
      }

      public MaterialAsset(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public MaterialAsset(string pName) : base(pName)
      {
      }

      public MaterialAsset(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MaterialAssetGetTemplateFile(IntPtr materialAsset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MaterialAssetSetTemplateFile(IntPtr materialAsset, string file);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr MaterialAssetCreateInstance();


      }
      #endregion

      #region Properties

      public string TemplateFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.MaterialAssetGetTemplateFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.MaterialAssetSetTemplateFile(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion
      
      #region Methods

      #endregion
   }
}