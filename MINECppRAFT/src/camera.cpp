#include "camera.h"

#include <iostream>

#define speed 5
#define sensitivity 1

void Camera::mouse_callback(GLFWwindow* window, double x, double y)
{
	Camera* camera = static_cast<Camera*>(glfwGetWindowUserPointer(window));

	vec3 _dir;
	int wx;
	int wy;
	glfwGetFramebufferSize(window, &wx, &wy);

	float xpos, ypos;

	xpos = (x + camera->last_pos[0]) / wx;
	ypos = (y + camera->last_pos[1]) / wy;

	if (ypos > 1.55)
		ypos = 1.55;
	else if (ypos < -1.55)
		ypos = -1.55;
	else
	{
		camera->last_pos[1] += y - (wy / 2);
	}
	camera->last_pos[0] += x - (wx / 2);

	_dir[0] = cos(xpos * sensitivity) * cos(ypos * sensitivity);
	_dir[1] = sin(-ypos * sensitivity);
	_dir[2] = sin(xpos * sensitivity) * cos(ypos * sensitivity);

	vec3_norm(camera->dir, _dir);

	glfwSetCursorPos(window, wx / 2, wy / 2);
}

Camera::Camera(GLFWwindow* window)
{
	glfwSetWindowUserPointer(window, this);
	glfwSetCursorPosCallback(window, Camera::mouse_callback);

	last_pos[0] = 0;
	last_pos[1] = 0;

	position[0] = 1024;
	position[1] = 32;
	position[2] = 1024;

	up[0] = 0;
	up[1] = 1;
	up[2] = 0;

	dir[0] = 0;
	dir[1] = 0;
	dir[2] = 1;

	pov = 1.57;
	ratio = 1080 / 720;
	near = 0.1;
	far = 128;

}

void Camera::set_pointer(GLFWwindow* window)
{
	glfwSetWindowUserPointer(window, this);
	glfwSetCursorPosCallback(window, Camera::mouse_callback);
}

void Camera::set_ratio(float x, float y)
{
	ratio = x / y;
}

void Camera::camera_control(double delta_time, GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		position[0] += speed * delta_time * dir[0];
		position[1] += speed * delta_time * dir[1];
		position[2] += speed * delta_time * dir[2];
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		position[0] -= speed * delta_time * dir[0];
		position[1] -= speed * delta_time * dir[1];
		position[2] -= speed * delta_time * dir[2];
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		vec3 cross;
		vec3_mul_cross(cross, dir, up);
		vec3_norm(cross, cross);
		position[0] -= speed * delta_time * cross[0]; 
		position[1] -= speed * delta_time * cross[1];
		position[2] -= speed * delta_time * cross[2];
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		vec3 cross;
		vec3_mul_cross(cross, dir, up);
		vec3_norm(cross, cross);
		position[0] += speed * delta_time * cross[0];
		position[1] += speed * delta_time * cross[1];
		position[2] += speed * delta_time * cross[2];
	}
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		position[1] += speed * delta_time;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		position[1] -= speed * delta_time;
	}
	//dir[0] += position[0];
	//dir[1] += position[1];
	//dir[2] += position[2];
}

mat4x4* Camera::get_matrix(void)
{
	mat4x4 m, p;
	mat4x4_identity(m);
	mat4x4_perspective(p, pov, ratio, near, far);
	vec3 _dir;
	vec3_add(_dir, position, dir);
	mat4x4_look_at(m, position, _dir, up);
	mat4x4_mul(mvp, p, m);
	return &mvp;
}
