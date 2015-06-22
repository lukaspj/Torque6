using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge
{
   public unsafe class SimObject : IDisposable
   {
      internal struct Internal
      {
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
         internal static extern bool SimObjectStartTimer(IntPtr pObjectPtr, string pCallbackFunction, float pTimePeriod, int pRepeat);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void SimObjectStopTimer(IntPtr pObjectPtr);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool SimObjectIsTimerActive(IntPtr pObjectPtr);
         
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int SimObjectSchedule(IntPtr pObjectPtr, int pTime, int pArgc, string[] pArgv);
      }

      public Sim.SimObjectPtr* ObjectPtr { get; protected set; }

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

      #region Properties
      public bool CanSaveDynamicFields
      {
         get
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            return Internal.SimObjectGetCanSaveDynamicFields(ObjectPtr->ObjPtr);
         }
         set
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            Internal.SimObjectSetCanSaveDynamicFields(ObjectPtr->ObjPtr, value);
         }
      }

      public string InternalName
      {
         get
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            return Internal.SimObjectGetInternalName(ObjectPtr->ObjPtr);
         }
         set
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            Internal.SimObjectSetInternalName(ObjectPtr->ObjPtr, value);
         }
      }

      public SimObject ParentGroup
      {
         get
         {
            throw new Exception("Eh?");
         }
         set
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            Internal.SimObjectSetParentGroup(ObjectPtr->ObjPtr, value.ObjectPtr->ObjPtr);
         }
      }

      public string SuperClass
      {
         get
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            return Internal.SimObjectGetSuperClass(ObjectPtr->ObjPtr);
         }
         set
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            Internal.SimObjectSetSuperClass(ObjectPtr->ObjPtr, value);
         }
      }

      public string Class
      {
         get
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            return Internal.SimObjectGetClass(ObjectPtr->ObjPtr);
         }
         set
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            Internal.SimObjectSetClass(ObjectPtr->ObjPtr, value);
         }
      }

      public string Name
      {
         get
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            return Internal.SimObjectGetName(ObjectPtr->ObjPtr);
         }
         set
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            Internal.SimObjectSetName(ObjectPtr->ObjPtr, value);
         }
      }

      public uint Id
      {
         get
         {
            if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
            return Internal.SimObjectGetID(ObjectPtr->ObjPtr);
         }
      }
      #endregion

      #region Methods

      public bool IsMethod(string pMethodName)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectIsMethod(ObjectPtr->ObjPtr, pMethodName);
      }

      public string Call(string pMethodName, params string[] pArgs)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         string[] newParams = new string[pArgs.Length + 2];
         for (int i = 0; i < pArgs.Length; i++)
            newParams[i + 2] = pArgs[i];
         newParams[0] = pMethodName;
         newParams[1] = pMethodName;
         return Internal.SimObjectCall(ObjectPtr->ObjPtr, newParams.Length, newParams);
      }

      public void DumpClassHierarchy()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         Internal.SimObjectDumpClassHierarchy(ObjectPtr->ObjPtr);
      }

      public void Dump()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         Internal.SimObjectDump(ObjectPtr->ObjPtr);
      }

      public bool IsMemberOfClass(string pClassName)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectIsMemberOfClass(ObjectPtr->ObjPtr, pClassName);
      }

      public string GetFieldValue(string pFieldName)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectGetFieldValue(ObjectPtr->ObjPtr, pFieldName);
      }

      public void SetFieldValue(string pFieldName, string pValue)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         Internal.SimObjectSetFieldValue(ObjectPtr->ObjPtr, pFieldName, pValue);
      }

      public int GetDynamicFieldCount()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectGetDynamicFieldCount(ObjectPtr->ObjPtr);
      }

      public string GetDynamicField(int pIndex)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectGetDynamicField(ObjectPtr->ObjPtr, pIndex);
      }

      public int GetFieldCount()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectGetFieldCount(ObjectPtr->ObjPtr);
      }

      public string GetField(int pIndex)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectGetField(ObjectPtr->ObjPtr, pIndex);
      }

      public string GetProgenitorFile()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectGetProgenitorFile(ObjectPtr->ObjPtr);
      }

      public void SetProgenitorFile(string pFile)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         Internal.SimObjectSetProgenitorFile(ObjectPtr->ObjPtr, pFile);
      }

      public int GetTypeMask()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectGetType(ObjectPtr->ObjPtr);
      }

      public string GetFieldType(string pFieldName)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectGetFieldType(ObjectPtr->ObjPtr, pFieldName);
      }

      public bool IsChildOfGroup(SimGroup pGroup)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectIsChildOfGroup(ObjectPtr->ObjPtr, pGroup.ObjectPtr->ObjPtr);
      }

      public SimGroup GetGroup()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return new SimGroup(Internal.SimObjectGetGroup(ObjectPtr->ObjPtr));
      }

      public void DeleteObject()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         Internal.SimObjectDeleteObject(ObjectPtr->ObjPtr);
      }

      public SimObject Clone(bool pCopyDynamicFields)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return new SimObject(Internal.SimObjectClone(ObjectPtr->ObjPtr, pCopyDynamicFields));
      }

      public bool StartTimer(string pCallbackFunction, float pTimePeriod, int pRepeat)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectStartTimer(ObjectPtr->ObjPtr, pCallbackFunction, pTimePeriod, pRepeat);
      }

      public void StopTimer()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         Internal.SimObjectStopTimer(ObjectPtr->ObjPtr);
      }

      public bool IsTimerActive()
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
         return Internal.SimObjectIsTimerActive(ObjectPtr->ObjPtr);
      }

      public string Schedule(int pTime, string pCommand, params string[] pArgs)
      {
         if (ObjectPtr->ObjPtr == IntPtr.Zero) throw new Exception("Object has been deleted.");
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