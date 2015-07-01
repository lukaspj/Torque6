using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class StreamObject : SimObject
   {
      public StreamObject()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.StreamObjectCreateInstance());
      }

      public StreamObject(uint pId) : base(pId)
      {
      }

      public StreamObject(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public StreamObject(string pName) : base(pName)
      {
      }

      public StreamObject(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr StreamObjectCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string StreamObjectGetStatus(IntPtr streamObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool StreamObjectIsEOS(IntPtr streamObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool StreamObjectIsEOF(IntPtr streamObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int StreamObjectGetPosition(IntPtr streamObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool StreamObjectSetPosition(IntPtr streamObj, int newPos);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int StreamObjectGetStreamSize(IntPtr streamObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string StreamObjectReadLine(IntPtr streamObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void StreamObjectWriteLine(IntPtr streamObj, string line);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string StreamObjectReadSTString(IntPtr streamObj, bool caseSensitive);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string StreamObjectReadString(IntPtr streamObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string StreamObjectReadLongString(IntPtr streamObj, int maxLength);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void StreamObjectWriteLongString(IntPtr streamObj, int maxLength, string longString);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void StreamObjectWriteString(IntPtr streamObj, string longString, int maxLength);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool StreamObjectCopyFrom(IntPtr streamObj, IntPtr other);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void GetStatus()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectGetStatus(ObjectPtr->ObjPtr);
      }

      public void IsEOS()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectIsEOS(ObjectPtr->ObjPtr);
      }

      public void IsEOF()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectIsEOF(ObjectPtr->ObjPtr);
      }

      public void GetPosition()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectGetPosition(ObjectPtr->ObjPtr);
      }

      public void SetPosition(int newPos)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectSetPosition(ObjectPtr->ObjPtr, newPos);
      }

      public void GetStreamSize()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectGetStreamSize(ObjectPtr->ObjPtr);
      }

      public void ReadLine()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectReadLine(ObjectPtr->ObjPtr);
      }

      public void WriteLine(string line)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectWriteLine(ObjectPtr->ObjPtr, line);
      }

      public void ReadSTString(bool caseSensitive)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectReadSTString(ObjectPtr->ObjPtr, caseSensitive);
      }

      public void ReadString()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectReadString(ObjectPtr->ObjPtr);
      }

      public void ReadLongString(int maxLength)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectReadLongString(ObjectPtr->ObjPtr, maxLength);
      }

      public void WriteLongString(int maxLength, string longString)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectWriteLongString(ObjectPtr->ObjPtr, maxLength, longString);
      }

      public void WriteString(string longString, int maxLength)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectWriteString(ObjectPtr->ObjPtr, longString, maxLength);
      }

      public void CopyFrom(StreamObject other)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.StreamObjectCopyFrom(ObjectPtr->ObjPtr, other.ObjectPtr->ObjPtr);
      }

      #endregion
   }
}