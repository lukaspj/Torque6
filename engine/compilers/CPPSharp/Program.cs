using System;
using CppSharp;

namespace CPPSharp
{
   class Program
   {
      static void Main(string[] args)
      {
         ConsoleDriver.Run(new Torque6Library());
         Console.ReadKey();
      }
   }
}
