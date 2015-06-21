using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge
{
   public unsafe class SimObject : IDisposable
   {
      internal struct Internal
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl, EntryPoint = "SimObjectGetName")]
         internal static extern IntPtr GetName(IntPtr pObjectPtr);
      }

      public Sim.SimObjectPtr* ObjectPtr { get; protected set; }

      public SimObject(int pId)
      {
         ObjectPtr = Sim.FindObjectWrapper(pId);
      }

      public SimObject(string pName)
      {
         ObjectPtr = Sim.FindObjectWrapper(pName);
      }

      public string Name
      {
         get
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            var ret = Internal.GetName(ObjectPtr->ObjPtr);
            return Marshal.PtrToStringAnsi(ret);
         }
      }

      #region IDisposable
      public void Dispose()
      {
         Dispose(true);
         GC.SuppressFinalize(this);
      }

      protected virtual void Dispose(bool pDisposing)
      {
         if (ObjectPtr->ObjPtr != IntPtr.Zero)
         {
            Marshal.FreeHGlobal((IntPtr)ObjectPtr);
         }
      }

      ~SimObject()
      {
         Dispose(false);
      }
      #endregion
   }
}