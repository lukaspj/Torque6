using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorTypeEnum : GuiInspectorField
   {
      public GuiInspectorTypeEnum()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorTypeEnumCreateInstance());
      }

      public GuiInspectorTypeEnum(uint pId) : base(pId)
      {
      }

      public GuiInspectorTypeEnum(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorTypeEnum(string pName) : base(pName)
      {
      }

      public GuiInspectorTypeEnum(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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