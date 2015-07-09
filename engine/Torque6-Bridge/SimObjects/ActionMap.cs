using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class ActionMap : SimObject
   {
      public ActionMap()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.ActionMapCreateInstance());
      }

      public ActionMap(uint pId) : base(pId)
      {
      }

      public ActionMap(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public ActionMap(string pName) : base(pName)
      {
      }

      public ActionMap(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ActionMapCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapBind(IntPtr map, int argc, string[] argv);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapBindObj(IntPtr map, int argc, string[] argv, IntPtr obj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapBindCmd(IntPtr map, string device, string action, string makeCmd, string breakCmd);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapUnbind(IntPtr map, string device, string action);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapUnbindObj(IntPtr map, string device, string action, IntPtr obj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapSave(IntPtr map, string fileName, bool append);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapPush(IntPtr map);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapPop(IntPtr map);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ActionMapGetBinding(IntPtr map, string command);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ActionMapGetCommand(IntPtr map, string device, string action);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ActionMapIsInverted(IntPtr map, string device, string action);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern float ActionMapGetScale(IntPtr map, string device, string action);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ActionMapGetDeadZone(IntPtr map, string device, string action);
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      public void Bind(int argc, string[] argv)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapBind(ObjectPtr->ObjPtr, argc, argv);
      }

      public void BindObj(int argc, string[] argv, SimObject obj)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapBindObj(ObjectPtr->ObjPtr, argc, argv, obj.ObjectPtr->ObjPtr);
      }

      public void BindCmd(string device, string action, string makeCmd, string breakCmd)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapBindCmd(ObjectPtr->ObjPtr, device, action, makeCmd, breakCmd);
      }

      public void Unbind(string device, string action)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapUnbind(ObjectPtr->ObjPtr, device, action);
      }

      public void UnbindObj(string device, string action, SimObject obj)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapUnbindObj(ObjectPtr->ObjPtr, device, action, obj.ObjectPtr->ObjPtr);
      }

      public void Save(string fileName, bool append)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapSave(ObjectPtr->ObjPtr, fileName, append);
      }

      public void Push()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapPush(ObjectPtr->ObjPtr);
      }

      public void Pop()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapPop(ObjectPtr->ObjPtr);
      }

      public void GetBinding(string command)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapGetBinding(ObjectPtr->ObjPtr, command);
      }

      public void GetCommand(string device, string action)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapGetCommand(ObjectPtr->ObjPtr, device, action);
      }

      public void IsInverted(string device, string action)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapIsInverted(ObjectPtr->ObjPtr, device, action);
      }

      public void GetScale(string device, string action)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapGetScale(ObjectPtr->ObjPtr, device, action);
      }

      public void GetDeadZone(string device, string action)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.ActionMapGetDeadZone(ObjectPtr->ObjPtr, device, action);
      }
      
      #endregion
   }
}