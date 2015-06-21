#include "../../stdafx.h"
#include "../Headers/Audio.h"
/*

// #pragma unmanaged
// push managed state on to stack and set unmanaged state
#pragma managed(push, off)

#include "assets/assetManager.h"

// #pragma unmanaged
#pragma managed(pop)

namespace EngineAudio = Audio;
using System::NotImplementedException;
using namespace System::Runtime::InteropServices;

extern ALuint alxGetWaveLen(ALuint buffer);
extern F32 mAudioChannelVolumes[Audio::AudioVolumeChannels];

bool IJWLayer::Audio::OpenAL::InitDriver()
{
   if (EngineAudio::OpenALInit())
   {
      static bool registered = false;
      if (!registered) {
         ResourceManager->registerExtension(".wav", AudioBuffer::construct);
      }
      registered = true;
      return true;
   }
   return false;
}

void IJWLayer::Audio::OpenAL::ShutdownDriver()
{
   EngineAudio::OpenALShutdown();
}

void IJWLayer::Audio::OpenAL::RegisterExtensions()
{
   throw gcnew NotImplementedException("");
}

String^ IJWLayer::Audio::OpenAL::GetString(ALEnum pALEnum)
{
   if ((int)pALEnum == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "alGetString: invalid enum provided");
      return "";
   }

   return gcnew String((const char*)alGetString((int)pALEnum));
}

int IJWLayer::Audio::OpenAL::GetAudioLength(String^ audioAssetId)
{
   char* _audioAssetId = (char*)Marshal::StringToHGlobalAnsi(audioAssetId).ToPointer();
   
   // Acquire audio asset.
   AudioAsset* pAudioAsset = AssetDatabase.acquireAsset<AudioAsset>(_audioAssetId);

   // Did we get the audio asset?
   if (pAudioAsset == NULL)
   {
      // No, so warn.
      Con::warnf("alxGetAudioLength() - Could not find audio asset '%s'.", _audioAssetId);
      return 0;
   }

   Resource<AudioBuffer> buffer = AudioBuffer::find(pAudioAsset->getAudioFile());

   if (!buffer.isNull())
   {
      ALuint alBuffer = buffer->getALBuffer();
      return alxGetWaveLen(alBuffer);
   }

   // Warn.
   Con::warnf("alxGetAudioLength() - Could not find audio file '%s' for asset '%s'.", pAudioAsset->getAudioFile(), _audioAssetId);

   return 0;
}

int IJWLayer::Audio::OpenAL::CreateSource(String^ audioAssetId)
{
   char* _audioAssetId = (char*)Marshal::StringToHGlobalAnsi(audioAssetId).ToPointer();

   // Acquire audio asset.
   AudioAsset* pAudioAsset = AssetDatabase.acquireAsset<AudioAsset>(_audioAssetId);

   // Did we get the audio asset?
   if (pAudioAsset == NULL)
   {
      // No, so warn.
      Con::warnf("alxCreateSource() - Could not find audio asset '%s'.", _audioAssetId);
      return NULL_AUDIOHANDLE;
   }

   // Fetch audio handle.
   AUDIOHANDLE handle = alxCreateSource(pAudioAsset);

   // Release asset.
   AssetDatabase.releaseAsset(_audioAssetId);

   return handle;
}

void IJWLayer::Audio::OpenAL::SourceF(U32 handle, ALEnum e, float value)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "cAudio_alxSourcef: invalid enum provided");
      return;
   }

   alxSourcef(handle, (int)e, value);
}

void IJWLayer::Audio::OpenAL::Source3F(U32 handle, ALEnum e, Point3F pos)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "cAudio_alxSourcef: invalid enum provided");
      return;
   }

   alxSource3f(handle, (int)e, pos.x, pos.y, pos.z);
}

void IJWLayer::Audio::OpenAL::SourceI(U32 handle, ALEnum e, int val)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "cAudio_alxSourcef: invalid enum provided");
      return;
   }

   alxSourcei(handle, (int)e, val);
}

float IJWLayer::Audio::OpenAL::GetSourceF(U32 handle, ALEnum e)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "cAudio_alxSourcef: invalid enum provided");
      return -1;
   }

   F32 value;
   alxGetSourcef(handle, (int)e, &value);
   return value;
}

IJWLayer::Point3F^ IJWLayer::Audio::OpenAL::GetSource3F(U32 handle, ALEnum e)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "cAudio_alxSourcef: invalid enum provided");
      return nullptr;
   }

   F32 value1, value2, value3;
   alxGetSource3f(handle, (int)e, &value1, &value2, &value3);

   return gcnew Point3F(value1, value2, value3);
}

int IJWLayer::Audio::OpenAL::GetSourceI(U32 handle, ALEnum e)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "cAudio_alxSourcef: invalid enum provided");
      return -1;
   }

   ALint value;
   alxGetSourcei(handle, (int)e, &value);
   return(static_cast<S32>(value));
}

int IJWLayer::Audio::OpenAL::Play(String^ audioAssetId)
{
   char* _audioAssetId = (char*)Marshal::StringToHGlobalAnsi(audioAssetId).ToPointer();

   // Acquire audio asset.
   AudioAsset* pAudioAsset = AssetDatabase.acquireAsset<AudioAsset>(_audioAssetId);

   // Did we get the audio asset?
   if (pAudioAsset == NULL)
   {
      // No, so warn.
      Con::warnf("alxPlay() - Could not find audio asset '%s'.", _audioAssetId);
      return NULL_AUDIOHANDLE;
   }

   // Fetch audio handle.
   AUDIOHANDLE handle = alxPlay(pAudioAsset);

   // Release asset.
   AssetDatabase.releaseAsset(_audioAssetId);

   return handle;
}

bool IJWLayer::Audio::OpenAL::Pause(U32 handle)
{
   if (handle == NULL_AUDIOHANDLE)
      return false;
   return alxPause(handle);
}

void IJWLayer::Audio::OpenAL::Unpause(U32 handle)
{
   if (handle == NULL_AUDIOHANDLE)
      return;
   alxUnPause(handle);
}

void IJWLayer::Audio::OpenAL::Stop(U32 handle)
{
   if (handle == NULL_AUDIOHANDLE)
      return;
   alxStop(handle);
}

void IJWLayer::Audio::OpenAL::StopAll()
{
   alxStopAll();
}

bool IJWLayer::Audio::OpenAL::IsPlaying(U32 handle)
{
   if (handle == NULL_AUDIOHANDLE)
      return false;
   return alxIsPlaying(handle);
}

void IJWLayer::Audio::OpenAL::ListenerF(ALEnum e, float value)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "alxListenerf: invalid enum provided");
      return;
   }

   alxListenerf((int)e, value);
}

void IJWLayer::Audio::OpenAL::Listener3F(ALEnum e, Point3F^ position)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "alxListenerf: invalid enum provided");
      return;
   }

   alxListenerPoint3F((int)e, &position->ToEngine());
}

float IJWLayer::Audio::OpenAL::GetListenerF(ALEnum e)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "alxGetListenerf: invalid enum provided");
      return(0.f);
   }

   F32 value;
   alxGetListenerf((int)e, &value);
   return(value);
}

IJWLayer::Point3F^ IJWLayer::Audio::OpenAL::GetListener3F(ALEnum e)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "alxGetListenerf: invalid enum provided");
      return nullptr;
   }

   EnginePoint3F v;
   alxGetListenerPoint3F((int)e, &v);

   return Point3F::FromEngine(v);
}

int IJWLayer::Audio::OpenAL::GetListenerI(ALEnum e)
{
   if ((int)e == AL_INVALID)
   {
      Con::errorf(ConsoleLogEntry::General, "alxGetListenerf: invalid enum provided");
      return(0.f);
   }

   int value;
   alGetListeneri((int)e, &value);
   return(value);
}

float IJWLayer::Audio::OpenAL::GetChannelVolume(U32 ChannelID)
{
   if (ChannelID >= EngineAudio::AudioVolumeChannels)
   {
      Con::errorf(ConsoleLogEntry::General, "alxGetChannelVolume: invalid channel '%d'", ChannelID);
      return(0.f);
   }

   return(mAudioChannelVolumes[ChannelID]);
}

bool IJWLayer::Audio::OpenAL::SetChannelVolume(U32 ChannelID, float volume)
{
   if (ChannelID >= EngineAudio::AudioVolumeChannels)
   {
      Con::errorf(ConsoleLogEntry::General, "alxGetChannelVolume: invalid channel '%d'", ChannelID);
      return(0.f);
   }
   volume = mClampF(volume, 0.f, 1.f);

   mAudioChannelVolumes[ChannelID] = volume;
   alxUpdateTypeGain(ChannelID);
   return true;
}

int IJWLayer::Audio::OpenAL::GetStreamPosition(U32 handle)
{
   if (handle == NULL_AUDIOHANDLE)
      return -1;

   return alxGetStreamPosition(handle);
}

float IJWLayer::Audio::OpenAL::GetStreamDuration(U32 handle)
{
   if (handle == NULL_AUDIOHANDLE)
      return -1;

   return alxGetStreamDuration(handle);
}

int IJWLayer::Audio::OpenAL::StartiOSAudioStream(String^ audioAssetId)
{
#ifdef TORQUE_OS_IOS
   char* _audioAssetId = (char*)Marshal::StringToHGlobalAnsi(audioAssetId).ToPointer();

   // Acquire audio asset.
   AudioAsset* pAudioAsset = AssetDatabase.acquireAsset<AudioAsset>(pAssetId);

   // Did we get the audio asset?
   if (pAudioAsset == NULL)
   {
      // No, so warn.
      Con::warnf("startiOSAudioStream() - Could not find audio asset '%s'.", pAssetId);
      return 0;
   }

   // Fetch the audio filename,
   char fileName[1024];
   Con::expandPath(fileName, sizeof(fileName), pAudioAsset->getAudioFile());
   iOSStreamSource* pStream = new iOSStreamSource(fileName);
   pStream->start(pAudioAsset->getLooping());

   // Release asset.
   AssetDatabase.releaseAsset(pAssetId);

   return pStream->getId();
#else
   throw gcnew Exception("This is not iOS");
#endif
}

void IJWLayer::Audio::OpenAL::StopiOSAudioStream(String^ audioAssetId)
{
#ifdef TORQUE_OS_IOS
#else
   throw gcnew Exception("This is not iOS");
#endif
}

void IJWLayer::Audio::OpenAL::SetiOSAudioStreamVolume(SimObject^ streamID, float volume)
{
#ifdef TORQUE_OS_IOS
#else
   throw gcnew Exception("This is not iOS");
#endif
}
*/