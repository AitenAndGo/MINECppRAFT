#pragma once

#include "../textures/Catalog.h"

#include "render/VertexArray.h"
#include "render/IndexBuffer.h"
#include "render/VertexBuffer.h"

typedef struct {
	bool top;
	bool front_side;
	bool left_side;
	bool right_side;
	bool back_side;
	bool bottom;
} wall;


class block
{
private:
	float block_size;
	float position[3];
	float indicies[8][3];
	unsigned int* draw_indicies;
	float* vertex;
	unsigned int texture_type;

	unsigned int count;
	unsigned int size;
public:
	//VertexArray* voa;
	//VertexBuffer* vb;
	//IndexBuffer* ib;
	block(const block& w) = delete;
	block(const unsigned int tex_name = 0, float _size = 1, float x = 0, float y = 0, float z = 0);
	~block();
	float* get_ver(void);
	unsigned int* get_ind(void);
	void set_ind(wall visible_walls, unsigned int num);
	unsigned int get_size();

	void set_ver(float* _ver, int v);
	void set_ind_all(unsigned int* _ind, int v);

	inline unsigned int get_count() { return count; };
	inline float* get_position(void) { return position; };
};