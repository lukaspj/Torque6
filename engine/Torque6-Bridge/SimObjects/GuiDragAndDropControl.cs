using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiDragAndDropControl : GuiControl
   {
      public GuiDragAndDropControl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiDragAndDropControlCreateInstance());
      }

      public GuiDragAndDropControl(uint pId) : base(pId)
      {
      }

      public GuiDragAndDropControl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiDragAndDropControl(string pName) : base(pName)
      {
      }

      public GuiDragAndDropControl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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