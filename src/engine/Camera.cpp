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
}

glm::mat4 Camera::getView()
{
		return view;
}

glm::mat4 Camera::getProjection()
{
		projection = glm::perspective(glm::radians(angle), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
		return projection;
}
