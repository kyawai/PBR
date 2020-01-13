#ifndef _ENTITY_H_	
#define _ENTITY_H_

#include <memory>
#include "Application.h"
#include <vector>
class Component;
class Application;



class Entity
{
	friend Application;
	std::weak_ptr<Application> app;
	std::vector<std::shared_ptr<Component>> components;
	std::shared_ptr<Entity> self;

public:

	//std::shared_ptr<Application> app;
	template<class T>
	std::shared_ptr<T> getComponent()
	{
			std::shared_ptr<T> rtn;
			for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
			{
					rtn = std::dynamic_pointer_cast<T>(*it);

					if (rtn)
					{
							return rtn;
					}
					
			}
	}

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
