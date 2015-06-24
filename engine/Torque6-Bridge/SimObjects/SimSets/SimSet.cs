using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.SimSets
{
   public unsafe class SimSet : SimObject
   {
      public SimSet()
      {
         ObjectPtr = Sim.WrapObject(Internal.SimSetCreateInstance());
      }

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

      #region UnsafeNativeMethods

      new internal struct Internal
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimSetCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetListObjects(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetAddObject(IntPtr pObjectPtr, IntPtr pNewObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetRemoveObject(IntPtr pObjectPtr, IntPtr pNewObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetDeleteObjects(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetClear(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetCallOnChildren(IntPtr pObjectPtr, string pMethod, int pArgc, string[] pArgv);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetReorderChild(IntPtr pObjectPtr, IntPtr pObjPtr1, IntPtr pObjPtr2);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int SimSetGetCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimSetGetObject(IntPtr pObjectPtr, int pIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimSetIsMember(IntPtr pObjectPtr, IntPtr pObjPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimSetFindObjectByInternalName(IntPtr pObjectPtr, string pName,
            bool pSearchChildren);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetBringToFront(IntPtr pObjectPtr, IntPtr pChildPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimSetPushToBack(IntPtr pObjectPtr, IntPtr pChildPtr);
      }

      #endregion

      #region Methods

      public void ListObjects()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetListObjects(ObjectPtr->ObjPtr);
      }

      public void AddObject(SimObject pObject)
      {
         if (IsDead()
             || pObject.IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetAddObject(ObjectPtr->ObjPtr, pObject.ObjectPtr->ObjPtr);
      }

      public void RemoveObject(SimObject pObject)
      {
         if (IsDead()
             || pObject.IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetRemoveObject(ObjectPtr->ObjPtr, pObject.ObjectPtr->ObjPtr);
      }

      public void DeleteObjects()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetDeleteObjects(ObjectPtr->ObjPtr);
      }

      public void Clear()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetClear(ObjectPtr->ObjPtr);
      }

      public void CallOnChildren(string pMethod, string[] pArgs)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetCallOnChildren(ObjectPtr->ObjPtr, pMethod, pArgs.Count(), pArgs);
      }

      public void ReorderChild(SimObject pObject1, SimObject pObject2)
      {
         if (IsDead()
             || pObject1.IsDead()
             || pObject2.IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetReorderChild(ObjectPtr->ObjPtr, pObject1.ObjectPtr->ObjPtr, pObject2.ObjectPtr->ObjPtr);
      }

      public int Count()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimSetGetCount(ObjectPtr->ObjPtr);
      }

      public SimObject GetObject(int pIdx)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return new SimObject(Internal.SimSetGetObject(ObjectPtr->ObjPtr, pIdx));
      }

      public bool IsMember(SimObject pObj)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimSetIsMember(ObjectPtr->ObjPtr, pObj.ObjectPtr->ObjPtr);
      }

      public SimObject FindObjectByInternalName(string pName, bool pSearchChildren = false)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return new SimObject(Internal.SimSetFindObjectByInternalName(ObjectPtr->ObjPtr, pName, pSearchChildren));
      }

      public void BringToFront(SimObject pObj)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetBringToFront(ObjectPtr->ObjPtr, pObj.ObjectPtr->ObjPtr);
      }

      public void PushToBack(SimObject pObj)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimSetPushToBack(ObjectPtr->ObjPtr, pObj.ObjectPtr->ObjPtr);
      }

      #endregion
   }
}