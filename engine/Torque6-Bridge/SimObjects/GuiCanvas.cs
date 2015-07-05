using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GuiCanvas : GuiControl
   {
      public GuiCanvas()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiCanvasCreateInstance());
      }

      public GuiCanvas(uint pId) : base(pId)
      {
      }

      public GuiCanvas(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiCanvas(string pName) : base(pName)
      {
      }

      public GuiCanvas(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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