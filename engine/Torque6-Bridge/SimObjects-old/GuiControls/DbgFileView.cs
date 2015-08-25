using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class DbgFileView : GuiArrayCtrl
   {
      
      public DbgFileView()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.DbgFileViewCreateInstance());
      }

      public DbgFileView(uint pId) : base(pId)
      {
      }

      public DbgFileView(string pName) : base(pName)
      {
      }

      public DbgFileView(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public DbgFileView(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public DbgFileView(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr DbgFileViewCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}