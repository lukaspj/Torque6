using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorField : GuiControl
   {
      public GuiInspectorField()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorFieldCreateInstance());
      }

      public GuiInspectorField(uint pId) : base(pId)
      {
      }

      public GuiInspectorField(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorField(string pName) : base(pName)
      {
      }

      public GuiInspectorField(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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