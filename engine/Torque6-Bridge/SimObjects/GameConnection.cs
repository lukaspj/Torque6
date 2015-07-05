using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;
using Torque6_Bridge.Utility;
using Torque6_Bridge.Types;

namespace Torque6_Bridge.SimObjects
{
   public unsafe class GameConnection : NetConnection
   {
      public GameConnection()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.GameConnectionCreateInstance());
      }

      public GameConnection(uint pId) : base(pId)
      {
      }

      public GameConnection(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public GameConnection(string pName) : base(pName)
      {
      }

      public GameConnection(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GameConnectionCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GameConnectionSetJoinPassword(IntPtr connection, string password);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GameConnectionSetConnectArgs(IntPtr connection, string password);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GameConnectionActivateGhosting(IntPtr connection);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GameConnectionResetGhosting(IntPtr connection);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void GameConnectionDelete(IntPtr connection, string reason);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr GameConnectionGetServerConnection(IntPtr connection);
      }
      
      #endregion

      #region Properties

      
      
      #endregion
      
      #region Methods

      public void SetJoinPassword(string password)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.GameConnectionSetJoinPassword(ObjectPtr->ObjPtr, password);
      }

      public void SetConnectArgs(string password)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.GameConnectionSetConnectArgs(ObjectPtr->ObjPtr, password);
      }

      public void ActivateGhosting()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.GameConnectionActivateGhosting(ObjectPtr->ObjPtr);
      }

      public void ResetGhosting()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.GameConnectionResetGhosting(ObjectPtr->ObjPtr);
      }

      public void Delete(string reason)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.GameConnectionDelete(ObjectPtr->ObjPtr, reason);
      }

      public void GetServerConnection()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.GameConnectionGetServerConnection(ObjectPtr->ObjPtr);
      }
      
      #endregion
   }
}