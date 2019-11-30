#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "openAL/AL/al.h"
#include "openAL/AL/alc.h"
#include "Component.h"
#include <vector>


class Audio : public Component

{
		ALuint id = 0;
		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;
		ALuint sid = 0;
		ALint state = 0;

public:
		Audio();
		~Audio();
		void AudioInit(char* _audio);
		void PlayAudio();
		void LoadAudio(char* _audio);
		bool CheckPlaying();
};


#endif
