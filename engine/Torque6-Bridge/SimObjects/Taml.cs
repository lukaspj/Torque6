using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class Taml : SimObject
   {
      public Taml()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.TamlCreateInstance());
      }

      public Taml(uint pId) : base(pId)
      {
      }

      public Taml(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public Taml(string pName) : base(pName)
      {
      }

      public Taml(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string TamlGetFormat(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetFormat(IntPtr tamlObj, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool TamlGetJSONStrict(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetJSONStrict(IntPtr tamlObj, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool TamlGetBinaryCompression(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetBinaryCompression(IntPtr tamlObj, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool TamlGetWriteDefaults(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetWriteDefaults(IntPtr tamlObj, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool TamlGetProgenitorUpdate(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetProgenitorUpdate(IntPtr tamlObj, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool TamlGetAutoFormat(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetAutoFormat(IntPtr tamlObj, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string TamlGetAutoFormatXmlExtension(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetAutoFormatXmlExtension(IntPtr tamlObj, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string TamlGetAutoFormatBinaryExtension(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetAutoFormatBinaryExtension(IntPtr tamlObj, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string TamlGetAutoFormatJSONExtension(IntPtr tamlObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TamlSetAutoFormatJSONExtension(IntPtr tamlObj, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr TamlCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool TamlWrite(IntPtr tamlObj, IntPtr simObj, string filename);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr TamlRead(IntPtr tamlObj, string filename);
      }
      
      #endregion

      #region Properties

      public string Format
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetFormat(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetFormat(ObjectPtr->ObjPtr, value);
         }
      }
      public bool JSONStrict
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetJSONStrict(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetJSONStrict(ObjectPtr->ObjPtr, value);
         }
      }
      public bool BinaryCompression
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetBinaryCompression(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetBinaryCompression(ObjectPtr->ObjPtr, value);
         }
      }
      public bool WriteDefaults
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetWriteDefaults(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetWriteDefaults(ObjectPtr->ObjPtr, value);
         }
      }
      public bool ProgenitorUpdate
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetProgenitorUpdate(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetProgenitorUpdate(ObjectPtr->ObjPtr, value);
         }
      }
      public bool AutoFormat
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetAutoFormat(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetAutoFormat(ObjectPtr->ObjPtr, value);
         }
      }
      public string AutoFormatXmlExtension
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetAutoFormatXmlExtension(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetAutoFormatXmlExtension(ObjectPtr->ObjPtr, value);
         }
      }
      public string AutoFormatBinaryExtension
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetAutoFormatBinaryExtension(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetAutoFormatBinaryExtension(ObjectPtr->ObjPtr, value);
         }
      }
      public string AutoFormatJSONExtension
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TamlGetAutoFormatJSONExtension(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TamlSetAutoFormatJSONExtension(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      public void Write(SimObject simObj, string filename)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.TamlWrite(ObjectPtr->ObjPtr, simObj.ObjectPtr->ObjPtr, filename);
      }

      public void Read(string filename)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.TamlRead(ObjectPtr->ObjPtr, filename);
      }
      
      #endregion
   }
}