using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class UndoManager : SimObject
   {
      public UndoManager()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.UndoManagerCreateInstance());
      }

      public UndoManager(uint pId) : base(pId)
      {
      }

      public UndoManager(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public UndoManager(string pName) : base(pName)
      {
      }

      public UndoManager(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int UndoManagerGetNumLevels(IntPtr undoAction);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void UndoManagerSetNumLevels(IntPtr undoAction, int value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr UndoManagerCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int UndoManagerGetRedoCount(IntPtr undoManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void UndoManagerClearAll(IntPtr undoManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int UndoManagerGetUndoCount(IntPtr undoManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string UndoManagerGetUndoName(IntPtr undoManager, int index);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string UndoManagerGetRedoName(IntPtr undoManager, int index);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void UndoManagerUndo(IntPtr undoManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void UndoManagerRedo(IntPtr undoManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string UndoManagerGetNextUndoName(IntPtr undoManager);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string UndoManagerGetNextRedoName(IntPtr undoManager);
      }
      
      #endregion

      #region Properties

      public int NumLevels
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.UndoManagerGetNumLevels(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.UndoManagerSetNumLevels(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      public void GetRedoCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerGetRedoCount(ObjectPtr->ObjPtr);
      }

      public void ClearAll()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerClearAll(ObjectPtr->ObjPtr);
      }

      public void GetUndoCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerGetUndoCount(ObjectPtr->ObjPtr);
      }

      public void GetUndoName(int index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerGetUndoName(ObjectPtr->ObjPtr, index);
      }

      public void GetRedoName(int index)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerGetRedoName(ObjectPtr->ObjPtr, index);
      }

      public void Undo()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerUndo(ObjectPtr->ObjPtr);
      }

      public void Redo()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerRedo(ObjectPtr->ObjPtr);
      }

      public void GetNextUndoName()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerGetNextUndoName(ObjectPtr->ObjPtr);
      }

      public void GetNextRedoName()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.UndoManagerGetNextRedoName(ObjectPtr->ObjPtr);
      }
      
      #endregion
   }
}