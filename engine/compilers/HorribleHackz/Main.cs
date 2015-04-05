using System;
using System.IO;
using System.Reflection;
using HorribleHackz.CustomAttributes;
using IJWLayer;

namespace HorribleHackz
{
   internal class MainClass
   {
      public static ModuleManager ModuleDatabase;
      public static AssetManager AssetDatabase;

      [ScriptEntryPoint]
      public static void EntryPoint()
      {
         // Mandatory initialization, since these can't be set based on the non-existant main.cs
         var CSDir = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location);
         Engine.Platform.setMainDotCsDir(CSDir);
         Engine.Platform.setCurrentDirectory(CSDir);

         // Logging settings
         Engine.Con.setLogMode(2);
         Engine.Script.setScriptExecEcho(false);
         Engine.Script.trace(false);

         // Not really necessary, but shows how globals work
         Globals.SetBool("Scripts::ignoreDSOs", true);

         // This is my realm!
         Engine.Version.setCompanyAndProduct("LukasPJ", "Torque6");

         // Find the Databases by name
         ModuleDatabase = ModuleManager.Wrap("ModuleDatabase");
         AssetDatabase = AssetManager.Wrap("AssetDatabase");

         // Make sure they have been created
         if (!ModuleDatabase.IsAlive())
            throw new Exception("ModuleDatabase not found");
         if (!AssetDatabase.IsAlive())
            throw new Exception("AssetDatabase not found");

         // Didn't implement this property yet.
         ModuleDatabase.setFieldValue("EchoInfo", "false");
         AssetDatabase.EchoInfo = false;
         AssetDatabase.IgnoreAutoUnload = true;

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
         // Quit on button down
         if (val == "1")
            Engine.Con.quit();
      }
   }
}