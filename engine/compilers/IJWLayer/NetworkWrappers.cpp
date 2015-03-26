#include "Stdafx.h"
#include "NetworkWrappers.h"
#include "MarshalHelper.h"

using namespace System::Runtime::InteropServices;
using System::String;

void IJWLayer::NetObjectWrapper::scopeToClient(NetConnectionWrapper^ client)
{
   if (!IsAlive())
      return;
   if (!client->IsAlive())
   {
      Con::errorf(ConsoleLogEntry::General, "NetObject::scopeToClient: Couldn't find connection %s", "TODO, implement references");
      return;
   }
   client->GetObjectPtr()->objectLocalScopeAlways(GetObjectPtr());
}

void IJWLayer::NetObjectWrapper::clearScopeToClient(NetConnectionWrapper^ client)
{
   if (!IsAlive())
      return;
   if (!client->IsAlive())
   {
      Con::errorf(ConsoleLogEntry::General, "NetObject::clearScopeToClient: Couldn't find connection %s", "TODO, implement references");
      return;
   }
   client->GetObjectPtr()->objectLocalClearAlways(GetObjectPtr());
}

void IJWLayer::NetObjectWrapper::setScopeAlways()
{
   if (IsAlive())
      GetObjectPtr()->setScopeAlways();
}

int IJWLayer::NetObjectWrapper::getGhostID()
{
   if (!IsAlive())
      return -1;
   return GetObjectPtr()->getNetIndex();
}

void IJWLayer::TCPObjectWrapper::send(...array<String^>^ args)
{
   if (!IsAlive())
      return;
   for (int i = 0; i < args->Length; i++)
   {
      const char* arg = (char*)Marshal::StringToHGlobalAnsi(args[i]).ToPointer();
      GetObjectPtr()->send((const U8 *)arg, args[i]->Length);
   }
}

void IJWLayer::TCPObjectWrapper::listen(int port)
{
   if (IsAlive())
      GetObjectPtr()->listen(port);
}

void IJWLayer::TCPObjectWrapper::connect(String^ address)
{
   if (!IsAlive())
      return;
   
   const char* addr = (char*)Marshal::StringToHGlobalAnsi(address).ToPointer();
   GetObjectPtr()->connect(addr);
}

void IJWLayer::TCPObjectWrapper::openAndConnect(String^ address)
{
   if (!IsAlive())
      return;
   
   const char* addr = (char*)Marshal::StringToHGlobalAnsi(address).ToPointer();
   GetObjectPtr()->openAndConnect(addr);
}

void IJWLayer::TCPObjectWrapper::disconnect()
{
   if (!IsAlive())
      return;
   
   GetObjectPtr()->disconnect();
}

String^ IJWLayer::TCPObjectWrapper::URLEncodeString(String^ data)
{
   if (!IsAlive())
      return nullptr;

   const char* _data = (char*)Marshal::StringToHGlobalAnsi(data).ToPointer();

   U8	*pEncodedString;
   U32	iNewBufferLen;


   pEncodedString = GetObjectPtr()->URLEncodeData((U8 *)_data, dStrlen(_data) + 1, &iNewBufferLen);

   //copy string to return buffer
   char	*pcReturnBuffer = Con::getReturnBuffer(iNewBufferLen);
   dMemcpy(pcReturnBuffer, pEncodedString, iNewBufferLen);

   //free encoded data pointer
   dFree((void *)pEncodedString);

   return gcnew String(pcReturnBuffer);
}

void IJWLayer::HTTPObjectWrapper::get(String^ address, String^ requestURI, String^ query)
{
   if (!IsAlive())
      return;

   const char* _address = (char*)Marshal::StringToHGlobalAnsi(address).ToPointer();
   const char* _requestURI = (char*)Marshal::StringToHGlobalAnsi(requestURI).ToPointer();
   const char* _query = NULL;
   if (query != nullptr)
       _query = (char*)Marshal::StringToHGlobalAnsi(query).ToPointer();

   GetObjectPtr()->get(_address, _requestURI, _query);
}

void IJWLayer::HTTPObjectWrapper::get(String^ address, String^ requestURI)
{
   get(address, requestURI, nullptr);
}

void IJWLayer::HTTPObjectWrapper::post(String^ address, String^ requestURI, String^ query, String^ post)
{
   if (!IsAlive())
      return;

   const char* _address = (char*)Marshal::StringToHGlobalAnsi(address).ToPointer();
   const char* _requestURI = (char*)Marshal::StringToHGlobalAnsi(requestURI).ToPointer();
   const char* _query = (char*)Marshal::StringToHGlobalAnsi(query).ToPointer();
   const char* _post = (char*)Marshal::StringToHGlobalAnsi(post).ToPointer();

   GetObjectPtr()->post(_address, _requestURI, _query, _post);
}

