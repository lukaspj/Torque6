using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorGroup : GuiRolloutCtrl
   {
      public GuiInspectorGroup()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorGroupCreateInstance());
      }

      public GuiInspectorGroup(uint pId) : base(pId)
      {
      }

      public GuiInspectorGroup(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorGroup(string pName) : base(pName)
      {
      }

      public GuiInspectorGroup(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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