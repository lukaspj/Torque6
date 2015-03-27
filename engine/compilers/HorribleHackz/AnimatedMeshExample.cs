using System;
using HorribleHackz.CustomAttributes;
using IJWLayer;

namespace HorribleHackz
{
   [ConsoleClass]
   class AnimatedMeshExample
   {
      public static void create()
      {
         SceneEntityWrapper entity1 = new SceneEntityWrapper()
         {
            Template = "^AnimatedMeshExample/entities/bigDwarfRedDwarf.taml",
            Position = "0 0 0",
            Rotation = "0 0 0"
         };
         entity1.registerObject();
         IJWLayer.Scene.addEntity(entity1, "Dwarf Meshes");

         SceneEntityWrapper light1 = new SceneEntityWrapper()
         {
            Template = IJWLayer.Con.expandPath("^AnimatedMeshExample/entities/lightTest2.taml"),
            Position = "0 0 0"
         };
         IJWLayer.Scene.addEntity(light1, "Lights");

         IJWLayer.Scene.setDirectionalLight("1 1 -1", "0.8 0.8 0.8", "0.1 0.1 0.1");
      }
      public static void destroy()
      {
         IJWLayer.Con.print("DESTROYED AnimatedMeshExample MODULE");
      }
   }
}
