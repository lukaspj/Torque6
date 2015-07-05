using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class PNGImage : SimObject
   {
      public PNGImage()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.PNGImageCreateInstance());
      }

      public PNGImage(uint pId) : base(pId)
      {
      }

      public PNGImage(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public PNGImage(string pName) : base(pName)
      {
      }

      public PNGImage(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr PNGImageCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool PNGImageCreateBaseImage(IntPtr image, int width, int height, int imageType);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool PNGImageMergeOn(IntPtr image, int width, int height, string imageFile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool PNGImageSaveImage(IntPtr image, string fileName);
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      public void CreateBaseImage(int width, int height, int imageType)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.PNGImageCreateBaseImage(ObjectPtr->ObjPtr, width, height, imageType);
      }

      public void MergeOn(int width, int height, string imageFile)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.PNGImageMergeOn(ObjectPtr->ObjPtr, width, height, imageFile);
      }

      public void SaveImage(string fileName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.PNGImageSaveImage(ObjectPtr->ObjPtr, fileName);
      }
      
      #endregion
   }
}