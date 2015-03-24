using System;
using HorribleHackz.CustomAttributes;
using IJWLayer;

namespace HorribleHackz
{
   [ConsoleClass]
   class SimObject
   {
      public void onAdd()
      {
         SimObjectWrapper wrapper = new SimObjectWrapper(SimObjectWrapper.GetID("Test"));
         bool isitmethod = wrapper.isMethod("getName");
      }

      [ConsoleFunction]
      public static string TestConsoleFunction(string res)
      {
         Console.WriteLine("TestConsoleFunction");
         return res;
      }

      [ConsoleFunction]
      public static void BeforeQuit()
      {
      }
   }
}
