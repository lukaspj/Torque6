using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class EventManager : SimObject
   {
      public EventManager()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.EventManagerCreateInstance());
      }

      public EventManager(uint pId) : base(pId)
      {
      }

      public EventManager(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public EventManager(string pName) : base(pName)
      {
      }

      public EventManager(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string EventManagerGetQueue(IntPtr eventManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void EventManagerSetQueue(IntPtr eventManager, string value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr EventManagerCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool EventManagerRegisterEvent(IntPtr eventManager, string eventName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void EventManagerUnregisterEvent(IntPtr eventManager, string eventName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool EventManagerIsRegisteredEvent(IntPtr eventManager, string eventName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool EventManagerPostEvent(IntPtr eventManager, string eventName, string data);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool EventManagerSubscribe(IntPtr eventManager, IntPtr listener, string eventName, string callback);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void EventManagerRemove(IntPtr eventManager, IntPtr listener, string eventName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void EventManagerDumpEvents(IntPtr eventManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void EventManagerDumpSubscribers(IntPtr eventManager, string eventName);
      }
      
      #endregion

      #region Properties

      public string Queue
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.EventManagerGetQueue(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.EventManagerSetQueue(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      public void RegisterEvent(string eventName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.EventManagerRegisterEvent(ObjectPtr->ObjPtr, eventName);
      }

      public void UnregisterEvent(string eventName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.EventManagerUnregisterEvent(ObjectPtr->ObjPtr, eventName);
      }

      public void IsRegisteredEvent(string eventName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.EventManagerIsRegisteredEvent(ObjectPtr->ObjPtr, eventName);
      }

      public void PostEvent(string eventName, string data)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.EventManagerPostEvent(ObjectPtr->ObjPtr, eventName, data);
      }

      public void Subscribe(SimObject listener, string eventName, string callback)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.EventManagerSubscribe(ObjectPtr->ObjPtr, listener.ObjectPtr->ObjPtr, eventName, callback);
      }

      public void Remove(SimObject listener, string eventName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.EventManagerRemove(ObjectPtr->ObjPtr, listener.ObjectPtr->ObjPtr, eventName);
      }

      public void DumpEvents()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.EventManagerDumpEvents(ObjectPtr->ObjPtr);
      }

      public void DumpSubscribers(string eventName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.EventManagerDumpSubscribers(ObjectPtr->ObjPtr, eventName);
      }
      
      #endregion
   }
}