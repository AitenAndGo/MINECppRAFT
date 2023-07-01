#include "chunk.h"

#include <iostream>

#define BLOCK_SIZE 1
#define MAX_H 256
#define CHUNK_SIZE 16

block* chunk::get_block(unsigned int** map, int x, int z, int h)
{

	wall w1;
	w1.top = false;
	w1.bottom = false;
	w1.back_side = false;
	w1.front_side = false;
	w1.left_side = false;
	w1.right_side = false;

	bool f = false;

	unsigned int num = 0;
	if (h <= map[x][z] - 1) {
		if (h == map[x][z] - 1) {
			//visible_walls |= (1 << 0);
			w1.top = true;
			num++;
			f = true;
		}
		if (map[x - 1][z] <= h) {
			//visible_walls |= (1 << 4);
			w1.left_side = true;
			num++;
			f = true;
		}
		if (map[x + 1][z] <= h) {
			//visible_walls |= (1 << 5);
			w1.right_side = true;
			num++;
			f = true;
		}
		if (map[x][z - 1] <= h) {
			//visible_walls |= (1 << 2);
			w1.back_side = true;
			num++;
			f = true;
		}
		if (map[x][z + 1] <= h) {
			//visible_walls |= (1 << 3);
			w1.front_side = true;
			num++;
			f = true;
		}
		if (!f) {
			return nullptr;
		}
		wall_count += num;
		unsigned int type;
		if (h <= 27) {
			type = WATER;
		}
		else if (h <= 28)
		{
			type = SAND;
		}
		else if (h <= 64)
		{
			h + 1 < map[x][z] ? type = STONE : h == map[x][z] - 1 ? type = GRASS : type = DIRT;
		}
		else
		{
			h + 1 < map[x][z] ? type = STONE : h == map[x][z] - 1 ? type = SNOW : type = DIRT;
		}
		block* b1 = new block(type, 1.0f, x, h, z);
		b1->set_ind(w1, num);
		return b1;
	}
	else
		return nullptr;
}

void chunk::set_render_data()
{
	delete[] vertex;
	delete[] draw_indicies;
	vertex = new float[count * 144];
	draw_indicies = new unsigned int[wall_count * 6];
	int index = 0;
	int index2 = 0;
	for (size_t i = 0; i < count; i++){
		memcpy(&vertex[index], blocks[i]->get_ver(), sizeof(float) * 144);
		index += 144;
		for (size_t j = 0; j < blocks[i]->get_count(); j++)
		{
			draw_indicies[index2] = blocks[i]->get_ind()[j] + (i * 24);
			index2++;
		}
		delete blocks[i];
	}
	blocks.clear();
}

chunk::chunk(float x, float y, float z)
{
	position[0] = x;
	position[1] = y;
	position[2] = z;
	count = 0;
	wall_count = 0;
	id_count = 0;
}

chunk::~chunk()
{
	for (block* b : blocks) {
		delete b;
	}
	delete[] vertex;
	delete[] draw_indicies;
}

void chunk::set_blocks(unsigned int** map)
{
	count = 0;
	wall_count = 0;
	id_count = 0;
	for (block* b : blocks) {
		delete b;
	}
	blocks.clear();
	for (size_t i = 0; i < CHUNK_SIZE; i++){
		for (size_t j = 0; j < CHUNK_SIZE; j++) {
			for (int h = 0; h <= map[(int)position[0] + i][(int)position[2] + j]; h++){

				int x = position[0] + i;
				int z = position[2] + j;

				block* b = get_block(map, x, z, h);

				if (b != nullptr) {
					blocks.push_back(b);
					count++;
				}
			}
		}
	}
	set_render_data();
}

std::vector<block*>* chunk::get_blocks(void)
{
	return &blocks;
}
