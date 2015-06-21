using CppSharp;
using CppSharp.AST;
using CppSharp.Generators;

namespace CPPSharp
{
   class Torque6Library : ILibrary
   {
      public void Preprocess(Driver driver, ASTContext ctx)
      {
      }

      public void Postprocess(Driver driver, ASTContext ctx)
      {
      }

      public void SetupPasses(Driver driver)
      {
      }

      public void Setup(Driver driver)
      {
         DriverOptions options = driver.Options;
         options.GeneratorKind = GeneratorKind.CSharp;
         options.LibraryName = "Torque6";
         options.Libraries.Add("E:/GitHub/Torque6/build/Torque6_DEBUG.lib");
         options.Headers.Add("simObject.h");
         options.Headers.Add("mPoint.h");
         options.Headers.Add("platform.h");
         options.Headers.Add("torqueConfig.h");
         options.addIncludeDirs("E:/GitHub/Torque6/engine/source");
         options.addIncludeDirs("E:/GitHub/Torque6/engine/source/sim");
         options.addIncludeDirs("E:/GitHub/Torque6/engine/source/math");
         options.addIncludeDirs("E:/GitHub/Torque6/engine/source/platform");
         options.OutputDir = "CSharpStuff";
      }
   }
}
