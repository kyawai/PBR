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
		//std::sr1::shared_ptr<Entity> entity = getEntity();
		//std::sr1::shared_ptr<Transform> transform = entity->getComponent<Transform>();
		//camPos = transform->getPos();
}

glm::mat4 Camera::getView()
{
	//std::sr1::shared_ptr<Entity> entity = getEntity();
	//std::sr1::shared_ptr<Transform> transform = entity->getComponent<Transform>();
	//view = glm::inverse(transform->GetModel());
	return view;
}

//glm::vec3 Camera::getPos()
//{
//		return camPos;
//}

glm::mat4 Camera::getProjection()
{
		projection = glm::perspective(glm::radians(angle), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
		return projection;
}

//void Camera::AddRotCam(float _rotY, float _rotX, float _rotZ)
//{
//	rotY += _rotY;
//	rotX += _rotX;
//	rotZ += _rotZ;
//}
