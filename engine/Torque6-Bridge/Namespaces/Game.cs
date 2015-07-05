using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.SimObjects;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.Namespaces
{
   public static unsafe class Game
   {
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void Game_SaveJournal(string filePath);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void Game_SaveJournal(string filePath, bool doBreak);
      }

      #endregion
      
      #region Functions

      public static void SaveJournal(string filePath)
      {
         InternalUnsafeMethods.Game_SaveJournal(filePath);
      }

      public static void SaveJournal(string filePath, bool doBreak)
      {
         InternalUnsafeMethods.Game_SaveJournal(filePath, doBreak);
      }      

      #endregion
   }
}