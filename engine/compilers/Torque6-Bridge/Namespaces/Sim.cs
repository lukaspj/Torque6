using System;
using System.Runtime.InteropServices;

namespace Torque6_Bridge.Namespaces
{
   public unsafe class Sim
   {
      [StructLayout(LayoutKind.Explicit, Size = 4)]
      public partial struct SimObjectPtr
      {
         [FieldOffset(0)] public IntPtr ObjPtr;
      }

      [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
      private static extern IntPtr SimFindObjectById(int pId);

      public static IntPtr FindObject(int pId)
      {
         return SimFindObjectById(pId);
      }

      [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
      private static extern IntPtr SimFindObjectWrapperById(int pId);

      public static SimObjectPtr* FindObjectWrapper(int pId)
      {
         return (SimObjectPtr*)SimFindObjectWrapperById(pId);
      }

      [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
      private static extern IntPtr SimFindObjectByName([MarshalAs(UnmanagedType.LPStr)]string pName);

      public static IntPtr FindObject(string pName)
      {
         return SimFindObjectByName(pName);
      }

      [DllImport("Torque6_DEBUG.dll", CallingConvention = CallingConvention.Cdecl)]
      private static extern IntPtr SimFindObjectWrapperByName([MarshalAs(UnmanagedType.LPStr)]string pName);

      public static SimObjectPtr* FindObjectWrapper(string pName)
      {
         return (SimObjectPtr*)SimFindObjectWrapperByName(pName);
      }
   }
}
