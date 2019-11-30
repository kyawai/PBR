#ifndef _ENTITY_H_	
#define _ENTITY_H_

#include <memory>
#include "Application.h"
#include "Component.h"
#include <vector>
class Component;
class Application;



class Entity
{
	friend Application;
	std::weak_ptr<Application> app;
	std::vector<std::shared_ptr<Component>> components;

public:
	std::shared_ptr<Entity> self;
	std::shared_ptr<Application> getApp;
	template<class T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> ret = std::make_shared<T>();
		components.push_back(ret);
		ret->entity = self;
		ret->app = app;
		return ret;
	}
	template<class T, class A>
	std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> ret = std::make_shared<T>(a);
		components.push_back(ret);
		ret->entity = self;
		ret->app = app;
		return ret;
	}
	template<class T, class A, class B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		std::shared_ptr<T> ret = std::make_shared<T>(a,b);
		components.push_back(ret);
		ret->entity = self;
		ret->app = app;
		return ret;
	}
	template<class T, class A, class B, class C>
	std::shared_ptr<T> addComponent(A a, B b, C c)
	{
		std::shared_ptr<T> ret = std::make_shared<T>(a,b,c);
		components.push_back(ret);
		ret->entity = self;
		ret->app = app;
		return ret;
	}


	void tick();
	void display();


};




#endif // ! _ENTITY_H_
