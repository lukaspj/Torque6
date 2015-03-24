using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using HorribleHackz.CustomAttributes;

namespace HorribleHackz
{
   class Initializer
   {
      public static void InitializeTypeDictionaries()
      {
         var types = AppDomain.CurrentDomain.GetAssemblies()
            .SelectMany(a => a.GetTypes());
         foreach (Type type in types)
         {
            IEnumerable<ConsoleClassAttribute> attributes =
                  type.GetCustomAttributes<ConsoleClassAttribute>(false);
            if (attributes.Any())
            {
               EngineCallbacks.RegisterType(attributes.First().ConsoleName ?? type.Name, type);
            }
            foreach (MethodInfo methodInfo in type.GetMethods())
            {
               IEnumerable<ConsoleFunctionAttribute> functionAttributes =
                     methodInfo.GetCustomAttributes<ConsoleFunctionAttribute>(false);
               if (functionAttributes.Any())
                  EngineCallbacks.RegisterFunction(functionAttributes.First().FunctionName ?? methodInfo.Name, methodInfo);
            }
         }
      }
   }
}
