// IJWLayer.h

#pragma once

#include "CollectionsWrapper.h"
#include "network/netObject.h"
#include "network/netConnection.h"
#include "network/tcpObject.h"
#include "network/httpObject.h"

namespace IJWLayer {

   ref class NetObjectWrapper;

   public ref class NetConnectionWrapper : SimGroupWrapper
   {
   public:
      static NetConnectionWrapper^ Wrap(int ID) { return static_cast<NetConnectionWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static NetConnectionWrapper^ Wrap(NetConnection* obj) { return static_cast<NetConnectionWrapper^>(SimObjectWrapper::Wrap(obj)); };

      NetConnection* GetObjectPtr(){
         return static_cast<NetConnection*>(mObject);
      };

      String^ getAddress();
      void setSimulatedNetParams(float packetLoss, int delay);
      int getPing();
      int getPacketLoss();
      void checkMaxRate();
      void setLogging(bool value);
      NetObjectWrapper^ resolveGhostID(int ghostID);
      NetObjectWrapper^ resolveObjectFromGhostIndex(int ghostIdx);
      int getGhostID(NetObjectWrapper^ object);
      void connect(String^ remoteAddress);
      String^ connectLocal();
      int getGhostsActive();
   };

   public ref class NetObjectWrapper : SimObjectWrapper
   {
   public:
      static NetObjectWrapper^ Wrap(int ID) { return static_cast<NetObjectWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static NetObjectWrapper^ Wrap(NetObject* obj) { return static_cast<NetObjectWrapper^>(SimObjectWrapper::Wrap(obj)); };

      NetObject* GetObjectPtr(){
         return static_cast<NetObject*>(mObject);
      };

      void scopeToClient(NetConnectionWrapper^ client);
      void clearScopeToClient(NetConnectionWrapper^ client);
      void setScopeAlways();
      int getGhostID();
   };

   public ref class TCPObjectWrapper : SimObjectWrapper
   {
   public:
      static TCPObjectWrapper^ Wrap(int ID) { return static_cast<TCPObjectWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static TCPObjectWrapper^ Wrap(TCPObject* obj) { return static_cast<TCPObjectWrapper^>(SimObjectWrapper::Wrap(obj)); };

      TCPObject* GetObjectPtr(){
         return static_cast<TCPObject*>(mObject);
      };

      void send(...array<String^>^ args);
      void listen(int port);
      void connect(String^ address);
      void openAndConnect(String^ address);
      void disconnect();
      String^ URLEncodeString(String^ data);
   };

   public ref class HTTPObjectWrapper : TCPObjectWrapper
   {
   public:
      static HTTPObjectWrapper^ Wrap(int ID) { return static_cast<HTTPObjectWrapper^>(SimObjectWrapper::Wrap(ID)); };
      static HTTPObjectWrapper^ Wrap(HTTPObject* obj) { return static_cast<HTTPObjectWrapper^>(SimObjectWrapper::Wrap(obj)); };

      HTTPObject* GetObjectPtr(){
         return static_cast<HTTPObject*>(mObject);
      };

      void get(String^ address, String^ requestURI, String^ query);
      void get(String^ address, String^ requestURI);
      void post(String^ address, String^ requestURI, String^ query, String^ post);
   };
}
