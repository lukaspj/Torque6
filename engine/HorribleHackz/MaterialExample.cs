using HorribleHackz.CustomAttributes;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.SimObjects;
using Torque6_Bridge.Types;

namespace HorribleHackz
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
            ((MeshComponent) spheres.FindComponent("TestSphere" + i)).SetUniformVec4("sphereMetalVal",
               new Point4F(metal, 0, 0, 0));
            ((MeshComponent) spheres.FindComponent("TestSphere" + i)).SetUniformVec4("sphereRoughVal",
               new Point4F(rough, 0, 0, 0));

            metal += 0.25f;
            if (metal > 1.0)
            {
               metal = 0.0f;
               rough += 0.25f;
            }
         }

         // Let there be lights!
         SceneEntity light1 = new SceneEntity
         {
            Template = "^AnimatedMeshExample/entities/lightTest2.taml",
            Position = Point3F.Zero()
         };
         light1.RegisterObject();
         Scene.AddEntity(light1, "Lights");

         // More lights I guess
         Scene.SetDirectionalLight(new Point3F(1, 1, -1), new Color(1.0f, 1.0f, 1.0f), new Color(0.2f, 0.2f, 0.2f));

    //Skybox::load(expandPath("^Skybox/textures/pisa_lod.dds"));
    //Skybox::enable();
      }

      /*%spheres = new SceneEntity();
    %spheres.template = "MaterialExample:TestSpheres";
    %spheres.position = "0 0 0";
    %spheres.rotation = "0 0 0";
    Scene::addEntity(%spheres, "Spheres");

    %metal = 0.0;
    %rough = 0.0;
    for(%n = 0; %n < 25; %n++)
    {
        %spheres.findComponent("TestSphere" @ %n).setUniformFloat("sphereMetalVal", %metal);
        %spheres.findComponent("TestSphere" @ %n).setUniformFloat("sphereRoughVal", %rough);
  
        %metal += 0.25;
        if ( %metal > 1.0 )
        {
            %metal = 0.0;
            %rough += 0.25;
        }
    }

    Scene::setDirectionalLight("1 1 -1", "1.0 1.0 1.0", "0.2 0.2 0.2");

    Skybox::load(expandPath("^Skybox/textures/pisa_lod.dds"));
    Skybox::enable();*/

      public static void destroy()
      {
         Console.Print("DESTROYED MaterialExample MODULE");
      }
   }
}