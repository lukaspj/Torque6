using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class AndroidStreamSource : SimObject
   {
      public AndroidStreamSource()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AndroidStreamSourceCreateInstance());
      }

      public AndroidStreamSource(uint pId) : base(pId)
      {
      }

      public AndroidStreamSource(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public AndroidStreamSource(string pName) : base(pName)
      {
      }

      public AndroidStreamSource(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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