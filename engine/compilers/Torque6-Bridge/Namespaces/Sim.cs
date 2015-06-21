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

      [DllImport("CInterfaceDLL", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SimFindObject")]
      private static extern IntPtr SimFindObject(int pId);

      public static IntPtr FindObject(int pId)
      {
         return SimFindObject(pId);
      }

      [DllImport("CInterfaceDLL", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SimFindObject")]
      private static extern IntPtr SimFindObjectWrapper(int pId);

      public static SimObjectPtr* FindObjectWrapper(int pId)
      {
         return (SimObjectPtr*)SimFindObjectWrapper(pId);
      }
   }
}
