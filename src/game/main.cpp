#include <iostream>
#include <memory>


#include <engine/Application.h>
#include <engine/Component.h>
#include <engine/Entity.h>
//#include <engine/Exception.h>
#include <engine/Renderer.h>
#include <engine/Transform.h>
#include <engine/PBR.h>

int main()
{
	std::shared_ptr<Application> app = Application::Initialize(); 
	std::shared_ptr<Entity> ent = app->AddEntity();

	std::shared_ptr<Entity> cameraEnt = app->AddEntity();
	std::shared_ptr<Transform> cameraTransform = cameraEnt->addComponent<Transform>();
	cameraTransform->SetPos(glm::vec3(0, 0, 2));
	std::shared_ptr<Camera> camera = cameraEnt->addComponent<Camera>();
	
	camera->CamIni(65);
	std::shared_ptr<Transform> transform = ent->addComponent<Transform>();
	transform->SetRotation(0.0f, 0.0f, 0.0f);
	transform->SetPos(glm::vec3(0, 0, 0));
	transform->SetScale(glm::vec3(0.5, 0.5, 0.5));

	std::shared_ptr<PBR> rend = ent->addComponent<PBR>();
	rend->PBRIni("../shaders/newShader.txt", "../models/pbrSphere.obj", "../models/AlbedoTexture.png", camera, "../models/AlbedoTexture.png","../models/MetalTexture.png", "../models/RoughnessTexture.png", "../models/AoTexture.png", "../models/NormalTexture.png");

	std::shared_ptr<Audio> sound = ent->addComponent<Audio>();
	sound->AudioInit("../sounds/0229.ogg");
//	sound->PlayAudio();

	app->Run();
	//std::cout << "game RUnning" << std::endl;
	
return 0;
}