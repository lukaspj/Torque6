using HorribleHackz.Framework;

namespace HorribleHackz
{
   class Program
   {
      static void Main(string[] args)
      {
         Torque6Main.Libraries libraries = new Torque6Main.Libraries()
         {
            Windows32bit = "Torque6_DEBUG.dll",
            Windows64bit = "Torque6_DEBUG.dll",
            Linux32bit = "Torque6_DEBUG.so",
            Linux64bit = "Torque6_DEBUG.so",
         };
         Torque6Main.InitializeTorque6(args, libraries);
      }
   }
}
