#include "WordGeneration.h"

#include <random>
#include <cmath>
#include <iostream>

#include <OpenSimplexNoise/OpenSimplexNoise.h>


void WordGeneration::generate_world_map(int64_t seed)
{
	OpenSimplexNoise::Noise noise(seed);

	map = new unsigned int* [world_size];
	for (int i = 0; i < world_size; i++)
	{
		map[i] = new unsigned int[world_size];
	}
	int a = 0;
	int b = 1;
	for (int i = 0; i < world_size; i++) {
		for (int j = 0; j < world_size; j++)
		{
			float n0 = a + (0.5 * (noise.eval((double)i / 128, (double)j / 128) + 1.0) * (b - a));
			float n1 = a + (0.5 * (noise.eval((double)i / 32, (double)j / 32) + 1.0) * (b - a));
			float n2 = a + (0.5 * (noise.eval((double)i / 16, (double)j / 16) + 1.0) * (b - a));
			n2 = (n0 * 5 + n1 * 2 + n2) / 8;
			float n = 15086 * pow(n2, 6) - 47171 * pow(n2, 5) + 54690 * pow(n2, 4) - 28547 * pow(n2, 3) + 6388.1 * pow(n2, 2) - 366.98 * n2 + 0.9851;
			if (n <= 27)
				n = 27;
			map[i][j] = 1 + n;
		}
	}
}

std::vector<chunk*> WordGeneration::get_render_input()
{
	return world;
}

void WordGeneration::AddChunk(chunk* _chunk)
{
    world.push_back(_chunk);
}

WordGeneration::WordGeneration()
{
	last_mid_chunk_x = 0;
	last_mid_chunk_z = 0;
	world_size = 2048;
	chunk_vision = 9;

	//generating the world map
	generate_world_map();

	int index = 0;
	for (int i = -chunk_vision / 2; i <= chunk_vision / 2; i++)
	{
		for (int j = -chunk_vision / 2; j <= chunk_vision / 2; j++)
		{
			chunk* pice = new chunk((float)(1024 + i * 16), (float)(0), (float)(1024 + j * 16));
			pice->set_blocks(map);
			AddChunk(pice);
			last_chunk_map[index][0] = i;
			last_chunk_map[index][1] = j;
			index++;
		}
	}
	//landscape* l = new landscape(1024 - 4 * 16, 0, 1024 - 4 * 16);
	//l->set_blocks(map);
	//world.push_back(l);
}

WordGeneration::~WordGeneration()
{
	for (chunk* c : world)
	{
		delete c;
	}
	world.clear();
}

bool WordGeneration::upgrade_chunks(float x, float y)
{
	int mid_x = (int)x / 16;
	int mid_z = (int)y / 16;
	int range_of_view = chunk_vision;
	bool c_flag = false;
	int index = 0;
		if (mid_x != last_mid_chunk_x || mid_z != last_mid_chunk_z) {
			last_mid_chunk_x = mid_x;
			last_mid_chunk_z = mid_z;
			for (int i = -range_of_view / 2; i <= range_of_view / 2; i++)
			{
				for (int j = -range_of_view / 2; j <= range_of_view / 2; j++)
				{
					if (mid_x + i < 0 || mid_z + j < 0) {
						break;
					}
						world[index]->set_position((float)(mid_x + i) * 16, 0.0f, (float)(mid_z + j) * 16);
						world[index]->set_blocks(map);
					index++;
				}
			}
			return true;
		}
	return false;
}
