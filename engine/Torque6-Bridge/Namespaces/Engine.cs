using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.SimObjects;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.Namespaces
{
   public static unsafe class Engine
   {
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void CopyBehaviorToComponent(IntPtr behavior, IntPtr component);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void DeactivatePackage(string packageName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void Quit();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void QuitWithErrorMessage(string msg);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string Detag(int tagId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string GetTag(string taggedString);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GetStockColorCount();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string GetStockColorCount(int index);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool IsStockColor(string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern Color GetStockColor(string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool CaptureScreenArea(int posX, int posY, uint width, uint height, string fileName, string fileType);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool PNG2JPG(string bmpname, uint quality);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ShowStats(bool enable);
      }

      #endregion
      
      #region Functions

      public static void CopyBehaviorToComponent(BehaviorInstance behavior, SimComponent component)
      {
         InternalUnsafeMethods.CopyBehaviorToComponent(behavior.ObjectPtr->ObjPtr, component.ObjectPtr->ObjPtr);
      }

      public static void DeactivatePackage(string packageName)
      {
         InternalUnsafeMethods.DeactivatePackage(packageName);
      }

      public static void Quit()
      {
         InternalUnsafeMethods.Quit();
      }

      public static void QuitWithErrorMessage(string msg)
      {
         InternalUnsafeMethods.QuitWithErrorMessage(msg);
      }

      public static string Detag(int tagId)
      {
         return InternalUnsafeMethods.Detag(tagId);
      }

      public static string GetTag(string taggedString)
      {
         return InternalUnsafeMethods.GetTag(taggedString);
      }

      public static int GetStockColorCount()
      {
         return InternalUnsafeMethods.GetStockColorCount();
      }

      public static string GetStockColorCount(int index)
      {
         return InternalUnsafeMethods.GetStockColorCount(index);
      }

      public static bool IsStockColor(string name)
      {
         return InternalUnsafeMethods.IsStockColor(name);
      }

      public static Color GetStockColor(string name)
      {
         return InternalUnsafeMethods.GetStockColor(name);
      }

      public static bool CaptureScreenArea(int posX, int posY, uint width, uint height, string fileName, string fileType)
      {
         return InternalUnsafeMethods.CaptureScreenArea(posX, posY, width, height, fileName, fileType);
      }

      public static bool PNG2JPG(string bmpname, uint quality)
      {
         return InternalUnsafeMethods.PNG2JPG(bmpname, quality);
      }

      public static void ShowStats(bool enable)
      {
         InternalUnsafeMethods.ShowStats(enable);
      }      

      #endregion
   }
}