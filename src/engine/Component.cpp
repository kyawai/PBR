#include "Component.h"
#include "Entity.h"
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "glm/glm.hpp"

std::shared_ptr<Entity> Component::getEntity()
{
	std::shared_ptr<Entity> addent = std::make_shared<Entity>();
	return entity.lock();
}

//std::shared_ptr<Application> Component::getApp()
//{
//	std::shared_ptr<Application> addapp = std::make_shared<Application>();
//	return addapp;
//}

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
	//	std::shared_ptr<Application> retApp = std::make_shared<Application>();
	return app.lock();
}
