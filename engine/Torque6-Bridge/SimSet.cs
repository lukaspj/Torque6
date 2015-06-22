using System;

namespace Torque6_Bridge
{
   public class SimSet : SimObject
   {
      public SimSet(uint pId) : base(pId)
      {
      }

      public SimSet(string pName) : base(pName)
      {
      }

      public SimSet(IntPtr pPtr)
         : base(pPtr)
      {
      }
   }
}