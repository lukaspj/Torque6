using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class BehaviorTemplate : SimObject
   {
      public BehaviorTemplate()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.BehaviorTemplateCreateInstance());
      }

      public BehaviorTemplate(uint pId) : base(pId)
      {
      }

      public BehaviorTemplate(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public BehaviorTemplate(string pName) : base(pName)
      {
      }

      public BehaviorTemplate(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorTemplateGetFriendlyName(IntPtr instance);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void BehaviorTemplateSetFriendlyName(IntPtr instance, string name);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorTemplateGetDescription(IntPtr instance);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void BehaviorTemplateSetDescription(IntPtr instance, string description);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorTemplateGetBehaviorType(IntPtr instance);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void BehaviorTemplateSetBehaviorType(IntPtr instance, string type);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr BehaviorTemplateCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr BehaviorTemplateCreateBehaviorInstance(IntPtr instance);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorTemplateAddBehaviorField(IntPtr instance, string fieldName, string desc, string type, string defaultValue, string userData);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int BehaviorTemplateGetBehaviorFieldCount(IntPtr instance);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorTemplateGetBehaviorField(IntPtr instance, int fieldIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorTemplateGetBehaviorFieldUserData(IntPtr instance, int fieldIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorTemplateGetBehaviorFieldDescription(IntPtr instance, int fieldIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorTemplateAddBehaviorOutput(IntPtr instance, string outputName, string label, string description);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int BehaviorTemplateGetBehaviorOutputCount(IntPtr instance);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorTemplateGetBehaviorOutput(IntPtr instance, int fieldIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorTemplateHasBehaviorOutput(IntPtr instance, string outputName);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorTemplateAddBehaviorInput(IntPtr instance, string inputName, string label, string description);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int BehaviorTemplateGetBehaviorInputCount(IntPtr instance);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string BehaviorTemplateGetBehaviorInput(IntPtr instance, int fieldIndex);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern bool BehaviorTemplateHasBehaviorInput(IntPtr instance, string inputName);
      }
      
      #endregion

      #region Properties

      public string FriendlyName
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.BehaviorTemplateGetFriendlyName(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.BehaviorTemplateSetFriendlyName(ObjectPtr->ObjPtr, value);
         }
      }
      public string Description
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.BehaviorTemplateGetDescription(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.BehaviorTemplateSetDescription(ObjectPtr->ObjPtr, value);
         }
      }
      public string BehaviorType
      {
         get
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            return InternalUnsafeMethods.BehaviorTemplateGetBehaviorType(ObjectPtr->ObjPtr);
         }
         set
         {
            if (IsDead()) throw new SimObjectPointerInvalidException();
            InternalUnsafeMethods.BehaviorTemplateSetBehaviorType(ObjectPtr->ObjPtr, value);
         }
      }
      
      #endregion
      
      #region Methods

      public void CreateBehaviorInstance()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateCreateBehaviorInstance(ObjectPtr->ObjPtr);
      }

      public void AddBehaviorField(string fieldName, string desc, string type, string defaultValue, string userData)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateAddBehaviorField(ObjectPtr->ObjPtr, fieldName, desc, type, defaultValue, userData);
      }

      public void GetBehaviorFieldCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateGetBehaviorFieldCount(ObjectPtr->ObjPtr);
      }

      public void GetBehaviorField(int fieldIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateGetBehaviorField(ObjectPtr->ObjPtr, fieldIndex);
      }

      public void GetBehaviorFieldUserData(int fieldIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateGetBehaviorFieldUserData(ObjectPtr->ObjPtr, fieldIndex);
      }

      public void GetBehaviorFieldDescription(int fieldIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateGetBehaviorFieldDescription(ObjectPtr->ObjPtr, fieldIndex);
      }

      public void AddBehaviorOutput(string outputName, string label, string description)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateAddBehaviorOutput(ObjectPtr->ObjPtr, outputName, label, description);
      }

      public void GetBehaviorOutputCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateGetBehaviorOutputCount(ObjectPtr->ObjPtr);
      }

      public void GetBehaviorOutput(int fieldIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateGetBehaviorOutput(ObjectPtr->ObjPtr, fieldIndex);
      }

      public void HasBehaviorOutput(string outputName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateHasBehaviorOutput(ObjectPtr->ObjPtr, outputName);
      }

      public void AddBehaviorInput(string inputName, string label, string description)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateAddBehaviorInput(ObjectPtr->ObjPtr, inputName, label, description);
      }

      public void GetBehaviorInputCount()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateGetBehaviorInputCount(ObjectPtr->ObjPtr);
      }

      public void GetBehaviorInput(int fieldIndex)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateGetBehaviorInput(ObjectPtr->ObjPtr, fieldIndex);
      }

      public void HasBehaviorInput(string inputName)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.BehaviorTemplateHasBehaviorInput(ObjectPtr->ObjPtr, inputName);
      }
      
      #endregion
   }
}