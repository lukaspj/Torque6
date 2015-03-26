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
      NetConnectionWrapper(int ID) : SimGroupWrapper(ID){};

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
      NetObjectWrapper(int ID) : SimObjectWrapper(ID){};
      NetObjectWrapper(NetObject* object) : SimObjectWrapper(object){};

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
      TCPObjectWrapper(int ID) : SimObjectWrapper(ID){};

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
      HTTPObjectWrapper(int ID) : TCPObjectWrapper(ID){};

      HTTPObject* GetObjectPtr(){
         return static_cast<HTTPObject*>(mObject);
      };

      void get(String^ address, String^ requestURI, String^ query);
      void get(String^ address, String^ requestURI);
      void post(String^ address, String^ requestURI, String^ query, String^ post);
   };
}
