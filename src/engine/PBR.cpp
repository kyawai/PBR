#define STB_IMAGE_IMPLEMENTATION
#include "PBR.h"
#include <GL/glew.h>
#include <fstream>
#include "Entity.h"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 1020


class Camera;

glm::vec3 lightPos[] =
{
		glm::vec3(-10.0f,  10.0f, 10.0f),
		glm::vec3(10.0f,  10.0f, 10.0f),
		glm::vec3(-10.0f, -10.0f, 10.0f),
		glm::vec3(10.0f, -10.0f, 10.0f),
};

glm::vec3 lightColours[] =
{
				glm::vec3(300.0f, 300.0f, 300.0f),
				glm::vec3(300.0f, 300.0f, 300.0f),
				glm::vec3(300.0f, 300.0f, 300.0f),
				glm::vec3(300.0f, 300.0f, 300.0f)
};
PBR::PBR()
{
}

PBR::~PBR()
{
}

void PBR::onDisplay()
{
		std::sr1::shared_ptr<Entity> ent = getEntity();
		std::sr1::shared_ptr<Transform> trans = ent->getComponent<Transform>();
		std::sr1::shared_ptr<Application> app = getApp();

		glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader->setUniform("roughness", roughness);
		shader->setUniform("u_Projection", camera->getProjection());
		shader->setUniform("view", camera->getView());
		shader->setUniform("u_Model", trans->GetModel());
		shader->setUniform("albedo", albedo);
		shader->setUniform("metallic", metallic);
		shader->setUniform("camPos", camera->getPos());
		shader->setUniform("ao", ao);

		for (unsigned int i = 0; i < sizeof(lightPos) / sizeof(lightPos[0]); i++)
		{
				glm::vec3 newPos = lightPos[i] + glm::vec3(sin(app->deltaTime*5.0)*5.0, 0.0, 0.0);
				newPos = lightPos[i];
				shader->setUniform("lightPos[" + std::to_string(i) + "]", lightPos[i]);
				shader->setUniform("lightColours[" + std::to_string(i) + "]", lightColours[i]);
		}

		shader->setMesh(mesh);
		shader->render();
	


}

void PBR::PBRIni(char * _shader, char * _model, char * _texture, std::shared_ptr<Camera> _camera, glm::vec3 _albedo, float _metallic, float _roughness, float _ao)
{
		metallic = _metallic;
		albedo = _albedo;
		roughness = _roughness;
		ao = _ao;
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
		texture = app->context->createTexture();
		{
				int w = 0;
				int h = 0;
				int bpp = 0;

				unsigned char* data = stbi_load(_texture, &w, &h, &bpp, 3);
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
				mesh->setTexture("u_Texture", texture);
		}
}
