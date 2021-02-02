///
///  @file  SoundSource.cpp
///  @brief Manages the sounds throughout the scene

//  header includes
#include "SoundSource.h"

namespace whyengine
{
  //  initlize the values
  void SoundSource::onInitialize(std::shared_ptr<Sound> sound)
  {
    alGenBuffers(1, &sid);
    alSourcei(sid, AL_BUFFER, sound->id);
    alSourcePlay(sid);
  }

  void SoundSource::onTick()
  {
    ALint state = 0;
    alGetSourcei(sid, AL_SOURCE_STATE, &state);

    if(state == AL_STOPPED)
    {
      destroy();
    }
  }

  void SoundSource::onDestroy()
  {
    alDeleteSources(1, &sid);
  }
}