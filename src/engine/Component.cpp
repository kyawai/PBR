#include "Component.h"
#include "Entity.h"
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "glm/glm.hpp"

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

void Component::onInit()
{
}

void Component::onBegin()
{
}

void Component::onTick()
{
}

void Component::onDisplay()
{
}

std::shared_ptr<Application> Component::getApp()
{
	return app.lock();
}
