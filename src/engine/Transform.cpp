#include "Transform.h"

Transform::~Transform()
{
}

glm::mat4 Transform::GetModel()
{
		model = glm::scale(model, scale);
		model = glm::rotate(glm::mat4(1.0f), glm::radians(rotX), glm::vec3(1.0f, 0.0f, 0.0f))
				* glm::rotate(glm::mat4(1.0f), glm::radians(rotY), glm::vec3(0.0f, 1.0f, 0.0f))
				* glm::rotate(glm::mat4(1.0f), glm::radians(rotZ), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::translate(model, pos);
		return model;
}

glm::vec3 Transform::getPos()
{
		return glm::vec3();
}

void Transform::SetPos(glm::vec3 _pos)
{
		pos = _pos;
}

void Transform::AddPos(glm::vec3 _pos)
{
		pos += _pos;
}

float Transform::GetRotation()
{
		return rotY;
}

void Transform::SetRotation(float _rotY, float _rotX, float _rotZ)
{
		rotY = _rotY;
		rotX = _rotX;
		rotZ = _rotZ;
}

void Transform::AddRotation(float _rotY, float _rotX, float _rotZ)
{
		rotY += _rotY;
		rotX += _rotX;
		rotZ += _rotZ;
}

glm::vec3 Transform::getScale()
{
		return scale;
}

void Transform::SetScale(glm::vec3 _scale)
{
		scale = _scale;
}
