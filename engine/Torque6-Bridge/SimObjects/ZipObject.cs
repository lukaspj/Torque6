using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class ZipObject : SimObject
   {
      public ZipObject()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.ZipObjectCreateInstance());
      }

      public ZipObject(uint pId) : base(pId)
      {
      }

      public ZipObject(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public ZipObject(string pName) : base(pName)
      {
      }

      public ZipObject(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ZipObjectCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ZipObjectOpenArchive(IntPtr zipObj, string fileName, int mode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ZipObjectCloseArchive(IntPtr zipObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ZipObjectOpenFileForRead(IntPtr zipObj, string fileName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ZipObjectOpenFileForWrite(IntPtr zipObj, string fileName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ZipObjectCloseFile(IntPtr zipObj, IntPtr stream);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ZipObjectAddFile(IntPtr zipObj, string fileName, string pathInZip, bool replace);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ZipObjectExtractFile(IntPtr zipObj, string fileName, string pathInZip);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ZipObjectDeleteFile(IntPtr zipObj, string pathInZip);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ZipObjectGetFileEntryCount(IntPtr zipObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ZipObjectGetFileEntry(IntPtr zipObj, int index);
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      public void OpenArchive(string fileName, int mode)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectOpenArchive(ObjectPtr->ObjPtr, fileName, mode);
      }

      public void CloseArchive()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectCloseArchive(ObjectPtr->ObjPtr);
      }

      public void OpenFileForRead(string fileName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectOpenFileForRead(ObjectPtr->ObjPtr, fileName);
      }

      public void OpenFileForWrite(string fileName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectOpenFileForWrite(ObjectPtr->ObjPtr, fileName);
      }

      public void CloseFile(StreamObject stream)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectCloseFile(ObjectPtr->ObjPtr, stream.ObjectPtr->ObjPtr);
      }

      public void AddFile(string fileName, string pathInZip, bool replace)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectAddFile(ObjectPtr->ObjPtr, fileName, pathInZip, replace);
      }

      public void ExtractFile(string fileName, string pathInZip)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectExtractFile(ObjectPtr->ObjPtr, fileName, pathInZip);
      }

      public void DeleteFile(string pathInZip)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectDeleteFile(ObjectPtr->ObjPtr, pathInZip);
      }

      public void GetFileEntryCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectGetFileEntryCount(ObjectPtr->ObjPtr);
      }

      public void GetFileEntry(int index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ZipObjectGetFileEntry(ObjectPtr->ObjPtr, index);
      }
      
      #endregion
   }
}