using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.SimObjects;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.Namespaces
{
   public static unsafe class Script
   {
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void Script_DumpConsoleClasses(bool dumpScript, bool dumpEngine);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void Script_DumpConsoleFunctions(bool dumpScript, bool dumpEngine);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void Script_Backtrace();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool Script_IsPackage(string packageName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void Script_ActivatePackage(string packageName);
      }

      #endregion
      
      #region Functions

      public static void DumpConsoleClasses(bool dumpScript, bool dumpEngine)
      {
         InternalUnsafeMethods.Script_DumpConsoleClasses(dumpScript, dumpEngine);
      }

      public static void DumpConsoleFunctions(bool dumpScript, bool dumpEngine)
      {
         InternalUnsafeMethods.Script_DumpConsoleFunctions(dumpScript, dumpEngine);
      }

      public static void Backtrace()
      {
         InternalUnsafeMethods.Script_Backtrace();
      }

      public static bool IsPackage(string packageName)
      {
         return InternalUnsafeMethods.Script_IsPackage(packageName);
      }

      public static void ActivatePackage(string packageName)
      {
         InternalUnsafeMethods.Script_ActivatePackage(packageName);
      }      

      #endregion
   }
}