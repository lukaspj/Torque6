using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.SimObjects.SimSets;

namespace Torque6_Bridge.SimObjects
{
   public class SimObjectPointerInvalidException : Exception
   {
      public SimObjectPointerInvalidException()
      :base("The SimObject was invalid, this usually happens if you try to use an object after it has been deleted.")
      {
      }

      public SimObjectPointerInvalidException(string message)
         : base(message)
      {
      }

      public SimObjectPointerInvalidException(string message, Exception inner)
         : base(message, inner)
      {
      }
   }

   public unsafe class SimObject : IDisposable
   {
      public SimObject()
      {
         ObjectPtr = Sim.WrapObject(Internal.SimObjectCreateInstance());
      }

      public SimObject(uint pId)
      {
         ObjectPtr = Sim.FindObjectWrapper(pId);
      }

      public SimObject(string pName)
      {
         ObjectPtr = Sim.FindObjectWrapper(pName);
      }

      public SimObject(IntPtr pObjPtr)
      {
         ObjectPtr = Sim.WrapObject(pObjPtr);
      }

      public SimObject(Sim.SimObjectPtr* pObjPtr)
      {
         ObjectPtr = pObjPtr;
      }

      public Sim.SimObjectPtr* ObjectPtr { get; protected set; }

      #region UnsafeNativeMethods

