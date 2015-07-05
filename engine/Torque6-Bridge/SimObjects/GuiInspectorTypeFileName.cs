using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorTypeFileName : GuiInspectorField
   {
      public GuiInspectorTypeFileName()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorTypeFileNameCreateInstance());
      }

      public GuiInspectorTypeFileName(uint pId) : base(pId)
      {
      }

      public GuiInspectorTypeFileName(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorTypeFileName(string pName) : base(pName)
      {
      }

      public GuiInspectorTypeFileName(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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