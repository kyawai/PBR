#define STB_IMAGE_IMPLEMENTATION
#include "PBR.h"
#include <GL/glew.h>
#include <fstream>
#include "Entity.h"
#include "glm/ext.hpp"
#include "glm/gtx/string_cast.hpp"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 1020


class Camera;


PBR::PBR()
{
	
	
	lightPos[0] = glm::vec3(0.0f, 0.0f, 1.0f);
	lightPos[1] = glm::vec3(10.0f, 10.0f, 10.0f);
	lightPos[2] = glm::vec3(-10.0f, -10.0f, 10.0f);
	lightPos[3] = glm::vec3(10.0f, -10.0f, 10.0f);
	

	
	
	lightColours[0] = glm::vec3(300.0f, 300.0f, 300.0f);
	lightColours[1] = glm::vec3(0.0f, 0.0f, 0.0f);
	lightColours[2] = glm::vec3(0.0f,0.0f, 0.0f);
	lightColours[3] = glm::vec3(0.0f, 0.0f, 0.0f);
	

}

PBR::~PBR()
{
}

void PBR::onDisplay()
{
		std::sr1::shared_ptr<Entity> ent = getEntity();
		std::sr1::shared_ptr<Transform> trans = ent->getComponent<Transform>();
		std::sr1::shared_ptr<Application> app = getApp();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader->setUniform("u_Projection", camera->getProjection());
		shader->setUniform("view", camera->getView());
		shader->setUniform("camPos", camera->getPos());
		//


		for (unsigned int i = 0; i < sizeof(lightPos) / sizeof(lightPos[0]); i++)
		{
				glm::vec3 newPos = lightPos[i] + glm::vec3(sin(app->deltaTime*5.0)*5.0, 0.0, 0.0);
				shader->setUniform("lightPos[" + std::to_string(i) + "]", curLightPos);
				shader->setUniform("lightColours[" + std::to_string(i) + "]", lightColours[i]);
		}
		shader->setUniform("u_Model", trans->GetModel());

		std::cout << " light pos: " << glm::to_string(curLightPos)<< std::endl;
		shader->setMesh(mesh);
		shader->render();
	


}

glm::vec3 PBR::getPosition()
{
	return curLightPos;
}

void PBR::SetPosition(glm::vec3 _lightPosition)
{
	curLightPos += _lightPosition;
}

std::sr1::shared_ptr < rend::Texture> PBR::MakeTexture(const char * _filepath)
{
	std::sr1::shared_ptr<Application> app = getApp();
	texture = app->context->createTexture();
	{
		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char* data = stbi_load(_filepath, &w, &h, &bpp, 3);
		if (!data)
		{
			throw rend::Exception("cant load texture");
		}
		texture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int size = y * w * 3 + x * 3;

				texture->setPixel(x, y, glm::vec3(data[size] / 255.0f, data[size + 1] / 255.0f, data[size + 2] / 255.0f));

			}
		}
		stbi_image_free(data);
	}
	return texture;
}



void PBR::PBRIni(char * _shader, char * _model, char * _texture, std::shared_ptr<Camera> _camera, char* _albedo, char* _metallic, char* _roughness, char* _ao, char* _normal)
{

		albedoT = MakeTexture(_albedo);
		metallicT = MakeTexture(_metallic);
		roughnessT = MakeTexture(_roughness);
		aoT = MakeTexture(_ao);
		normalT = MakeTexture(_normal);
		camera = _camera;


		std::sr1::shared_ptr<Application> app = getApp();
		shader = app->context->createShader();
		{
				std::ifstream f(_shader);
				if (!f.is_open())
				{
						throw rend::Exception("cant open shader for PBR");
				}
				std::string shaderPBRTxt;
				std::string pos;
				while (!f.eof())
				{
						std::getline(f, pos);
						shaderPBRTxt += pos + "\n";
				}
				shader->parse(shaderPBRTxt);
		}
		mesh = app->context->createMesh();
		{
				std::ifstream f(_model);
				if (!f.is_open())
				{
						throw rend::Exception("cant open model txt");
				}

				std::string modelTxt;
				std::string pos;
				while (!f.eof())
				{
						std::getline(f, pos);
						modelTxt += pos + "\n";
				}
				mesh->parse(modelTxt);
		}
		mesh->setTexture("albedoMap", albedoT);
		mesh->setTexture("metallicMap", metallicT);
		mesh->setTexture("roughnessMap", roughnessT);
		mesh->setTexture("aoMap", aoT);
		mesh->setTexture("normalMap", normalT);

}
