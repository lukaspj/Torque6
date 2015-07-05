using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class Achievement : SimObject
   {
      public Achievement()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.AchievementCreateInstance());
      }

      public Achievement(uint pId) : base(pId)
      {
      }

      public Achievement(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public Achievement(string pName) : base(pName)
      {
      }

      public Achievement(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
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