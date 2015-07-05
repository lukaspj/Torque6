using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorTypeGuiProfile : GuiInspectorTypeEnum
   {
      public GuiInspectorTypeGuiProfile()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorTypeGuiProfileCreateInstance());
      }

      public GuiInspectorTypeGuiProfile(uint pId) : base(pId)
      {
      }

      public GuiInspectorTypeGuiProfile(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorTypeGuiProfile(string pName) : base(pName)
      {
      }

      public GuiInspectorTypeGuiProfile(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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