using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.Scene
{
   public unsafe class SinNode : BaseNode
   {
      public SinNode()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.SinNodeCreateInstance());
      }

      public SinNode(uint pId) : base(pId)
      {
      }

      public SinNode(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public SinNode(string pName) : base(pName)
      {
      }

      public SinNode(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SinNodeGetXSrc(IntPtr sinNode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SinNodeSetXSrc(IntPtr sinNode, string src);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SinNodeCreateInstance();
      }
      
      #endregion

      #region Properties

      public string XSrc
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.SinNodeGetXSrc(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.SinNodeSetXSrc(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}