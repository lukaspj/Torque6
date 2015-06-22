//using HorribleHackz.CustomAttributes;
//using IJWLayer;

//namespace HorribleHackz
//{
//   [ConsoleClass]
//   internal class AnimatedMeshExample
//   {
//      public static void create()
//      {
//         // Create some dwarfs!
//         SceneEntity entity1 = new SceneEntity
//         {
//            Template = "^AnimatedMeshExample/entities/bigDwarfRedDwarf.taml",
//            Position = Point3F.Zero(),
//            Rotation = Point3F.Zero()
//         };

//         // Register the object! (Similar to how you do it in C++)
//         entity1.registerObject();

//         // Add it to the scene!
//         Game.Scene.addEntity(entity1, "Dwarf Meshes");

//         // Let there be lights!
//         SceneEntity light1 = new SceneEntity
//         {
//            Template = "^AnimatedMeshExample/entities/lightTest2.taml",
//            Position = Point3F.Zero()
//         };
//         light1.registerObject();
//         Game.Scene.addEntity(light1, "Lights");

//         // More lights I guess
//         Game.Scene.setDirectionalLight(new Point3F(1, 1, -1), "0.8 0.8 0.8", "0.1 0.1 0.1");
//      }

//      public static void destroy()
//      {
//         Engine.Con.print("DESTROYED AnimatedMeshExample MODULE");
//      }
//   }
//}