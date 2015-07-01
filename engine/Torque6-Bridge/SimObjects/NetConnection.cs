using System;
using System.Runtime.InteropServices;
using Torque6_Bridge.Namespaces;

namespace Torque6_Bridge.SimObjects.Assets
{
   public unsafe class NetConnection : SimGroup
   {
      public NetConnection()
      {
         ObjectPtr = Sim.WrapObject(InternalUnsafeMethods.NetConnectionCreateInstance());
      }

      public NetConnection(uint pId) : base(pId)
      {
      }

      public NetConnection(IntPtr pObjPtr) : base(pObjPtr)
      {
      }

      public NetConnection(string pName) : base(pName)
      {
      }

      public NetConnection(Sim.SimObjectPtr* pObjPtr) : base(pObjPtr)
      {
      }
      
      #region UnsafeNativeMethods

      new internal struct InternalUnsafeMethods
      {
         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr NetConnectionCreateInstance();

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string NetConnectionGetAddress(IntPtr connection);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void NetConnectionSetSimulatedNetParams(IntPtr connection, float packetLoss, int delay);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern float NetConnectionGetPing(IntPtr connection);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern float NetConnectionGetPacketLoss(IntPtr connection);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void NetConnectionCheckMaxRate(IntPtr connection);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void NetConnectionSetLogging(IntPtr connection, bool value);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr NetConnectionResolveGhostID(IntPtr connection, int ghostId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern IntPtr NetConnectionResolveObjectFromGhostIndex(IntPtr connection, int ghostId);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int NetConnectionGetGhostID(IntPtr connection, IntPtr netObj);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern void NetConnectionConnect(IntPtr connection, string remoteAddress);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern string NetConnectionConnectLocal(IntPtr connection);

         [DllImport("Torque6_DEBUG", CallingConvention = CallingConvention.Cdecl)]
         internal static extern int NetConnectionGetGhostsActive(IntPtr connection);


      }
      #endregion

      #region Properties


      #endregion
      
      #region Methods

      public void GetAddress()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionGetAddress(ObjectPtr->ObjPtr);
      }

      public void SetSimulatedNetParams(float packetLoss, int delay)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionSetSimulatedNetParams(ObjectPtr->ObjPtr, packetLoss, delay);
      }

      public void GetPing()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionGetPing(ObjectPtr->ObjPtr);
      }

      public void GetPacketLoss()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionGetPacketLoss(ObjectPtr->ObjPtr);
      }

      public void CheckMaxRate()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionCheckMaxRate(ObjectPtr->ObjPtr);
      }

      public void SetLogging(bool value)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionSetLogging(ObjectPtr->ObjPtr, value);
      }

      public void ResolveGhostID(int ghostId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionResolveGhostID(ObjectPtr->ObjPtr, ghostId);
      }

      public void ResolveObjectFromGhostIndex(int ghostId)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionResolveObjectFromGhostIndex(ObjectPtr->ObjPtr, ghostId);
      }

      public void GetGhostID(NetObject netObj)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionGetGhostID(ObjectPtr->ObjPtr, netObj.ObjectPtr->ObjPtr);
      }

      public void Connect(string remoteAddress)
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionConnect(ObjectPtr->ObjPtr, remoteAddress);
      }

      public void ConnectLocal()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionConnectLocal(ObjectPtr->ObjPtr);
      }

      public void GetGhostsActive()
      {
         if (IsDead()) throw new SimObjectPointerInvalidException();
         InternalUnsafeMethods.NetConnectionGetGhostsActive(ObjectPtr->ObjPtr);
      }

      #endregion
   }
}