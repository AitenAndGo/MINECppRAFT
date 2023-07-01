#pragma once

#include <linmath/linmath.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Camera
{
private:
	vec3 position;
	vec3 up;
	vec3 dir;
	float pov;
	float ratio;
	float near;
	float far;

	mat4x4 mvp;

	vec2 last_pos;

	static void mouse_callback(GLFWwindow* window, double x, double y);

public:
	void set_dir(vec3 _dir);
	Camera(GLFWwindow* window = nullptr);
	void set_pointer(GLFWwindow* window);
	void set_ratio(float x, float y);
	void camera_control(double delta_time, GLFWwindow* window);
	inline vec3* get_dir(void) { return &dir; };
	inline float get_position_x(void) { return position[0]; };
	inline float get_position_y(void) { return position[1]; };
	inline float get_position_z(void) { return position[2]; };
	mat4x4* get_matrix(void);
};

