#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <memory>
#include <iostream>
#include <glm/glm.hpp>

class Application;
class Entity;

class Component
{
	friend Entity;

	std::weak_ptr<Entity> entity;

public:
	std::shared_ptr<Entity> getEntity();
	std::weak_ptr<Application> app;
	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();
	std::shared_ptr<Application> getApp();

};



#endif // ! _COMPONENTS_H_
