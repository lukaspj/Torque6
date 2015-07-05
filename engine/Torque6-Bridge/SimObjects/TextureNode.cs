using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class TextureNode : BaseNode
   {
      public TextureNode()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.TextureNodeCreateInstance());
      }

      public TextureNode(uint pId) : base(pId)
      {
      }

      public TextureNode(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public TextureNode(string pName) : base(pName)
      {
      }

      public TextureNode(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int TextureNodeGetSlot(IntPtr textureNode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TextureNodeSetSlot(IntPtr textureNode, int slot);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool TextureNodeGetPremultiplyAlpha(IntPtr textureNode);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void TextureNodeSetPremultiplyAlpha(IntPtr textureNode, bool val);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr TextureNodeCreateInstance();
      }
      
      #endregion

      #region Properties

      public int Slot
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TextureNodeGetSlot(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TextureNodeSetSlot(ObjectPtr->ObjPtr, value);
         }
      }
      public bool PremultiplyAlpha
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.TextureNodeGetPremultiplyAlpha(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.TextureNodeSetPremultiplyAlpha(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}