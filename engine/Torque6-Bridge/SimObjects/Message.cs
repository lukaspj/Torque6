using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class Message : SimObject
   {
      public Message()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.MessageCreateInstance());
      }

      public Message(uint pId) : base(pId)
      {
      }

      public Message(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public Message(string pName) : base(pName)
      {
      }

      public Message(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr MessageCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MessageGetType(IntPtr message);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MessageAddReference(IntPtr message);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MessageFreeReference(IntPtr message);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void GetType()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageGetType(ObjectPtr->ObjPtr);
      }

      public void AddReference()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageAddReference(ObjectPtr->ObjPtr);
      }

      public void FreeReference()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageFreeReference(ObjectPtr->ObjPtr);
      }

      #endregion
   }
}