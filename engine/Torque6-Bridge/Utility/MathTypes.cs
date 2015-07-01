using System.Runtime.InteropServices;

namespace Torque6_Bridge.Types
{
   [StructLayout(LayoutKind.Sequential)]
   public struct ColorI
   {
      public int R;
      public int G;
      public int B;
      public int A;
   }

   [StructLayout(LayoutKind.Sequential)]
   public struct Point2I
   {
      public int x;
      public int y;
   }

   [StructLayout(LayoutKind.Sequential)]
   public struct Point2F
   {
      public float x;
      public float y;
   }

   [StructLayout(LayoutKind.Sequential)]
   public struct Point3I
   {
      public int x;
      public int y;
      public int z;
   }

   [StructLayout(LayoutKind.Sequential)]
   public struct Point3F
   {
      public float x;
      public float y;
      public float z;
   }
}