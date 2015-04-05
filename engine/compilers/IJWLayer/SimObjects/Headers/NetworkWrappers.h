// IJWLayer.h

#pragma once

#include "CollectionsWrapper.h"

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "network/netObject.h"
#include "network/netConnection.h"
#include "network/tcpObject.h"
#include "network/httpObject.h"

// #pragma unmanaged
#pragma managed(pop)

typedef NetConnection EngineNetConnection;
typedef NetObject EngineNetObject;
typedef TCPObject EngineTCPObject;
typedef HTTPObject EngineHTTPObject;

namespace IJWLayer {

   ref class NetObject;

   public ref class NetConnection : SimGroup
   {
   public:
      static NetConnection^ Wrap(int ID) { return static_cast<NetConnection^>(SimObject::Wrap(ID)); };
      static NetConnection^ Wrap(EngineNetConnection* obj) { return static_cast<NetConnection^>(SimObject::Wrap(obj)); };

      EngineNetConnection* GetObjectPtr(){
         return static_cast<EngineNetConnection*>(mObject);
      };

      String^ getAddress();
      void setSimulatedNetParams(float packetLoss, int delay);
      int getPing();
      int getPacketLoss();
      void checkMaxRate();
      void setLogging(bool value);
      NetObject^ resolveGhostID(int ghostID);
      NetObject^ resolveObjectFromGhostIndex(int ghostIdx);
      int getGhostID(NetObject^ object);
      void connect(String^ remoteAddress);
      String^ connectLocal();
      int getGhostsActive();
   };

   public ref class NetObject : SimObject
   {
   public:
      static NetObject^ Wrap(int ID) { return static_cast<NetObject^>(SimObject::Wrap(ID)); };
      static NetObject^ Wrap(EngineNetObject* obj) { return static_cast<NetObject^>(SimObject::Wrap(obj)); };

      EngineNetObject* GetObjectPtr(){
         return static_cast<EngineNetObject*>(mObject);
      };

      void scopeToClient(NetConnection^ client);
      void clearScopeToClient(NetConnection^ client);
      void setScopeAlways();
      int getGhostID();
   };

   public ref class TCPObject : SimObject
   {
   public:
      static TCPObject^ Wrap(int ID) { return static_cast<TCPObject^>(SimObject::Wrap(ID)); };
      static TCPObject^ Wrap(EngineTCPObject* obj) { return static_cast<TCPObject^>(SimObject::Wrap(obj)); };

      EngineTCPObject* GetObjectPtr(){
         return static_cast<EngineTCPObject*>(mObject);
      };

      void send(...array<String^>^ args);
      void listen(int port);
      void connect(String^ address);
      void openAndConnect(String^ address);
      void disconnect();
      String^ URLEncodeString(String^ data);
   };

   public ref class HTTPObject : TCPObject
   {
   public:
      static HTTPObject^ Wrap(int ID) { return static_cast<HTTPObject^>(SimObject::Wrap(ID)); };
      static HTTPObject^ Wrap(EngineHTTPObject* obj) { return static_cast<HTTPObject^>(SimObject::Wrap(obj)); };

      EngineHTTPObject* GetObjectPtr(){
         return static_cast<EngineHTTPObject*>(mObject);
      };

      void get(String^ address, String^ requestURI, String^ query);
      void get(String^ address, String^ requestURI);
      void post(String^ address, String^ requestURI, String^ query, String^ post);
   };
}
