#pragma once

#include <glad/glad.h>
#include <iostream>
#include <linmath/linmath.h>

class Shader
{
private:
    std::string vertex_shader_text;
    std::string fragment_shader_text;

    unsigned int ID;

   unsigned int CompileShader(unsigned int type, std::string& _src);
   unsigned int CreateShader();
   int GetUniformLocation(const std::string& name);

public:
    Shader();
    ~Shader();

    void bind();
    void unbind();

    void SetUniform_4f(const std::string& name, float v0, float v1, float v2, float v3);
    void SetUniform_mat4(const std::string& name, mat4x4 mvp);

};

