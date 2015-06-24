using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.SimSets
{
   public unsafe class ActionMap : SimSet
   {
      public ActionMap()
      {
         ObjectPtr = Sim.WrapObject(Internal.ActionMapCreateInstance());
      }

      public ActionMap(uint pId) : base(pId)
      {
      }

      public ActionMap(string pName) : base(pName)
      {
      }

      public ActionMap(IntPtr pPtr) : base(pPtr)
      {
      }

      #region UnsafeNativeMethods

      internal struct Internal
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr ActionMapCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapBind(IntPtr pObjectPtr, int pArgc, string[] pArgv);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapBindObj(IntPtr pObjectPtr, int pArgc, string[] pArgv, IntPtr pBindObjPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapBindCmd(IntPtr pObjectPtr, string pDevice, string pAction, string pMakeCmd,
            string pBreakCmd);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapUnbind(IntPtr pObjectPtr, string pDevice, string pAction);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapUnbindObj(IntPtr pObjectPtr, string pDevice, string pAction,
            IntPtr pBindObjPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapSave(IntPtr pObjectPtr, string pFileName, bool pAppend);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapPush(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void ActionMapPop(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ActionMapGetBinding(IntPtr pObjectPtr, string pCommand);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ActionMapGetCommand(IntPtr pObjectPtr, string pDevice, string pAction);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool ActionMapIsInverted(IntPtr pObjectPtr, string pDevice, string pAction);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern float ActionMapGetScale(IntPtr pObjectPtr, string pDevice, string pAction);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string ActionMapGetDeadZone(IntPtr pObjectPtr, string pDevice, string pAction);
      }

      #endregion

      #region Methods

      public void Bind(string pDevice, string pAction, string pCommand, params string[] pModifiers)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         string[] args = new string[pModifiers.Length + 3];
         args[0] = pDevice;
         args[1] = pAction;
         args[2] = pCommand;
         Internal.ActionMapBind(ObjectPtr->ObjPtr, args.Length, args);
      }

      public void BindObj(SimObject pObject, string pDevice, string pAction, string pCommand, params string[] pModifiers)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         string[] args = new string[pModifiers.Length + 3];
         args[0] = pDevice;
         args[1] = pAction;
         args[2] = pCommand;
         Internal.ActionMapBindObj(ObjectPtr->ObjPtr, args.Length, args, pObject.ObjectPtr->ObjPtr);
      }

      public void BindCmd(string pDevice, string pAction, string pMakeCmd, string pBreakCmd)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.ActionMapBindCmd(ObjectPtr->ObjPtr, pDevice, pAction, pMakeCmd, pBreakCmd);
      }

      public void Unbind(string pDevice, string pAction)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.ActionMapUnbind(ObjectPtr->ObjPtr, pDevice, pAction);
      }

      public void UnbindObj(SimObject pObject, string pDevice, string pAction)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.ActionMapUnbindObj(ObjectPtr->ObjPtr, pDevice, pAction, pObject.ObjectPtr->ObjPtr);
      }

      public void Save(string pFileName = null, bool pAppend = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.ActionMapSave(ObjectPtr->ObjPtr, pFileName, pAppend);
      }

      public void Push()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.ActionMapPush(ObjectPtr->ObjPtr);
      }

      public void Pop()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.ActionMapPop(ObjectPtr->ObjPtr);
      }

      public string GetBinding(string pCommand)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.ActionMapGetBinding(ObjectPtr->ObjPtr, pCommand);
      }

      public string GetCommand(string pDevice, string pAction)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.ActionMapGetCommand(ObjectPtr->ObjPtr, pDevice, pAction);
      }

      public bool IsInverted(string pDevice, string pAction)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.ActionMapIsInverted(ObjectPtr->ObjPtr, pDevice, pAction);
      }

      public float GetScale(string pDevice, string pAction)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.ActionMapGetScale(ObjectPtr->ObjPtr, pDevice, pAction);
      }

      public Point2F GetDeadZone(string pDevice, string pAction)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return new Point2F(Internal.ActionMapGetDeadZone(ObjectPtr->ObjPtr, pDevice, pAction));
      }

      #endregion
   }

   public class Point2F
   {
      public Point2F(string pActionMapGetDeadZone)
      {
         throw new NotImplementedException();
      }
   }
}