#pragma once
#include <glad/glad.h>

class VertexArray
{
private:
	unsigned int ID;
public:
	VertexArray();
	void enable();
	void bind();
	void unbind();
};

