using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
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

      public GuiInspectorField(string pName) : base(pName)
      {
      }

      public GuiInspectorField(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorField(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiInspectorField(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiInspectorFieldCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}