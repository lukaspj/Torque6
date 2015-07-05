using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class EntityTemplate : SimGroup
   {
      public EntityTemplate()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.EntityTemplateCreateInstance());
      }

      public EntityTemplate(uint pId) : base(pId)
      {
      }

      public EntityTemplate(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public EntityTemplate(string pName) : base(pName)
      {
      }

      public EntityTemplate(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr EntityTemplateCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}