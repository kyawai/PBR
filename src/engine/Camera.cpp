#include "Camera.h"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 1020
Camera::~Camera()
{
}

void Camera::CamIni(float _angle)
{
		angle = _angle;
		pos = glm::mat4(1.0f);
		std::sr1::shared_ptr<Entity> ent = getEntity();
		std::sr1::shared_ptr<Transform> tranform = ent->getComponent<Transform>();
		camPos = tranform->getPos();
}

glm::mat4 Camera::getView()
{
		return view;
}

glm::vec3 Camera::getPos()
{
		return camPos;
}

glm::mat4 Camera::getProjection()
{
		projection = glm::perspective(glm::radians(angle), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
		return projection;
}
