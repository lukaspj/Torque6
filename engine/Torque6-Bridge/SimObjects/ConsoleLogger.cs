using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class ConsoleLogger : SimObject
   {
      public ConsoleLogger()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.ConsoleLoggerCreateInstance());
      }

      public ConsoleLogger(uint pId) : base(pId)
      {
      }

      public ConsoleLogger(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public ConsoleLogger(string pName) : base(pName)
      {
      }

      public ConsoleLogger(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int ConsoleLoggerGetLevel(IntPtr logger);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ConsoleLoggerSetLevel(IntPtr logger, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ConsoleLoggerCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ConsoleLoggerAttach(IntPtr logger);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ConsoleLoggerDetach(IntPtr logger);


      }
      #endregion

      #region Properties

      public int Level
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.ConsoleLoggerGetLevel(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.ConsoleLoggerSetLevel(ObjectPtr->ObjPtr, value);
         }
      }

      #endregion
      
      #region Methods

      public void Attach()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ConsoleLoggerAttach(ObjectPtr->ObjPtr);
      }

      public void Detach()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ConsoleLoggerDetach(ObjectPtr->ObjPtr);
      }

      #endregion
   }
}