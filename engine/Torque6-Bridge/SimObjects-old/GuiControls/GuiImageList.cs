using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiImageList : SimObject
   {
      
      public GuiImageList()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiImageListCreateInstance());
      }

      public GuiImageList(uint pId) : base(pId)
      {
      }

      public GuiImageList(string pName) : base(pName)
      {
      }

      public GuiImageList(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiImageList(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiImageList(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiImageListCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}