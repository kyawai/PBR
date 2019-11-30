#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Component.h"
#include <glm/gtx/transform.hpp>

class Transform : public Component
{
		glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);;
		glm::vec3 scale = glm::vec3(1.0f,1.0f,1.0f);
		glm::mat4 model = glm::mat4(1.0f);
		float rotY = 0.0f;
		float rotX = 0.0f;
		float rotZ = 0.0f;

public:
		~Transform();

		glm::mat4 GetModel();

	  glm::vec3 getPos();
		void SetPos(glm::vec3 _pos);
		void AddPos(glm::vec3 _pos);

		float GetRotation();
		void SetRotation(float _rotY, float _rotX, float _rotZ);
		void AddRotation(float _rotY, float _rotX, float _rotZ);

		glm::vec3 getScale();
		void SetScale(glm::vec3 _scale);


};


#endif // ! _TRANSFORM_H_

