using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiInspectorDynamicField : GuiInspectorField
   {
      
      public GuiInspectorDynamicField()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorDynamicFieldCreateInstance());
      }

      public GuiInspectorDynamicField(uint pId) : base(pId)
      {
      }

      public GuiInspectorDynamicField(string pName) : base(pName)
      {
      }

      public GuiInspectorDynamicField(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorDynamicField(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorDynamicField(SimObject pObj) : base(pObj)
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