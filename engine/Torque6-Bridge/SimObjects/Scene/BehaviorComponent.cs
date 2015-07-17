using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.Scene
{
   public unsafe class BehaviorComponent : DynamicConsoleMethodComponent
   {
      public BehaviorComponent()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.BehaviorComponentCreateInstance());
      }

      public BehaviorComponent(uint pId) : base(pId)
      {
      }

      public BehaviorComponent(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public BehaviorComponent(string pName) : base(pName)
      {
      }

      public BehaviorComponent(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr BehaviorComponentCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorComponentAddBehavior(IntPtr component, IntPtr inst);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorComponentRemoveBehavior(IntPtr component, IntPtr inst, bool deleteBehavior);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void BehaviorComponentClearBehaviors(IntPtr component);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int BehaviorComponentGetBehaviorCount(IntPtr component);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr BehaviorComponentGetBehavior(IntPtr component, string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr BehaviorComponentGetBehaviorByIndex(IntPtr component, uint index);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorComponentReOrder(IntPtr component, IntPtr inst, uint index);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorComponentConnect(IntPtr component, IntPtr outputBehavior, string outputName, IntPtr inputBehavior, string inputName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorComponentDisconnect(IntPtr component, IntPtr outputBehavior, string outputName, IntPtr inputBehavior, string inputName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorComponentRaise(IntPtr component, IntPtr outputBehavior, string outputName, uint timeDelta);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern uint BehaviorComponentGetBehaviorConnectionCount(IntPtr component, IntPtr outputBehavior, string outputName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorComponentGetBehaviorConnection(IntPtr component, IntPtr outputBehavior, string outputName, uint connectionIndex);
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      public void AddBehavior(BehaviorInstance inst)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentAddBehavior(ObjectPtr->ObjPtr, inst.ObjectPtr->ObjPtr);
      }

      public void RemoveBehavior(BehaviorInstance inst, bool deleteBehavior = true)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentRemoveBehavior(ObjectPtr->ObjPtr, inst.ObjectPtr->ObjPtr, deleteBehavior);
      }

      public void ClearBehaviors()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentClearBehaviors(ObjectPtr->ObjPtr);
      }

      public void GetBehaviorCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentGetBehaviorCount(ObjectPtr->ObjPtr);
      }

      public void GetBehavior(string name)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentGetBehavior(ObjectPtr->ObjPtr, name);
      }

      public void GetBehaviorByIndex(uint index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentGetBehaviorByIndex(ObjectPtr->ObjPtr, index);
      }

      public void ReOrder(BehaviorInstance inst, uint index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentReOrder(ObjectPtr->ObjPtr, inst.ObjectPtr->ObjPtr, index);
      }

      public void Connect(BehaviorInstance outputBehavior, string outputName, BehaviorInstance inputBehavior, string inputName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentConnect(ObjectPtr->ObjPtr, outputBehavior.ObjectPtr->ObjPtr, outputName, inputBehavior.ObjectPtr->ObjPtr, inputName);
      }

      public void Disconnect(BehaviorInstance outputBehavior, string outputName, BehaviorInstance inputBehavior, string inputName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentDisconnect(ObjectPtr->ObjPtr, outputBehavior.ObjectPtr->ObjPtr, outputName, inputBehavior.ObjectPtr->ObjPtr, inputName);
      }

      public void Raise(BehaviorInstance outputBehavior, string outputName, uint timeDelta = 0)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentRaise(ObjectPtr->ObjPtr, outputBehavior.ObjectPtr->ObjPtr, outputName, timeDelta);
      }

      public void GetBehaviorConnectionCount(BehaviorInstance outputBehavior, string outputName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentGetBehaviorConnectionCount(ObjectPtr->ObjPtr, outputBehavior.ObjectPtr->ObjPtr, outputName);
      }

      public void GetBehaviorConnection(BehaviorInstance outputBehavior, string outputName, uint connectionIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorComponentGetBehaviorConnection(ObjectPtr->ObjPtr, outputBehavior.ObjectPtr->ObjPtr, outputName, connectionIndex);
      }
      
      #endregion
   }
}