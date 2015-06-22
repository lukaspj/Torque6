using System;

namespace Torque6_Bridge
{
   public class SimGroup : SimSet
   {
      public SimGroup(uint pId) : base(pId)
      {
      }

      public SimGroup(string pName) : base(pName)
      {
      }

      public SimGroup(IntPtr pPtr)
         : base(pPtr)
      {
      }
   }
}