using System::String;

#include "../../ConsoleTypes/Headers/Points.h"
#include "../../SimObjects/Headers/SimObjectWrapper.h"
//#include "audio/audio.h"

namespace IJWLayer
{
   /*
   public ref class Audio
   {
   public:
      enum class ALEnum{
         GAIN = AL_GAIN,
         GAIN_LINEAR = AL_GAIN_LINEAR,
         PITCH = AL_PITCH,
         REFERENCE_DISTANCE = AL_REFERENCE_DISTANCE,
         MAX_DISTANCE = AL_MAX_DISTANCE,
         CONE_OUTER_GAIN = AL_CONE_OUTER_GAIN,
         POSITION = AL_POSITION,
         DIRECTION = AL_DIRECTION,
         VELOCITY = AL_VELOCITY,
         ORIENTATION = AL_ORIENTATION,
         CONE_INNER_ANGLE = AL_CONE_INNER_ANGLE,
         CONE_OUTER_ANGLE = AL_CONE_OUTER_ANGLE,
         LOOPING = AL_LOOPING,
         SAMPLE_OFFSET = AL_SAMPLE_OFFSET,
         SEC_OFFSET = AL_SEC_OFFSET,
         BYTE_OFFSET = AL_BYTE_OFFSET,
         VENDOR = AL_VENDOR,
         VERSION = AL_VERSION,
         RENDERER = AL_RENDERER,
         EXTENSIONS = AL_EXTENSIONS,
         INVALID = AL_INVALID
      };

      ref class OpenAL
      {
      public: 
         static bool InitDriver();
         static void ShutdownDriver();
         static void RegisterExtensions();
         static String^ GetString(ALEnum ALEnum);
         static int GetAudioLength(String^ audioAssetId);
         static int CreateSource(String^ audioAssetId);
         static void SourceF(U32 handle, ALEnum ALEnum, float value);
         static void Source3F(U32 handle, ALEnum ALEnum, Point3F position);
         static void SourceI(U32 handle, ALEnum ALEnum, int value);
         static float GetSourceF(U32 handle, ALEnum ALEnum);
         static Point3F^ GetSource3F(U32 handle, ALEnum ALEnum);
         static int GetSourceI(U32 handle, ALEnum ALEnum);
         static int Play(String^ audioAssetId);
         static bool Pause(U32 handle);
         static void Unpause(U32 handle);
         static void Stop(U32 handle);
         static void StopAll();
         static bool IsPlaying(U32 handle);
         static void ListenerF(ALEnum ALEnum, float value);
         static void Listener3F(ALEnum ALEnum, Point3F^ position);
         static float GetListenerF(ALEnum ALEnum);
         static Point3F^ GetListener3F(ALEnum ALEnum);
         static int GetListenerI(ALEnum ALEnum);
         static float GetChannelVolume(U32 ChannelID);
         static bool SetChannelVolume(U32 ChannelID, float volume);
         static int GetStreamPosition(U32 handle);
         static float GetStreamDuration(U32 handle);
         static int StartiOSAudioStream(String^ audioAssetId);
         static void StopiOSAudioStream(String^ audioAssetId);
         static void SetiOSAudioStreamVolume(SimObject^ streamID, float volume);
      };
   };
      */
}