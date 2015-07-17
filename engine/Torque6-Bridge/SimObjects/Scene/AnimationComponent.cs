using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.Scene
{
   public unsafe class AnimationComponent : BaseComponent
   {
      public AnimationComponent()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AnimationComponentCreateInstance());
      }

      public AnimationComponent(uint pId) : base(pId)
      {
      }

      public AnimationComponent(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public AnimationComponent(string pName) : base(pName)
      {
      }

      public AnimationComponent(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern float AnimationComponentGetSpeed(IntPtr animationComponent);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AnimationComponentSetSpeed(IntPtr animationComponent, float val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AnimationComponentGetTarget(IntPtr animationComponent);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AnimationComponentSetTarget(IntPtr animationComponent, IntPtr val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string AnimationComponentGetMeshAsset(IntPtr animationComponent);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void AnimationComponentSetMeshAsset(IntPtr animationComponent, string meshAssetId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr AnimationComponentCreateInstance();
      }
      
      #endregion

      #region Properties

      public float Speed
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AnimationComponentGetSpeed(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AnimationComponentSetSpeed(ObjectPtr->ObjPtr, value);
         }
      }
      public MeshComponent Target
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return new MeshComponent(InternalUnsafeMethods.AnimationComponentGetTarget(ObjectPtr->ObjPtr));
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AnimationComponentSetTarget(ObjectPtr->ObjPtr, value.ObjectPtr->ObjPtr);
         }
      }
      public string MeshAsset
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.AnimationComponentGetMeshAsset(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.AnimationComponentSetMeshAsset(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}