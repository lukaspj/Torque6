using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class ModuleMergeDefinition : SimObject
   {
      public ModuleMergeDefinition()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.ModuleMergeDefinitionCreateInstance());
      }

      public ModuleMergeDefinition(uint pId) : base(pId)
      {
      }

      public ModuleMergeDefinition(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public ModuleMergeDefinition(string pName) : base(pName)
      {
      }

      public ModuleMergeDefinition(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ModuleMergeDefinitionGetMergePath(IntPtr mergeDefinition);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ModuleMergeDefinitionSetMergePath(IntPtr mergeDefinition, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ModuleMergeDefinitionCreateInstance();


      }
      #endregion

      #region Properties

      public string MergePath
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ModuleMergeDefinitionGetMergePath(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ModuleMergeDefinitionSetMergePath(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion
      
      #region Methods

      #endregion
   }
}