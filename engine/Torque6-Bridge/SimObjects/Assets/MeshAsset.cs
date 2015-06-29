using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class MeshAsset : SimObject
   {
      public MeshAsset()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.MeshAssetCreateInstance());
      }

      public MeshAsset(uint pId)
         : base(pId)
      {
      }

      public MeshAsset(IntPtr pObjPtr)
         : base(pObjPtr)
      {
      }

      public MeshAsset(string pName)
         : base(pName)
      {
      }

      public MeshAsset(Sim.SimObjectPtr* pObjPtr)
         : base(pObjPtr)
      {
      }
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr MeshAssetCreateInstance();
         
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MeshAssetGetMeshFile(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MeshAssetSetMeshFile(IntPtr pObjectPtr, string val);

      }

      #endregion

      #region Properties

      public string MeshFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.MeshAssetGetMeshFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.MeshAssetSetMeshFile(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion

      #region Methods

      #endregion

   }

}
