using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorTypeCheckBox : GuiInspectorField
   {
      public GuiInspectorTypeCheckBox()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorTypeCheckBoxCreateInstance());
      }

      public GuiInspectorTypeCheckBox(uint pId) : base(pId)
      {
      }

      public GuiInspectorTypeCheckBox(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorTypeCheckBox(string pName) : base(pName)
      {
      }

      public GuiInspectorTypeCheckBox(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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