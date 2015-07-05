using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class ScriptMsgListener : SimObject
   {
      public ScriptMsgListener()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.ScriptMsgListenerCreateInstance());
      }

      public ScriptMsgListener(uint pId) : base(pId)
      {
      }

      public ScriptMsgListener(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public ScriptMsgListener(string pName) : base(pName)
      {
      }

      public ScriptMsgListener(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ScriptMsgListenerCreateInstance();
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      
      
      #endregion
   }
}