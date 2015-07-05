using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class DynamicConsoleMethodComponent : SimComponent
   {
      public DynamicConsoleMethodComponent()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.DynamicConsoleMethodComponentCreateInstance());
      }

      public DynamicConsoleMethodComponent(uint pId) : base(pId)
      {
      }

      public DynamicConsoleMethodComponent(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public DynamicConsoleMethodComponent(string pName) : base(pName)
      {
      }

      public DynamicConsoleMethodComponent(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr DynamicConsoleMethodComponentCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string DynamicConsoleMethodComponentCallOnBehaviors(IntPtr component, string methodName, int argc, string[] argv);
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      public void CallOnBehaviors(string methodName, int argc, string[] argv)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.DynamicConsoleMethodComponentCallOnBehaviors(ObjectPtr->ObjPtr, methodName, argc, argv);
      }
      
      #endregion
   }
}