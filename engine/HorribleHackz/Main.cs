using System;
using HorribleHackz.CustomAttributes;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.SimObjects;
using Console = Torque6_Bridge.Namespaces.Console;
using Version = Torque6_Bridge.Namespaces.Version;

//using IJWLayer;

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
         //var CSDir = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location);
         //Engine.Platform.setMainDotCsDir(CSDir);
         //Engine.Platform.setCurrentDirectory(CSDir);

         // Logging settings
         Console.SetLogMode(2);
         Console.PrintEchoFileLoads(false);
         //Engine.Script.trace(false);

         // Not really necessary, but shows how globals work
         //Globals.SetBool("Scripts::ignoreDSOs", true);

         // This is my realm!
         Version.SetCompanyAndProduct("LukasPJ", "Torque6");

         // Find the Databases by name
         ModuleDatabase = new ModuleManager("ModuleDatabase");
         AssetDatabase = new AssetManager("AssetDatabase");

         // Make sure they have been created
         if (ModuleDatabase.IsDead())
            throw new Exception("ModuleDatabase not found");
         if (AssetDatabase.IsDead())
            throw new Exception("AssetDatabase not found");

         AssetDatabase.EchoInfo = false;
         AssetDatabase.IgnoreAutoUnload = true;

         // Scan modules.
         ModuleDatabase.ScanModules("modules", true);

         ModuleDatabase.ScanModules("../shared-modules", true);

         // Load AppCore module.
         ModuleDatabase.LoadExplicit("AppCore", -1);

         // Load the modules needed for this example
         ModuleDatabase.LoadExplicit("Console", -1);
         ModuleDatabase.LoadExplicit("FreeViewCamera", -1);
      }

      [ConsoleFunction]
      public static void onExit()
      {
         // Unload the AppCore module.
         ModuleDatabase.UnloadExplicit("AppCore");
      }

      [ConsoleFunction]
      public static void androidBackButton(string val)
      {
         // Quit on button down
         if (val == "1")
            Engine.Quit();
      }
   }
}