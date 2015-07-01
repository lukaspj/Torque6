using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class FileObject : SimObject
   {
      public FileObject()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.FileObjectCreateInstance());
      }

      public FileObject(uint pId) : base(pId)
      {
      }

      public FileObject(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public FileObject(string pName) : base(pName)
      {
      }

      public FileObject(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr FileObjectCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool FileObjectOpenForRead(IntPtr fileObj, string filename);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool FileObjectOpenForWrite(IntPtr fileObj, string filename);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool FileObjectOpenForAppend(IntPtr fileObj, string filename);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool FileObjectIsEOF(IntPtr fileObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string FileObjectReadLine(IntPtr fileObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string FileObjectPeekLine(IntPtr fileObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileObjectWriteLine(IntPtr fileObj, string text);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileObjectClose(IntPtr fileObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileObjectWriteObject(IntPtr fileObj, IntPtr simObj, string text);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void OpenForRead(string filename)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectOpenForRead(ObjectPtr->ObjPtr, filename);
      }

      public void OpenForWrite(string filename)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectOpenForWrite(ObjectPtr->ObjPtr, filename);
      }

      public void OpenForAppend(string filename)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectOpenForAppend(ObjectPtr->ObjPtr, filename);
      }

      public void IsEOF()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectIsEOF(ObjectPtr->ObjPtr);
      }

      public void ReadLine()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectReadLine(ObjectPtr->ObjPtr);
      }

      public void PeekLine()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectPeekLine(ObjectPtr->ObjPtr);
      }

      public void WriteLine(string text)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectWriteLine(ObjectPtr->ObjPtr, text);
      }

      public void Close()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectClose(ObjectPtr->ObjPtr);
      }

      public void WriteObject(SimObject simObj, string text)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileObjectWriteObject(ObjectPtr->ObjPtr, simObj.ObjectPtr->ObjPtr, text);
      }

      #endregion
   }
}