using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
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

      public DbgFileView(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public DbgFileView(string pName) : base(pName)
      {
      }

      public DbgFileView(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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