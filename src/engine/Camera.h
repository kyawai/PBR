#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Component.h"
#include "Application.h"
#include "Renderer.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/vec3.hpp>

class Camera : public Component
{
		glm::mat4 pos;
		glm::mat4 view;
		glm::mat4 projection;
		float angle;
	//	glm::vec3 camPos;
//		glm::vec3 camRot;
//		glm::mat4 model;
//		float rotY;
//		float rotX;
//		float rotZ;


public:
		~Camera();
		void CamIni(float _angle);
		glm::mat4 getView();
	//	glm::vec3 getPos();
		glm::mat4 getProjection();
	//	void AddRotCam(float _rotY, float _rotX, float _rotZ);


};

#endif

