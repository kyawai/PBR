#include <iostream>
#include "Application.h"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 1020


std::shared_ptr<Application> Application::Initialize()
{
	std::shared_ptr<Application> ini = std::make_shared<Application>();
	ini->self = ini;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw rend::Exception("Failed to initialise at Application::Initialize");
	}

	ini->window = SDL_CreateWindow("MYENGINE",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(ini->window))
	{
		throw rend::Exception("failed to create window");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(ini->window);
	if (!glContext)
	{
		throw rend::Exception("failed to create opengl cotext");
	}


	ini->device = alcOpenDevice(NULL);

	if (!ini->device)
	{
			throw std::exception();
	}
	ini->soundContext = alcCreateContext(ini->device, NULL);

	if (!ini->soundContext)
	{
			alcCloseDevice(ini->device);
			throw std::exception();
	}
	if (!alcMakeContextCurrent(ini->soundContext))
	{
			alcDestroyContext(ini->soundContext);
			alcCloseDevice(ini->device);
			throw std::exception();
	}
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

	ini->context = rend::Context::initialize();
	return ini;
}

Application::~Application()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
	alcMakeContextCurrent(NULL);
	alcDestroyContext(soundContext);
	alcCloseDevice(device);
}

std::shared_ptr<Entity> Application::AddEntity()
{
	std::shared_ptr<Entity> ent = std::make_shared<Entity>();
	entities.push_back(ent);
	ent->app = self;
	ent->self = ent;
	return ent;
}

void Application::Run()
{

	bool quit = false;
	while (!quit)
	{
		SDL_Event event = { 0 };
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->tick();
		//	std::cout << "entity tick" << std::endl;
		}


		for (std::vector<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->display();
		//	std::cout << "entities display" << std::endl;
		}

		SDL_GL_SwapWindow(window);
	}

}

void Application::Stop()
{
	running = false;
}
