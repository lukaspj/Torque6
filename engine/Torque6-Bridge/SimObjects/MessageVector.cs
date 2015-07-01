using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class MessageVector : SimObject
   {
      public MessageVector()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.MessageVectorCreateInstance());
      }

      public MessageVector(uint pId) : base(pId)
      {
      }

      public MessageVector(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public MessageVector(string pName) : base(pName)
      {
      }

      public MessageVector(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr MessageVectorCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MessageVectorClear(IntPtr messageVector);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MessageVectorPushBackLine(IntPtr messageVector, string msg, int tag);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool MessageVectorPopBackLine(IntPtr messageVector);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MessageVectorPushFrontLine(IntPtr messageVector, string msg, int tag);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool MessageVectorPopFrontLine(IntPtr messageVector);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool MessageVectorInsertLine(IntPtr messageVector, int pos, string msg, int tag);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool MessageVectorDeleteLine(IntPtr messageVector, uint lineIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void MessageVectorDump(IntPtr messageVector, string filename, string header);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int MessageVectorGetNumLines(IntPtr messageVector);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MessageVectorGetLineTextByTag(IntPtr messageVector, int tag);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int MessageVectorGetLineIndexByTag(IntPtr messageVector, int tag);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string MessageVectorGetLineText(IntPtr messageVector, uint index);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int MessageVectorGetLineTag(IntPtr messageVector, uint index);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void Clear()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorClear(ObjectPtr->ObjPtr);
      }

      public void PushBackLine(string msg, int tag)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorPushBackLine(ObjectPtr->ObjPtr, msg, tag);
      }

      public void PopBackLine()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorPopBackLine(ObjectPtr->ObjPtr);
      }

      public void PushFrontLine(string msg, int tag)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorPushFrontLine(ObjectPtr->ObjPtr, msg, tag);
      }

      public void PopFrontLine()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorPopFrontLine(ObjectPtr->ObjPtr);
      }

      public void InsertLine(int pos, string msg, int tag)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorInsertLine(ObjectPtr->ObjPtr, pos, msg, tag);
      }

      public void DeleteLine(uint lineIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorDeleteLine(ObjectPtr->ObjPtr, lineIndex);
      }

      public void Dump(string filename, string header)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorDump(ObjectPtr->ObjPtr, filename, header);
      }

      public void GetNumLines()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorGetNumLines(ObjectPtr->ObjPtr);
      }

      public void GetLineTextByTag(int tag)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorGetLineTextByTag(ObjectPtr->ObjPtr, tag);
      }

      public void GetLineIndexByTag(int tag)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorGetLineIndexByTag(ObjectPtr->ObjPtr, tag);
      }

      public void GetLineText(uint index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorGetLineText(ObjectPtr->ObjPtr, index);
      }

      public void GetLineTag(uint index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.MessageVectorGetLineTag(ObjectPtr->ObjPtr, index);
      }

      #endregion
   }
}