using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class FileDialog : SimObject
   {
      public FileDialog()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.FileDialogCreateInstance());
      }

      public FileDialog(uint pId) : base(pId)
      {
      }

      public FileDialog(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public FileDialog(string pName) : base(pName)
      {
      }

      public FileDialog(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string FileDialogGetDefaultPath(IntPtr fileDialog);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileDialogSetDefaultPath(IntPtr fileDialog, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string FileDialogGetDefaultFile(IntPtr fileDialog);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileDialogSetDefaultFile(IntPtr fileDialog, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string FileDialogGetFileName(IntPtr fileDialog);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileDialogSetFileName(IntPtr fileDialog, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string FileDialogGetFilters(IntPtr fileDialog);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileDialogSetFilters(IntPtr fileDialog, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string FileDialogGetTitle(IntPtr fileDialog);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileDialogSetTitle(IntPtr fileDialog, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool FileDialogGetChangePath(IntPtr fileDialog);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void FileDialogSetChangePath(IntPtr fileDialog, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr FileDialogCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool FileDialogExecute(IntPtr fileDialog);
      }
      
      #endregion

      #region Properties

      public string DefaultPath
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.FileDialogGetDefaultPath(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.FileDialogSetDefaultPath(ObjectPtr->ObjPtr, value);
         }
      }
      public string DefaultFile
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.FileDialogGetDefaultFile(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.FileDialogSetDefaultFile(ObjectPtr->ObjPtr, value);
         }
      }
      public string FileName
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.FileDialogGetFileName(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.FileDialogSetFileName(ObjectPtr->ObjPtr, value);
         }
      }
      public string Filters
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.FileDialogGetFilters(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.FileDialogSetFilters(ObjectPtr->ObjPtr, value);
         }
      }
      public string Title
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.FileDialogGetTitle(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.FileDialogSetTitle(ObjectPtr->ObjPtr, value);
         }
      }
      public bool ChangePath
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.FileDialogGetChangePath(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.FileDialogSetChangePath(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      public void Execute()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.FileDialogExecute(ObjectPtr->ObjPtr);
      }
      
      #endregion
   }
}