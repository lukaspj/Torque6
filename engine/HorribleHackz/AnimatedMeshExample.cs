using HorribleHackz.CustomAttributes;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.SimObjects;
using Torque6_Bridge.SimObjects.Scene;
using Torque6_Bridge.Types;

namespace HorribleHackz
{
   //[ConsoleClass]
   internal class AnimatedMeshExample
   {
      public static void create()
      {
         // Create some dwarfs!
         SceneEntity entity1 = new SceneEntity
         {
            Template = "AnimatedMeshExample:BigDwarfRedDwarf",
            Position = Point3F.Zero(),
            Rotation = Point3F.Zero()
         };

         // Register the object! (Similar to how you do it in C++)
         entity1.RegisterObject();

         // Add it to the scene!
         Scene.AddEntity(entity1, "Dwarf Meshes");

         // Let there be lights!
         SceneEntity light1 = new SceneEntity
         {
            Template = "AnimatedMeshExample:lightTest2",
            Position = Point3F.Zero()
         };
         light1.RegisterObject();
         Scene.AddEntity(light1, "Lights");

         // More lights I guess
         Scene.SetDirectionalLight(new Point3F(1, 1, -1), new Color(0.8f, 0.8f, 0.8f), new Color(0.1f, 0.1f, 0.1f));
      }

      public static void destroy()
      {
         Console.Print("DESTROYED AnimatedMeshExample MODULE");
      }
   }
}