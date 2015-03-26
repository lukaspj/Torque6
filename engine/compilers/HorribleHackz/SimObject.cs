using System;
using HorribleHackz.CustomAttributes;
using IJWLayer;

namespace HorribleHackz
{
   class MainClass
   {
      public static ModuleManagerWrapper ModuleDatabase;
      public static AssetManagerWrapper AssetDatabase;
      [ScriptEntryPoint]
      public static void EntryPoint()
      {
         string CSDir = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetEntryAssembly().Location);
         Platform.setMainDotCsDir(CSDir);
         Platform.setCurrentDirectory(CSDir);
         
         IJWLayer.Con.setLogMode(2);
         Script.setScriptExecEcho(false);
         Script.trace(false);
         Global.SetBool("Scripts::ignoreDSOs", true);

         EngineVersion.setCompanyAndProduct("LukasPJ", "Torque6");

         ModuleDatabase = new ModuleManagerWrapper(SimObjectWrapper.GetID("ModuleDatabase"));
         AssetDatabase = new AssetManagerWrapper(SimObjectWrapper.GetID("AssetDatabase"));
         if(!ModuleDatabase.IsAlive())
            throw new Exception("ModuleDatabase not found");
         ModuleDatabase.setFieldValue("EchoInfo", "false");
         AssetDatabase.setFieldValue("EchoInfo", "false");
         AssetDatabase.setFieldValue("IgnoreAutoUnload", "true");

         // Scan modules.
         ModuleDatabase.scanModules("modules");

         ModuleDatabase.scanModules("../shared-modules");

         // Load AppCore module.
         ModuleDatabase.loadExplicit("AppCore");

         // Load the modules needed for this example
         ModuleDatabase.loadExplicit("Console");
         ModuleDatabase.loadExplicit("FreeViewCamera");
      }

      [ConsoleFunction]
      public static void onExit()
      {
         // Unload the AppCore module.
         ModuleDatabase.unloadExplicit("AppCore");
      }

      [ConsoleFunction]
      public static void androidBackButton(string val)
      {
         if (val == "1")
            IJWLayer.Con.quit();
      }
   }
}
