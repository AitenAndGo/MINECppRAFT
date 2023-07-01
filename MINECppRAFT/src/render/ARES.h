#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
//#include "IndexBuffer.h"
//#include "VertexBuffer.h"
#include "Shader.h"
#include "../Texture.h"
#include <vector>
#include "../WordGeneration.h"


class ARES
{
private:
	GLFWwindow* window;
	//Shader shader;
	//VertexBuffer vb;
	//IndexBuffer ib;
	std::vector<VertexArray*> voas;
public:
	//ARES();
	void prepare_voas();
	void InitWindow(unsigned int resx = 1080, unsigned int resy = 720);
	//void PrepareToDraw(std::vector<block*> elements);
	//void DrawElements(std::vector<block*> elements, Shader& s, Texture& t, mat4x4 cm);
	void PrepareToDraw(std::vector<chunk*> elements);
	void DrawElements(std::vector<chunk*> elements, Shader& s, Texture& t, mat4x4 cm);
	GLFWwindow* getwindow();
};

