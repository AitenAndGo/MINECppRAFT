#pragma once

#include <iostream>


class Texture
{
private:
	unsigned int ID;
	//one cube wall
public:
	Texture();
	~Texture();
	Texture& operator=(Texture& t);
	void bind();
	void unbind();

	unsigned int get_ID(void);
};

