#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <memory>
#include <vector>
#include <list>
#include "Environment.h"
#include "Entity.h"
#include "Component.h"
#include "Renderer.h"
#include <rend/rend.h>
#include "SDL2/SDL.h"
#include "Audio.h"

class Application;
class Entity;

class Application
{
	bool running;
	std::vector<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Application> self;
	SDL_Window* window;
	ALCdevice* device;
	ALCcontext* soundContext;

public:
	std::sr1::shared_ptr<rend::Context> context;
	static std::shared_ptr<Application> Initialize();
	void Run();
	std::shared_ptr<Entity> AddEntity();
	void Stop();
	~Application();
};

#endif // !_APPLICATION_H_
