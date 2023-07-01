#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class IndexBuffer
{
private:
	unsigned int ID;
	unsigned int Count;
public:
	IndexBuffer(const void* data, unsigned int count);
	~IndexBuffer();

	void prepare(const void* data, unsigned int count);
	void bind();
	void unbind();
	unsigned int GetCount() { return Count; };
};

