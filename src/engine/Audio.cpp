#include "Audio.h"
#include <stb_vorbis.h>


Audio::Audio()
{
}


Audio::~Audio()
{
		alcMakeContextCurrent(NULL);
}

void Audio::AudioInit(char * _audio)
{
		alGenBuffers(1, &id);
		LoadAudio(_audio);
		alBufferData(id, format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), freq);

}

void Audio::PlayAudio()
{
		alGenSources(1, &sid);
		alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, id);
		alSourcePlay(sid);
}

void Audio::LoadAudio(char * _audio)
{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;
		size_t samples = stb_vorbis_decode_filename(_audio, &channels, &sampleRate, &output);
		if (samples == -1)
		{
				throw std::exception();
		}
		freq = sampleRate;
		if (channels == 1)
		{
				format = AL_FORMAT_MONO16;
		}
		else
		{
				format = AL_FORMAT_STEREO16;
		}
		bufferData.resize(sizeof(*output)*channels*samples);
		memcpy(&bufferData.at(0), output, bufferData.size());
		free(output);
}

bool Audio::CheckPlaying()
{
		alGetSourcei(sid, AL_SOURCE_STATE, &state);
		return (state == AL_PLAYING);
}
