using HorribleHackz.CustomAttributes;
using IJWLayerTest;

namespace HorribleHackz
{
   internal class MainClass
   {

      [ScriptEntryPoint]
      public static void EntryPoint()
      {
         SimObject obj =  new SimObject();
         obj.registerObject();
         Con.quit();
      }
   }
}