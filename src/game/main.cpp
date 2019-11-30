#include <iostream>
#include <memory>


#include <engine/Application.h>
#include <engine/Component.h>
#include <engine/Entity.h>
//#include <engine/Exception.h>
#include <engine/Renderer.h>
#include <engine/Transform.h>

int main()
{
	std::shared_ptr<Application> app = Application::Initialize();
	std::shared_ptr<Entity> ent = app->AddEntity();
	std::shared_ptr<Renderer> rend = ent->addComponent<Renderer>();
	std::shared_ptr<Entity> cameraEnt = app->AddEntity();
	std::shared_ptr<Camera> camera = cameraEnt->addComponent<Camera>();
	camera->CamIni(120);
	std::shared_ptr<Transform> transform = ent->addComponent<Transform>();
	transform->SetRotation(10.0f, 0.0f, 0.0f);
	rend->RenderInitialise("../Shaders/basicShader.txt", "../models/graveyard.obj", "../models/graveyard.png", camera);
	std::shared_ptr<Audio> sound = ent->addComponent<Audio>();
	sound->AudioInit("../sounds/0229.ogg");
	sound->PlayAudio();

	app->Run();
	//std::cout << "game RUnning" << std::endl;
	
return 0;
}