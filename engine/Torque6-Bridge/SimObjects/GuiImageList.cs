using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
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

      public GuiImageList(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiImageList(string pName) : base(pName)
      {
      }

      public GuiImageList(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}