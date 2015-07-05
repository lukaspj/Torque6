using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorTypeColorF : GuiInspectorTypeColor
   {
      public GuiInspectorTypeColorF()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorTypeColorFCreateInstance());
      }

      public GuiInspectorTypeColorF(uint pId) : base(pId)
      {
      }

      public GuiInspectorTypeColorF(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorTypeColorF(string pName) : base(pName)
      {
      }

      public GuiInspectorTypeColorF(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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