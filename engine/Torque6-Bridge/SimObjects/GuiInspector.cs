using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspector : GuiStackControl
   {
      public GuiInspector()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorCreateInstance());
      }

      public GuiInspector(uint pId) : base(pId)
      {
      }

      public GuiInspector(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspector(string pName) : base(pName)
      {
      }

      public GuiInspector(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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