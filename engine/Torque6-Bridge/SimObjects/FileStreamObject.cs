using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class FileStreamObject : StreamObject
   {
      public FileStreamObject()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.FileStreamObjectCreateInstance());
      }

      public FileStreamObject(uint pId) : base(pId)
      {
      }

      public FileStreamObject(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public FileStreamObject(string pName) : base(pName)
      {
      }

      public FileStreamObject(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr FileStreamObjectCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool FileStreamObjectOpen(IntPtr fileStream, string fileName, int mode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileStreamObjectClose(IntPtr fileStream);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void Open(string fileName, int mode)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileStreamObjectOpen(ObjectPtr->ObjPtr, fileName, mode);
      }

      public void Close()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileStreamObjectClose(ObjectPtr->ObjPtr);
      }

      #endregion
   }
}