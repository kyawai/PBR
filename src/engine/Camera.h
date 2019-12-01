#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Component.h"
#include "Application.h"

class Camera : public Component
{
		glm::mat4 pos;
		glm::mat4 view;
		glm::mat4 projection;
		float angle;
		glm::vec3 camPos;

public:
		~Camera();
		void CamIni(float _angle);
		glm::mat4 getView();
		glm::vec3 getPos();
		glm::mat4 getProjection();


};

#endif

