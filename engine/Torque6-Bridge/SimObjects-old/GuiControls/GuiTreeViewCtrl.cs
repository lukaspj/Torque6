using System;
using System.Linq;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects.GuiControls
{
   public unsafe class GuiTreeViewCtrl : GuiArrayCtrl
   {
      
      public GuiTreeViewCtrl()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GuiTreeViewCtrlCreateInstance());
      }

      public GuiTreeViewCtrl(uint pId) : base(pId)
      {
      }

      public GuiTreeViewCtrl(string pName) : base(pName)
      {
      }

      public GuiTreeViewCtrl(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTreeViewCtrl(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }

      public GuiTreeViewCtrl(SimObject pObj) : base(pObj)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiTreeViewCtrlGetTabSize(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetTabSize(IntPtr ctrl, int size);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiTreeViewCtrlGetTextOffset(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetTextOffset(IntPtr ctrl, int offset);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiTreeViewCtrlGetFullRowSelect(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetFullRowSelect(IntPtr ctrl, bool fullRowSelect);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int GuiTreeViewCtrlGetItemHeight(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetItemHeight(IntPtr ctrl, int height);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiTreeViewCtrlGetDestroyTreeOnSleep(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetDestroyTreeOnSleep(IntPtr ctrl, bool destroyOnSleep);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiTreeViewCtrlGetMouseDragging(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetMouseDragging(IntPtr ctrl, bool allowDragging);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiTreeViewCtrlGetMultipleSelections(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetMultipleSelections(IntPtr ctrl, bool multipleSelections);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiTreeViewCtrlGetDeleteObjectAllowed(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetDeleteObjectAllowed(IntPtr ctrl, bool allowDelete);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool GuiTreeViewCtrlGetDragToItemAllowed(IntPtr ctrl);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GuiTreeViewCtrlSetDragToItemAllowed(IntPtr ctrl, bool allowDrag);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GuiTreeViewCtrlCreateInstance();
      }
      
      #endregion

      #region Properties

      public int TabSize
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetTabSize(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetTabSize(ObjectPtr->ObjPtr, value);
         }
      }
      public int TextOffset
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetTextOffset(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetTextOffset(ObjectPtr->ObjPtr, value);
         }
      }
      public bool FullRowSelect
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetFullRowSelect(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetFullRowSelect(ObjectPtr->ObjPtr, value);
         }
      }
      public int ItemHeight
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetItemHeight(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetItemHeight(ObjectPtr->ObjPtr, value);
         }
      }
      public bool DestroyTreeOnSleep
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetDestroyTreeOnSleep(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetDestroyTreeOnSleep(ObjectPtr->ObjPtr, value);
         }
      }
      public bool MouseDragging
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetMouseDragging(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetMouseDragging(ObjectPtr->ObjPtr, value);
         }
      }
      public bool MultipleSelections
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetMultipleSelections(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetMultipleSelections(ObjectPtr->ObjPtr, value);
         }
      }
      public bool DeleteObjectAllowed
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetDeleteObjectAllowed(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetDeleteObjectAllowed(ObjectPtr->ObjPtr, value);
         }
      }
      public bool DragToItemAllowed
      {
         get
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            return InternalUnsafeMethods.GuiTreeViewCtrlGetDragToItemAllowed(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new Exceptions.SimObjectPointerInvalidException();
            InternalUnsafeMethods.GuiTreeViewCtrlSetDragToItemAllowed(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      
      
      #endregion

      
   }
}