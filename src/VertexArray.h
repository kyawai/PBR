
#ifndef _VERTEX_ARRAY_
#define _VERTEX_ARRAY_


#include <GL/glew.h>
#include <vector>

class VertexBuffer;

class VertexArray
{
private:
	GLuint id;
	std::vector<VertexBuffer*> buffers;
	bool dirty;

	void splitStringWhitespace(std::string& input, std::vector<std::string>& output);
	void splitString(std::string& input, char splitter, std::vector<std::string>& output);


public:
	VertexArray();

	VertexArray(std::string path);

	void SetBuffer(std::string attribute, VertexBuffer* buffer);

	int GetVertexCount();
	GLuint GetId();
};





#endif