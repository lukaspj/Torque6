using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiInspectorDatablockField : GuiInspectorField
   {
      public GuiInspectorDatablockField()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiInspectorDatablockFieldCreateInstance());
      }

      public GuiInspectorDatablockField(uint pId) : base(pId)
      {
      }

      public GuiInspectorDatablockField(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorDatablockField(string pName) : base(pName)
      {
      }

      public GuiInspectorDatablockField(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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