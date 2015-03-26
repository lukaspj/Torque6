using System;
using System.Runtime.InteropServices;

namespace HorribleHackz.Framework
{
   public static class Torque6Main
   {
      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate int T6Main(int pArgc, string[] pArgv, IntPtr pHInstance);

      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate void T6SetCallFunction(IntPtr pFunctionPtr, IntPtr pMethodPtr, IntPtr pIsMethodPtr, IntPtr pMainPtr);

      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate bool IsMethod(string className, string methodName);

      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate void MainEntryPoint();

      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate string CallFunction(string name, IntPtr argv, int argc, [MarshalAs(UnmanagedType.I1)] out bool result);

      [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
      public delegate string CallMethod(string className
                                       , uint obj
                                       , string name
                                       , IntPtr argv
                                       , int argc
                                       , [MarshalAs(UnmanagedType.I1)] out bool result);

      public struct Libraries
      {
         public string Windows32bit;
         public string Windows64bit;
         public string Linux32bit;
         public string Linux64bit;
      }

      public static void InitializeTorque6(string[] args, Libraries libraryNames)
      {
         IDllLoadUtils dllLoadUtils = Platform.IsLinux() ? (IDllLoadUtils)new DllLoadUtilsLinux()
                                                                                             : new DllLoadUtilsWindows();
         string libraryName;

         if (Platform.IsLinux())
         {
            libraryName = IntPtr.Size == 8 ? libraryNames.Linux64bit : libraryNames.Linux32bit;
         }
         else
         {
            libraryName = IntPtr.Size == 8 ? libraryNames.Windows64bit : libraryNames.Windows32bit;
         }

         var dllHandle = dllLoadUtils.LoadLibrary(libraryName);
         var mainHandle = dllLoadUtils.GetProcAddress(dllHandle, "main");
         var setCallbacksHandle = dllLoadUtils.GetProcAddress(dllHandle, "SetCallbacks");

         var setCallbacks = (T6SetCallFunction)Marshal.GetDelegateForFunctionPointer(
                        setCallbacksHandle, typeof(T6SetCallFunction));

         var main = (T6Main)Marshal.GetDelegateForFunctionPointer(
                        mainHandle, typeof(T6Main));

         Initializer.InitializeTypeDictionaries();

         CallFunction callDelegate = CallFunctionDelegate;
         CallMethod methodDelegate = CallMethodDelegate;
         IsMethod isMethodDelegate = IsMethodDelegate;
         IntPtr mainEntryPointPtr = IntPtr.Zero;
         if (Initializer.GetScriptEntry() != null)
            mainEntryPointPtr = Marshal.GetFunctionPointerForDelegate((MainEntryPoint)Initializer.GetScriptEntry().CreateDelegate(typeof(MainEntryPoint)));

         setCallbacks(Marshal.GetFunctionPointerForDelegate(callDelegate)
            , Marshal.GetFunctionPointerForDelegate(methodDelegate)
            , Marshal.GetFunctionPointerForDelegate(isMethodDelegate)
            , mainEntryPointPtr);

         main(args.Length, args, IntPtr.Zero);
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