String^ IJWLayer::NetConnectionWrapper::getAddress()
{
   if (!IsAlive())
      return nullptr;
   if (GetObjectPtr()->isLocalConnection())
      return "local";
   char *buffer = Con::getReturnBuffer(256);
   Net::addressToString(GetObjectPtr()->getNetAddress(), buffer);
   return gcnew String(buffer);
}

void IJWLayer::NetConnectionWrapper::setSimulatedNetParams(float packetLoss, int delay)
{
   if (IsAlive())
      GetObjectPtr()->setSimulatedNetParams(packetLoss, delay);
}

int IJWLayer::NetConnectionWrapper::getPing()
{
   if (IsAlive())
      return GetObjectPtr()->getRoundTripTime();
   return -1;
}

int IJWLayer::NetConnectionWrapper::getPacketLoss()
{
   if (IsAlive())
      return 100 * GetObjectPtr()->getPacketLoss();
   return -1;
}

void IJWLayer::NetConnectionWrapper::checkMaxRate()
{
   if (IsAlive())
      GetObjectPtr()->checkMaxRate();
}

void IJWLayer::NetConnectionWrapper::setLogging(bool value)
{
#ifdef TORQUE_DEBUG_NET
   if (IsAlive())
      GetObjectPtr()->setLogging(value);
#endif
}

IJWLayer::NetObjectWrapper^ IJWLayer::NetConnectionWrapper::resolveGhostID(int ghostId)
{
   if (!IsAlive())
      return nullptr;

   // Safety check
   if (ghostId < 0 || ghostId > NetConnection::MaxGhostCount) return nullptr;

   return gcnew NetObjectWrapper(GetObjectPtr()->resolveGhost(ghostId));
}

IJWLayer::NetObjectWrapper^ IJWLayer::NetConnectionWrapper::resolveObjectFromGhostIndex(int ghostId)
{
   if (!IsAlive())
      return nullptr;

   // Safety check
   if (ghostId < 0 || ghostId > NetConnection::MaxGhostCount) return nullptr;

   return gcnew NetObjectWrapper(GetObjectPtr()->resolveObjectFromGhostIndex(ghostId));
}

int IJWLayer::NetConnectionWrapper::getGhostID(IJWLayer::NetObjectWrapper^ object)
{
   if (IsAlive() && object->IsAlive())
      return GetObjectPtr()->getGhostIndex(object->GetObjectPtr());

   Con::errorf("NetConnection::serverToGhostID - could not find specified object");
   return -1;
}

void IJWLayer::NetConnectionWrapper::connect(String^ remoteAddress)
{
   if (!IsAlive())
      return;

   const char* _remoteAddress = (char*)Marshal::StringToHGlobalAnsi(remoteAddress).ToPointer();
   NetAddress addr;
   if (!Net::stringToAddress(_remoteAddress, &addr))
   {
      Con::errorf("NetConnection::connect: invalid address - %s", _remoteAddress);
      return;
   }
   GetObjectPtr()->connect(&addr);
}

String^ IJWLayer::NetConnectionWrapper::connectLocal()
{
   if (!IsAlive())
      return nullptr;
   ConsoleObject *co = ConsoleObject::create(GetObjectPtr()->getClassName());
   NetConnection *client = GetObjectPtr();
   NetConnection *server = dynamic_cast<NetConnection *>(co);
   const char *error = NULL;
   BitStream *stream = BitStream::getPacketStream();

   if (!server || !server->canRemoteCreate())
      goto errorOut;
   server->registerObject();
   server->setIsLocalClientConnection();

   server->setSequence(0);
   client->setSequence(0);
   client->setRemoteConnectionObject(server);
   server->setRemoteConnectionObject(client);

   stream->setPosition(0);
   client->writeConnectRequest(stream);
   stream->setPosition(0);
   if (!server->readConnectRequest(stream, &error))
      goto errorOut;

   stream->setPosition(0);
   server->writeConnectAccept(stream);
   stream->setPosition(0);

   if (!client->readConnectAccept(stream, &error))
      goto errorOut;

   client->onConnectionEstablished(true);
   server->onConnectionEstablished(false);
   client->setEstablished();
   server->setEstablished();
   client->setConnectSequence(0);
   server->setConnectSequence(0);
   NetConnection::setLocalClientConnection(server);
   server->assignName("LocalClientConnection");
   return "";

errorOut:
   server->deleteObject();
   client->deleteObject();
   if (!error)
      error = "Unknown Error";
   return gcnew String(error);
}

int IJWLayer::NetConnectionWrapper::getGhostsActive()
{
   if (IsAlive())
      return GetObjectPtr()->getGhostsActive();
   return -1;
}