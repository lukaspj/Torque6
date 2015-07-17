using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.Scene
{
   public unsafe class MultiplyNode : BaseNode
   {
      public MultiplyNode()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.MultiplyNodeCreateInstance());
      }

      public MultiplyNode(uint pId) : base(pId)
      {
      }

      public MultiplyNode(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public MultiplyNode(string pName) : base(pName)
      {
      }

      public MultiplyNode(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MultiplyNodeGetInputASrc(IntPtr MultiplyNode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MultiplyNodeSetInputASrc(IntPtr MultiplyNode, string src);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MultiplyNodeGetInputBSrc(IntPtr MultiplyNode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MultiplyNodeSetInputBSrc(IntPtr MultiplyNode, string src);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr MultiplyNodeCreateInstance();
      }
      
      #endregion

      #region Properties

      public string InputASrc
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.MultiplyNodeGetInputASrc(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.MultiplyNodeSetInputASrc(ObjectPtr->ObjPtr, value);
         }
      }
      public string InputBSrc
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.MultiplyNodeGetInputBSrc(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.MultiplyNodeSetInputBSrc(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}