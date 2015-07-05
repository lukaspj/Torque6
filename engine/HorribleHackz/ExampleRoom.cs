using HorribleHackz.CustomAttributes;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.SimObjects;
using Torque6_Bridge.Types;

namespace HorribleHackz
{
   [ConsoleClass]
   internal class ExampleRoom
   {
      public static void create()
      {
         // Dwarfs like something to stand on. Free fall is bad for the health!
         SceneEntity example_room = new SceneEntity
         {
            Template = "^ExampleRoom/entities/ExampleRoom.taml",
            Position = new Point3F { x = 0, y = -100, z = 0 }
         };
         Scene.AddEntity(example_room, "Floor");
      }

      public static void destroy()
      {
         Console.Print("DESTROYED ExampleRoom MODULE");
      }
   }
}