using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class EntityTemplateAsset : SimObject
   {
      public EntityTemplateAsset()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.EntityTemplateAssetCreateInstance());
      }

      public EntityTemplateAsset(uint pId) : base(pId)
      {
      }

      public EntityTemplateAsset(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public EntityTemplateAsset(string pName) : base(pName)
      {
      }

      public EntityTemplateAsset(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      #region Properties

      public string TemplateFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.EntityTemplateAssetGetTemplateFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.EntityTemplateAssetSetTemplateFile(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion

      #region UnsafeNativeMethods

      internal new struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr EntityTemplateAssetCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string EntityTemplateAssetGetTemplateFile(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string EntityTemplateAssetSetTemplateFile(IntPtr pObjectPtr, string val);
      }

      #endregion

      #region Methods

      #endregion
   }
}