#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Component.h"
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

public:
		~Camera();
		void CamIni(float _angle);
		glm::mat4 getView();
		glm::mat4 getProjection();


};

#endif

