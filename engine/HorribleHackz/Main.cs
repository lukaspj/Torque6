using System;
using System.IO;
using System.Reflection;
using HorribleHackz.CustomAttributes;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.SimObjects;
using Console = Torque6_Bridge.Namespaces.Console;
using Version = Torque6_Bridge.Namespaces.Version;

namespace HorribleHackz
{
   internal class MainClass
   {
      public static ModuleManager ModuleDatabase;
      public static AssetManager AssetDatabase;

      [ScriptEntryPoint]
      public static void EntryPoint()
      {
         RunMaterialsProjects();
      }

      private static void RunMaterialsProjects()
      {
         // Mandatory initialization, since these can't be set based on the non-existant main.cs
         string CSDir = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location);
         CSDir = "E:\\GitHub\\Torque6\\projects\\06-Materials";
         Engine.SetMainDotCsDir(CSDir);
         Engine.SetCurrentDirectory(CSDir);

         // Logging settings
         Console.SetLogMode(2);
         Console.PrintEchoFileLoads(true);

         Script.Trace(false);

         // Not really necessary, but shows how globals work
         Globals.SetBool("Scripts::ignoreDSOs", true);

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

         ModuleDatabase.EchoInfo = true;

         AssetDatabase.EchoInfo = true;
         AssetDatabase.IgnoreAutoUnload = true;

         // Scan modules.
         ModuleDatabase.ScanModules("modules");

         ModuleDatabase.ScanModules("../shared-modules");

         // Load AppCore module.
         ModuleDatabase.LoadExplicit("AppCore");

         // Load the modules needed for this example
         ModuleDatabase.LoadExplicit("Console");
         ModuleDatabase.LoadExplicit("FreeViewCamera");
         ModuleDatabase.LoadExplicit("ExampleRoom");
         ModuleDatabase.LoadExplicit("Skybox");

         // Editor is not required, but try to load it anyway.
         ModuleDatabase.LoadExplicit("Editor");

         // Load the example itself.
         ModuleDatabase.LoadExplicit("MaterialExample");
      }

      private static void RunAnimatedMeshProjected()
      {
         // Mandatory initialization, since these can't be set based on the non-existant main.cs
         string CSDir = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location);
         CSDir = "E:\\GitHub\\Torque6\\projects\\01-AnimatedMesh";
         Engine.SetMainDotCsDir(CSDir);
         Engine.SetCurrentDirectory(CSDir);

         // Logging settings
         Console.SetLogMode(2);
         Console.PrintEchoFileLoads(false);
         Script.Trace(false);

         // Not really necessary, but shows how globals work
         Globals.SetBool("Scripts::ignoreDSOs", true);

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
         ModuleDatabase.ScanModules("modules");

         ModuleDatabase.ScanModules("../shared-modules");

         // Load AppCore module.
         ModuleDatabase.LoadExplicit("AppCore");

         // Load the modules needed for this example
         ModuleDatabase.LoadExplicit("Console");
         ModuleDatabase.LoadExplicit("FreeViewCamera");
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