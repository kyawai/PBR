#include "Entity.h"
#include <iostream>

void Entity::tick()
{
	for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->onTick();
//		std::cout << "entity on tick" << std::endl;
	}
}

void Entity::display()
{
	for (std::vector<std::shared_ptr<Component>>::iterator it = components.begin(); it != components.end(); it++)
	{
		(*it)->onDisplay();
	}
}

//std::shared_ptr<Component> Entity::AddComponent()
//{
//	std::shared_ptr<Component> comp = std::make_shared<Component>();
//	components.push_back(comp);
//	return comp;
//}
