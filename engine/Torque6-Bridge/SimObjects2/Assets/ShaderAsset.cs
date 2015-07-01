using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class ShaderAsset : AssetBase
   {
      public ShaderAsset()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.ShaderAssetCreateInstance());
      }

      public ShaderAsset(uint pId)
         : base(pId)
      {
      }

      public ShaderAsset(IntPtr pObjPtr)
         : base(pObjPtr)
      {
      }

      public ShaderAsset(string pName)
         : base(pName)
      {
      }

      public ShaderAsset(Sim.SimObjectPtr* pObjPtr)
         : base(pObjPtr)
      {
      }

      #region UnsafeNativeMethods

      internal new struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ShaderAssetCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ShaderAssetGetVertexShaderFile(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ShaderAssetSetVertexShaderFile(IntPtr pObjectPtr, string val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ShaderAssetGetPixelShaderFile(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ShaderAssetSetPixelShaderFile(IntPtr pObjectPtr, string val);
      }

      #endregion

      #region Properties

      public string VertexShaderFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ShaderAssetGetVertexShaderFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ShaderAssetSetVertexShaderFile(ObjectPtr->ObjPtr, value);
         }
      }

      public string PixelShaderFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ShaderAssetGetPixelShaderFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ShaderAssetSetPixelShaderFile(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion

      #region Methods

      #endregion
   }
}