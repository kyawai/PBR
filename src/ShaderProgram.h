#ifndef _SHADER_PROGRAM_
#define _SHADER_PROGRAM_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <glm/gtc/type_ptr.hpp>
class VertexArray;
class Texture;

struct Sampler
{
		GLint id;
		Texture *texture;
};
class ShaderProgram
{
private:
	GLuint id;
	std::vector<Sampler> samplers;
public:
	ShaderProgram();
	ShaderProgram(std::string vert, std::string frag);

	void draw(VertexArray *vertexArray);

	void SetUniform(std::string uniform, glm::mat4 value);
	void SetUniform(std::string uniform, float value);
	void SetUniform(std::string uniform, int value);
	void SetUniform(std::string uniform, glm::vec3 value);
	void setUniform(std::string uniform, Texture *texture);
	void setUniform(std::string uniform, glm::vec4 value);
	void printShaderInfoLog(GLuint obj);
	void printProgramInfoLog(GLuint obj);

	GLuint getId();
};



#endif