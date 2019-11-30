#define STB_IMAGE_IMPLEMENTATION
#include <GL/glew.h>

#include "Renderer.h"
#include "Entity.h"

#include <exception>

#include <fstream>
#include "stb_image.h"


Renderer::Renderer()
{

}


void Renderer::onDisplay()
{
	angle += 0.5f;

	std::sr1::shared_ptr<Entity> ent = getEntity();

	//add transform


	glClearColor(0.10f, 0.15f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	shader->setUniform("u_Projection", camera->getProjection());

	shader->setUniform("u_Model", glm::rotate(glm::mat4(1.0f), glm::radians(10.0f), glm::vec3(1, 0, 0)) *
	glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0, 1, 0)) *
	glm::translate(glm::mat4(1.0f), glm::vec3(5, -2, 45)));

	shader->setMesh(mesh);
	shader->render();
}

void Renderer::RenderInitialise(char* _shader, char* _model, char* _texture, std::shared_ptr<Camera> _camera)
{
	std::sr1::shared_ptr<Application> app = getApp();
	shader = app->context->createShader();
	camera = _camera;
	{
		std::ifstream f(_shader);
		if (!f.is_open())
		{
			throw rend::Exception("cant open shader txt");
		}

		std::string shaderTxt;
		std::string pos;
		while (!f.eof())
		{
			std::getline(f, pos);
			shaderTxt += pos + "\n";
		}
		shader->parse(shaderTxt);
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

Renderer::~Renderer()
{
	
}