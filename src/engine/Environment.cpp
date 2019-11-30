#include "Environment.h"
#include <iostream>
void Environment::CalcTime()
{
		lastTime = SDL_GetTicks();
		diff = time - lastTime;
		deltaTime = diff / 1000.0f;
		lastTime = time;

		idealTime = 1.0f / 60.0f;

		if (idealTime > deltaTime)
		{
				SDL_Delay((idealTime - deltaTime)*1000.0f);
		}

}
