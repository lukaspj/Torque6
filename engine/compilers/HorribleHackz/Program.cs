using System;
using System.Linq;
using System.Runtime.InteropServices;
using IJWLayer;

namespace HorribleHackz
{
   class Program
   {
      [DllImport("Torque6_DEBUG.dll", EntryPoint = "main", CallingConvention = CallingConvention.Cdecl)]
      public static extern int T6Main(int pArgc, string[] pArgv, IntPtr pHInstance);

      [DllImport("Torque6_DEBUG.dll", EntryPoint = "SetCallbacks", CallingConvention = CallingConvention.Cdecl)]
      public static extern int T6SetCallFunction(IntPtr pFunctionPtr, IntPtr pMethodPtr, IntPtr pIsMethodPtr);

      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate bool IsMethod(string className, string methodName);

      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate string CallFunction(string name, IntPtr argv, int argc, [MarshalAs(UnmanagedType.I1)] out bool result);

      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate string CallMethod( string className
                                       , uint obj
                                       , string name
                                       , IntPtr argv
                                       , int argc
                                       , [MarshalAs(UnmanagedType.I1)] out bool result);

      static void Main(string[] args)
      {
         Initializer.InitializeTypeDictionaries();

         CallFunction callDelegate = CallFunctionDelegate;
         CallMethod methodDelegate = CallMethodDelegate;
         IsMethod isMethodDelegate = IsMethodDelegate;
         T6SetCallFunction(Marshal.GetFunctionPointerForDelegate(callDelegate)
            , Marshal.GetFunctionPointerForDelegate(methodDelegate)
            , Marshal.GetFunctionPointerForDelegate(isMethodDelegate));

         T6Main(args.Count(), args, IntPtr.Zero);
      }

      public static string CallFunctionDelegate(string name, IntPtr argv, int argc, out bool result)
      {
         string[] strings = CustomMarshalling.IntPtrToStringArray(argv, argc);
         return EngineCallbacks.CallScriptFunction(name, strings, out result);
      }

      public static string CallMethodDelegate(string className, uint obj, string name, IntPtr argv, int argc, out bool result)
      {
         string[] strings = CustomMarshalling.IntPtrToStringArray(argv, argc);
         return EngineCallbacks.CallScriptMethod(className, obj, name, strings, out result);
      }

      public static bool IsMethodDelegate(string className, string methodName)
      {
         return EngineCallbacks.IsMethod(className, methodName);
      }
   }
}
