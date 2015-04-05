using HorribleHackz.CustomAttributes;
using IJWLayer;
using Scene;

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
            Position = new Point3F {x = 0, y = -100, z = 0}
         };
         Game.Scene.addEntity(example_room, "Floor");
      }

      public static void destroy()
      {
         Engine.Con.print("DESTROYED ExampleRoom MODULE");
      }
   }
}