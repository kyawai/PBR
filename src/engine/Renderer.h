#ifndef _RENDERER_H_
#define _RENDERER_H_


#include "Component.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <sr1/memory>
#include "Camera.h"
#include <rend/rend.h>


class Renderer : public Component
{
	GLuint programId;
	GLuint vaoId;
	std::sr1::shared_ptr<rend::Shader> shader;
	std::sr1::shared_ptr<rend::Mesh> mesh;
	std::sr1::shared_ptr < rend::Texture> texture;
	std::sr1::shared_ptr<Camera> camera;
	float angle = 0;
public:
	Renderer();
	~Renderer();
	void onDisplay();
	void RenderInitialise(char* _shader, char* _model, char* _texture, std::shared_ptr<Camera> _camera);
};

#endif