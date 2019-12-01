#ifndef _PBR_H_
#define _PBR_H_
#include "Application.h"

#include <stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

class PBR : public Component
{

		SDL_Window* window;
		GLuint programId;
		GLuint vaoId;
		std::sr1::shared_ptr<rend::Shader> shader;
		std::sr1::shared_ptr<rend::Mesh> mesh;
		std::sr1::shared_ptr < rend::Texture> texture;
		std::sr1::shared_ptr<Camera> camera;


		glm::vec3 albedo;
		float metallic;
		float roughness;
		float ao;
		glm::vec3 camPos;
		glm::vec3 lightPos[4];
		glm::vec3 lightColour[4];



public:
		PBR();
		~PBR();
		void PBRIni(char* _shader, char* _model, char* _texture, std::shared_ptr<Camera> _camera, glm::vec3 _albedo, float _metallic, float _roughness, float _ao);
		void onDisplay();


		 
};



#endif