#include "Shader.h"
#include <iostream>

Shader::Shader()
{
	vertex_shader_text =
		"#version 330 core\n"
		"in vec4 position;\n"
		"in vec2 vTex;\n"
		"in float aColor;\n"
		//"float aColor = 1;\n"
		//"in double position;\n"
		"uniform mat4 MVP;\n"
		"out vec2 texpos;\n"
		"out float vColor;\n"
		"void main()\n"
		"{\n"
	/*	"	unsigned int position_x = 0;\n"
		"	position_x |= (position >> 48);\n"
		"	position &= 0xFFFF000000000000;\n"
		"	unsigned int position_y = 0;\n"
		"	position_y |= (position >> 32);\n"
		"	position &= 0xFFFFFFFF00000000;\n"
		"	unsigned int position_x = 0;\n"
		"	position_z |= (position >> 16);\n"
		"	position &= 0xFFFFFFFFFFFF0000;\n"
		"	vec2 vTex;\n"
		"	unsigned int u = 0;\n"
		"	u |= (position << 8);\n"
		"	position &= 0xFFFFFFFFFFFFFF00;\n"
		"	unsigned int v = 0;\n"
		"	v |= position;\n"
		"	position &= 0xFFFFFFFFFFFFFFFF;\n"
		"	vTex = vex2(u * 0.0625, v * 0.0625)\n"*/
		"	gl_Position = MVP * position;\n"
		//"	gl_Position = MVP * vec4(position_x, position_y, position_z, 1.0);\n"
		"   texpos = vTex;\n"
		"	vColor = aColor;\n"
		"}\n";

	fragment_shader_text = 
		"#version 330 core\n"
		"in vec2 texpos;\n"
		"in float vColor;\n"
		"uniform sampler2D ourTexture;\n"
		"uniform vec4 u_Color;\n"
		//"out vec4 color;\n"
		"out vec4 fragment;\n"
		"void main()\n"
		"{\n"
		//"	color = u_Color;\n"
		"   vec4 texColor = texture(ourTexture, texpos);\n"
		"   fragment = vec4(texColor.rgb * vColor, texColor.a);\n"
		"}\n";

	ID = CreateShader();
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

unsigned int Shader::CompileShader(unsigned int type, std::string& _src)
{
	unsigned int id = glCreateShader(type);
	const char* src = _src.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE) {
		int lenght;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);
		char* message = (char*)alloca(lenght * sizeof(char));
		glGetShaderInfoLog(id, lenght, &lenght, message);
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}


	return id;
}


void Shader::bind()
{
	glUseProgram(ID);
}

void Shader::unbind()
{
	glUseProgram(0);
}

unsigned int Shader::CreateShader()
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex_shader_text);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment_shader_text);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

void Shader::SetUniform_4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	glUniform4f(GetUniformLocation(name), v0, v1, v2, v3);
}

void Shader::SetUniform_mat4(const std::string& name, mat4x4 mvp) {
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, (const GLfloat*) mvp);
}
 
int Shader::GetUniformLocation(const std::string& name) {
	int location = glGetUniformLocation(ID, name.c_str());
	if (location == -1)
		std::cout << "Failed" << std::endl;
	return location;
}


