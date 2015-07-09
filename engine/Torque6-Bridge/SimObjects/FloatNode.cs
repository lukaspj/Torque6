using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class FloatNode : BaseNode
   {
      public FloatNode()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.FloatNodeCreateInstance());
      }

      public FloatNode(uint pId) : base(pId)
      {
      }

      public FloatNode(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public FloatNode(string pName) : base(pName)
      {
      }

      public FloatNode(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string FloatNodeGetUniformName(IntPtr floatNode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FloatNodeSetUniformName(IntPtr floatNode, string src);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern float FloatNodeGetValue(IntPtr floatNode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FloatNodeSetValue(IntPtr floatNode, float val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr FloatNodeCreateInstance();
      }
      
      #endregion

      #region Properties

      public string UniformName
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.FloatNodeGetUniformName(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.FloatNodeSetUniformName(ObjectPtr->ObjPtr, value);
         }
      }
      public float Value
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.FloatNodeGetValue(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.FloatNodeSetValue(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}