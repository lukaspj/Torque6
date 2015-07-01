using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class UndoScriptAction : UndoAction
   {
      public UndoScriptAction()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.UndoScriptActionCreateInstance());
      }

      public UndoScriptAction(uint pId) : base(pId)
      {
      }

      public UndoScriptAction(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public UndoScriptAction(string pName) : base(pName)
      {
      }

      public UndoScriptAction(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr UndoScriptActionCreateInstance();


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      #endregion
   }
}