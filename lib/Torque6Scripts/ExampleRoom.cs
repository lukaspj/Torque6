﻿using Torque6Scripts.Framework;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.SimObjects.Scene;
using Torque6_Bridge.Types;

namespace Torque6Scripts
{
   [ConsoleClass]
   internal class ExampleRoom
   {
      public static void create()
      {
         // Dwarfs like something to stand on. Free fall is bad for the health!
         SceneEntity example_room = new SceneEntity
         {
            Template = "ExampleRoom:ExampleRoom",
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