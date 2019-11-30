#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_
#include "SDL2/SDL.h"
#include "Application.h"

class Environment 
{
		float lastTime;
		float time;
		float diff;
		float deltaTime;
		float idealTime;
public:
		void CalcTime();
};
#endif
