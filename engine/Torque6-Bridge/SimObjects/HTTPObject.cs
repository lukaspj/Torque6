using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class HTTPObject : TCPObject
   {
      public HTTPObject()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.HTTPObjectCreateInstance());
      }

      public HTTPObject(uint pId) : base(pId)
      {
      }

      public HTTPObject(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public HTTPObject(string pName) : base(pName)
      {
      }

      public HTTPObject(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr HTTPObjectCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void HTTPObjectGet(IntPtr httpObj, string address, string requestURI, string query);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void HTTPObjectPost(IntPtr httpObj, string address, string requestURI, string query, string post);
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      public void Get(string address, string requestURI, string query)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.HTTPObjectGet(ObjectPtr->ObjPtr, address, requestURI, query);
      }

      public void Post(string address, string requestURI, string query, string post)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.HTTPObjectPost(ObjectPtr->ObjPtr, address, requestURI, query, post);
      }
      
      #endregion
   }
}