      internal struct Internal
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimObjectCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimObjectRegisterObject(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimObjectGetCanSaveDynamicFields(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectSetCanSaveDynamicFields(IntPtr pObjectPtr, bool pVal);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetInternalName(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectSetInternalName(IntPtr pObjectPtr, string pVal);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectSetParentGroup(IntPtr pObjectPtr, IntPtr pParentGroup);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetSuperClass(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectSetSuperClass(IntPtr pObjectPtr, string pVal);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetClass(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectSetClass(IntPtr pObjectPtr, string pVal);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetName(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectSetName(IntPtr pObjectPtr, string pVal);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern uint SimObjectGetID(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimObjectIsMethod(IntPtr pObjectPtr, string pMethodName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectCall(IntPtr pObjectPtr, int pArgc, string[] pArgv);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectDumpClassHierarchy(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectDump(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimObjectIsMemberOfClass(IntPtr pObjectPtr, string pClassName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetFieldValue(IntPtr pObjectPtr, string pFieldName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectSetFieldValue(IntPtr pObjectPtr, string pFieldName, string pValue);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int SimObjectGetDynamicFieldCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetDynamicField(IntPtr pObjectPtr, int pIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int SimObjectGetFieldCount(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetField(IntPtr pObjectPtr, int pIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetProgenitorFile(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectSetProgenitorFile(IntPtr pObjectPtr, string pFile);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int SimObjectGetType(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string SimObjectGetFieldType(IntPtr pObjectPtr, string pFileName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimObjectIsChildOfGroup(IntPtr pObjectPtr, IntPtr pGroup);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimObjectGetGroup(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectDeleteObject(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr SimObjectClone(IntPtr pObjectPtr, bool pCopyDynamicFields);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimObjectStartTimer(IntPtr pObjectPtr, string pCallbackFunction, float pTimePeriod,
            int pRepeat);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectStopTimer(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimObjectIsTimerActive(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int SimObjectSchedule(IntPtr pObjectPtr, int pTime, int pArgc, string[] pArgv);
      }

      #endregion

      #region Properties

      public bool CanSaveDynamicFields
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return Internal.SimObjectGetCanSaveDynamicFields(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            Internal.SimObjectSetCanSaveDynamicFields(ObjectPtr->ObjPtr, value);
         }
      }

      public string InternalName
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return Internal.SimObjectGetInternalName(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            Internal.SimObjectSetInternalName(ObjectPtr->ObjPtr, value);
         }
      }

      public SimObject ParentGroup
      {
         get { throw new Exception("Eh?"); }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            Internal.SimObjectSetParentGroup(ObjectPtr->ObjPtr, value.ObjectPtr->ObjPtr);
         }
      }

      public string SuperClass
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return Internal.SimObjectGetSuperClass(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            Internal.SimObjectSetSuperClass(ObjectPtr->ObjPtr, value);
         }
      }

      public string Class
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return Internal.SimObjectGetClass(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            Internal.SimObjectSetClass(ObjectPtr->ObjPtr, value);
         }
      }

      public string Name
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return Internal.SimObjectGetName(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            Internal.SimObjectSetName(ObjectPtr->ObjPtr, value);
         }
      }

      public uint Id
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return Internal.SimObjectGetID(ObjectPtr->ObjPtr);
         }
      }

      #endregion

      #region Methods

      public bool IsDead()
      {
         return ObjectPtr->ObjPtr == IntPtr.Zero;
      }

      public bool RegisterObject()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectRegisterObject(ObjectPtr->ObjPtr);
      }

      public bool IsMethod(string pMethodName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectIsMethod(ObjectPtr->ObjPtr, pMethodName);
      }

      public string Call(string pMethodName, params string[] pArgs)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         string[] newParams = new string[pArgs.Length + 2];
         for (int i = 0; i < pArgs.Length; i++)
            newParams[i + 2] = pArgs[i];
         newParams[0] = pMethodName;
         newParams[1] = pMethodName;
         return Internal.SimObjectCall(ObjectPtr->ObjPtr, newParams.Length, newParams);
      }

      public void DumpClassHierarchy()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimObjectDumpClassHierarchy(ObjectPtr->ObjPtr);
      }

      public void Dump()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimObjectDump(ObjectPtr->ObjPtr);
      }

      public bool IsMemberOfClass(string pClassName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectIsMemberOfClass(ObjectPtr->ObjPtr, pClassName);
      }

      public string GetFieldValue(string pFieldName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectGetFieldValue(ObjectPtr->ObjPtr, pFieldName);
      }

      public void SetFieldValue(string pFieldName, string pValue)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimObjectSetFieldValue(ObjectPtr->ObjPtr, pFieldName, pValue);
      }

      public int GetDynamicFieldCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectGetDynamicFieldCount(ObjectPtr->ObjPtr);
      }

      public string GetDynamicField(int pIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectGetDynamicField(ObjectPtr->ObjPtr, pIndex);
      }

      public int GetFieldCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectGetFieldCount(ObjectPtr->ObjPtr);
      }

      public string GetField(int pIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectGetField(ObjectPtr->ObjPtr, pIndex);
      }

      public string GetProgenitorFile()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectGetProgenitorFile(ObjectPtr->ObjPtr);
      }

      public void SetProgenitorFile(string pFile)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimObjectSetProgenitorFile(ObjectPtr->ObjPtr, pFile);
      }

      public int GetTypeMask()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectGetType(ObjectPtr->ObjPtr);
      }

      public string GetFieldType(string pFieldName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectGetFieldType(ObjectPtr->ObjPtr, pFieldName);
      }

      public bool IsChildOfGroup(SimGroup pGroup)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectIsChildOfGroup(ObjectPtr->ObjPtr, pGroup.ObjectPtr->ObjPtr);
      }

      public SimGroup GetGroup()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return new SimGroup(Internal.SimObjectGetGroup(ObjectPtr->ObjPtr));
      }

      public void DeleteObject()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimObjectDeleteObject(ObjectPtr->ObjPtr);
      }

      public SimObject Clone(bool pCopyDynamicFields)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return new SimObject(Internal.SimObjectClone(ObjectPtr->ObjPtr, pCopyDynamicFields));
      }

      public bool StartTimer(string pCallbackFunction, float pTimePeriod, int pRepeat)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectStartTimer(ObjectPtr->ObjPtr, pCallbackFunction, pTimePeriod, pRepeat);
      }

      public void StopTimer()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         Internal.SimObjectStopTimer(ObjectPtr->ObjPtr);
      }

      public bool IsTimerActive()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         return Internal.SimObjectIsTimerActive(ObjectPtr->ObjPtr);
      }

      public string Schedule(int pTime, string pCommand, params string[] pArgs)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         string[] newParams = new string[pArgs.Length + 2];
         for (int i = 0; i < pArgs.Length; i++)
            newParams[i + 2] = pArgs[i];
         newParams[0] = pCommand;
         newParams[1] = Id.ToString();
         return Internal.SimObjectCall(ObjectPtr->ObjPtr, newParams.Length, newParams);
      }

      #endregion

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
            Marshal.FreeHGlobal((IntPtr) ObjectPtr);
         }
      }

      ~SimObject()
      {
         Dispose(false);
      }

      #endregion
   }
}