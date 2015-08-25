using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiMenuBar : GuiTickCtrl
   {
      
      public GuiMenuBar()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiMenuBarCreateInstance());
      }

      public GuiMenuBar(uint pId) : base(pId)
      {
      }

      public GuiMenuBar(string pName) : base(pName)
      {
      }

      public GuiMenuBar(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMenuBar(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiMenuBar(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiMenuBarGetPadding(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiMenuBarSetPadding(IntPtr ctrl, int padding);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiMenuBarCreateInstance();
      }
      
      #endregion

      #region Properties

      public int Padding
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiMenuBarGetPadding(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiMenuBarSetPadding(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}