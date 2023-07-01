#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "render/ARES.h"
#include "camera.h"

class Window
{
private:
	ARES ares;
	Camera camera;
	
	int X;
	int Y;

	double time;
	double delta_time;
	double last_frame_time;


	void update_time();
	void update_ratio();
public:
	Window(int x = 1080, int y = 720);
	void loop(void);
};

