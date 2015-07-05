using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorTypeColor : GuiInspectorField
   {
      public GuiInspectorTypeColor()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorTypeColorCreateInstance());
      }

      public GuiInspectorTypeColor(uint pId) : base(pId)
      {
      }

      public GuiInspectorTypeColor(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorTypeColor(string pName) : base(pName)
      {
      }

      public GuiInspectorTypeColor(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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