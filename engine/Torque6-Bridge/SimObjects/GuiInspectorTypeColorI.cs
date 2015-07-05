using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorTypeColorI : GuiInspectorTypeColor
   {
      public GuiInspectorTypeColorI()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorTypeColorICreateInstance());
      }

      public GuiInspectorTypeColorI(uint pId) : base(pId)
      {
      }

      public GuiInspectorTypeColorI(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorTypeColorI(string pName) : base(pName)
      {
      }

      public GuiInspectorTypeColorI(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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