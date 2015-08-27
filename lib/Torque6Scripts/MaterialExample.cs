using Torque6Scripts.Framework;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.SimObjects.Scene;
using Torque6_Bridge.Types;

namespace Torque6Scripts
{
   [ConsoleClass]
   internal class MaterialExample
   {
      public static void create()
      {
         // Create some dwarfs!
         SceneEntity spheres = new SceneEntity
         {
            Template = "MaterialExample:TestSpheres",
            Position = Point3F.Zero(),
            Rotation = Point3F.Zero()
         };

         // Register the object! (Similar to how you do it in C++)
         spheres.RegisterObject();

         // Add it to the scene!
         Scene.AddEntity(spheres, "Spheres");

         float metal = 0.0f;
         float rough = 0.0f;

         for (int i = 0; i < 25; i++)
         {
            MeshComponent mesh = spheres.FindComponent("TestSphere" + i).As<MeshComponent>();
            mesh.SetUniformVec4("sphereMetalVal", new Point4F(metal, 0, 0, 0));
            mesh.SetUniformVec4("sphereRoughVal", new Point4F(rough, 0, 0, 0));

            metal += 0.25f;
            if (metal > 1.0f)
            {
               metal = 0.0f;
               rough += 0.25f;
            }
         }

         // More lights I guess
         Scene.SetDirectionalLight(new Point3F(1, 1, -1), new Color(1.0f, 1.0f, 1.0f), new Color(0.2f, 0.2f, 0.2f));

         Script.Eval("Skybox::load(expandPath(\"^Skybox/textures/pisa_lod.dds\"));");
         Script.Eval("Skybox::enable();");
      }

      public static void destroy()
      {
         Console.Print("DESTROYED MaterialExample MODULE");
      }
   }
}