
#include "block.h"
#include <iostream>


block::block(const unsigned int tex, float _size, float x, float y, float z)
{
	count = 0;

	texture_type = tex;
	
	vertex = nullptr;
	vertex = new float[24 * 6];

	block_size = _size;

	position[0] = x;
	position[1] = y;
	position[2] = z;

	indicies[0][0] = position[0] - (0.5 * block_size);
	indicies[0][1] = position[1] - (0.5 * block_size);
	indicies[0][2] = position[2] - (0.5 * block_size);

	indicies[1][0] = position[0] + (0.5 * block_size);
	indicies[1][1] = position[1] - (0.5 * block_size);
	indicies[1][2] = position[2] - (0.5 * block_size);

	indicies[2][0] = position[0] + (0.5 * block_size);
	indicies[2][1] = position[1] + (0.5 * block_size);
	indicies[2][2] = position[2] - (0.5 * block_size);

	indicies[3][0] = position[0] - (0.5 * block_size);
	indicies[3][1] = position[1] + (0.5 * block_size);
	indicies[3][2] = position[2] - (0.5 * block_size);

	indicies[4][0] = position[0] - (0.5 * block_size);
	indicies[4][1] = position[1] - (0.5 * block_size);
	indicies[4][2] = position[2] + (0.5 * block_size);

	indicies[5][0] = position[0] + (0.5 * block_size);
	indicies[5][1] = position[1] - (0.5 * block_size);
	indicies[5][2] = position[2] + (0.5 * block_size);

	indicies[6][0] = position[0] + (0.5 * block_size);
	indicies[6][1] = position[1] + (0.5 * block_size);
	indicies[6][2] = position[2] + (0.5 * block_size);

	indicies[7][0] = position[0] - (0.5 * block_size);
	indicies[7][1] = position[1] + (0.5 * block_size);
	indicies[7][2] = position[2] + (0.5 * block_size);

	float b1 = 0.98;
	float b2 = 0.85;
	float b3 = 0.65;

	//uint64_t result1 = 0;
	//result1 |= static_cast<uint16_t>(indicies[0][0]) << 48;
	//result1 |= static_cast<uint16_t>(indicies[0][1]) << 32;
	//result1 |= static_cast<uint16_t>(indicies[0][2]) << 16;
	//result1 |= static_cast<uint8_t>(catalog[texture_type][1].u) << 8;
	//result1 |= static_cast<uint8_t>(catalog[texture_type][1].v);
	////result1 |= static_cast<uint8_t>(b2);

	//uint64_t result2 = 0;
	//result2 |= static_cast<uint16_t>(indicies[1][0]) << 48;
	//result2 |= static_cast<uint16_t>(indicies[1][1]) << 32;
	//result2 |= static_cast<uint16_t>(indicies[1][2]) << 16;
	//result2 |= static_cast<uint8_t>(catalog[texture_type][0].u) << 8;
	//result2 |= static_cast<uint8_t>(catalog[texture_type][0].v);
	////result2 |= static_cast<uint64_t>(b2);

	//uint64_t result3 = 0;
	//result3 |= static_cast<uint16_t>(indicies[2][0]) << 48;
	//result3 |= static_cast<uint16_t>(indicies[2][1]) << 32;
	//result3 |= static_cast<uint16_t>(indicies[2][2]) << 16;
	//result3 |= static_cast<uint8_t>(catalog[texture_type][3].u) << 8;
	//result3 |= static_cast<uint8_t>(catalog[texture_type][3].v);
	////result3 |= static_cast<uint64_t>(b2);

	//uint64_t result4 = 0;
	//result4 |= static_cast<uint16_t>(indicies[3][0]) << 48;
	//result4 |= static_cast<uint16_t>(indicies[3][1]) << 32;
	//result4 |= static_cast<uint16_t>(indicies[3][2]) << 16;
	//result4 |= static_cast<uint8_t>(catalog[texture_type][2].u) << 8;
	//result4 |= static_cast<uint8_t>(catalog[texture_type][2].v);
	////result4 |= static_cast<uint64_t>(b2);

	//uint64_t result5 = 0;
	//result5 |= static_cast<uint16_t>(indicies[4][0]) << 48;
	//result5 |= static_cast<uint16_t>(indicies[4][1]) << 32;
	//result5 |= static_cast<uint16_t>(indicies[4][2]) << 16;
	//result5 |= static_cast<uint16_t>(catalog[texture_type][0].u) << 8;
	//result5 |= static_cast<uint8_t>(catalog[texture_type][0].v) << 4;
	//result5 |= static_cast<uint8_t>(b2);

	//uint64_t result6 = 0;
	//result6 |= static_cast<uint16_t>(indicies[5][0]) << 48;
	//result6 |= static_cast<uint16_t>(indicies[5][1]) << 32;
	//result6 |= static_cast<uint16_t>(indicies[5][2]) << 16;
	//result6 |= static_cast<uint8_t>(catalog[texture_type][1].u) << 8;
	//result6 |= static_cast<uint8_t>(catalog[texture_type][1].v);
	////result6 |= static_cast<uint64_t>(b2);

	//uint64_t result7 = 0;
	//result7 |= static_cast<uint16_t>(indicies[6][0]) << 48;
	//result7 |= static_cast<uint16_t>(indicies[6][1]) << 32;
	//result7 |= static_cast<uint16_t>(indicies[6][2]) << 16;
	//result7 |= static_cast<uint8_t>(catalog[texture_type][2].u) << 8;
	//result7 |= static_cast<uint8_t>(catalog[texture_type][2].v);
	////result7 |= static_cast<uint64_t>(b2);

	//uint64_t result8 = 0;
	//result8 |= static_cast<uint16_t>(indicies[7][0]) << 48;
	//result8 |= static_cast<uint16_t>(indicies[7][1]) << 32;
	//result8 |= static_cast<uint16_t>(indicies[7][2]) << 16;
	//result8 |= static_cast<uint8_t>(catalog[texture_type][3].u) << 8;
	//result8 |= static_cast<uint8_t>(catalog[texture_type][3].v);
	////result8 |= static_cast<uint64_t>(b2);

	//uint64_t result9 = 0;
	//result9 |= static_cast<uint16_t>(indicies[0][0]) << 48;
	//result9 |= static_cast<uint16_t>(indicies[0][1]) << 32;
	//result9 |= static_cast<uint16_t>(indicies[0][2]) << 16;
	//result9 |= static_cast<uint8_t>(catalog[texture_type][0].u) << 8;
	//result9 |= static_cast<uint8_t>(catalog[texture_type][0].v);
	////result9 |= static_cast<uint64_t>(b3);

	//uint64_t result10 = 0;
	//result10 |= static_cast<uint16_t>(indicies[3][0]) << 48;
	//result10 |= static_cast<uint16_t>(indicies[3][1]) << 32;
	//result10 |= static_cast<uint16_t>(indicies[3][2]) << 16;
	//result10 |= static_cast<uint8_t>(catalog[texture_type][3].u) << 8;
	//result10 |= static_cast<uint8_t>(catalog[texture_type][3].v);
	////result10 |= static_cast<uint64_t>(b3);

	//uint64_t result11 = 0;
	//result11 |= static_cast<uint16_t>(indicies[7][0]) << 48;
	//result11 |= static_cast<uint16_t>(indicies[7][1]) << 32;
	//result11 |= static_cast<uint16_t>(indicies[7][2]) << 16;
	//result11 |= static_cast<uint8_t>(catalog[texture_type][2].u) << 8;
	//result11 |= static_cast<uint8_t>(catalog[texture_type][2].v);
	////result11 |= static_cast<uint64_t>(b3);

	//uint64_t result12 = 0;
	//result12 |= static_cast<uint16_t>(indicies[4][0]) << 48;
	//result12 |= static_cast<uint16_t>(indicies[4][1]) << 32;
	//result12 |= static_cast<uint16_t>(indicies[4][2]) << 16;
	//result12 |= static_cast<uint8_t>(catalog[texture_type][1].u) << 8;
	//result12 |= static_cast<uint8_t>(catalog[texture_type][1].v);
	////result12 |= static_cast<uint64_t>(b3);

	//uint64_t result13 = 0;
	//result10 |= static_cast<uint16_t>(indicies[1][0]) << 48;
	//result10 |= static_cast<uint16_t>(indicies[1][1]) << 32;
	//result10 |= static_cast<uint16_t>(indicies[1][2]) << 16;
	//result10 |= static_cast<uint8_t>(catalog[texture_type][1].u) << 8;
	//result10 |= static_cast<uint8_t>(catalog[texture_type][1].v);
	////result10 |= static_cast<uint64_t>(b3);

	//uint64_t result14 = 0;
	//result14 |= static_cast<uint16_t>(indicies[2][0]) << 48;
	//result14 |= static_cast<uint16_t>(indicies[2][1]) << 32;
	//result14 |= static_cast<uint16_t>(indicies[2][2]) << 16;
	//result14 |= static_cast<uint8_t>(catalog[texture_type][2].u) << 8;
	//result14 |= static_cast<uint8_t>(catalog[texture_type][2].v);
	////result14 |= static_cast<uint64_t>(b3);

	//uint64_t result15 = 0;
	//result15 |= static_cast<uint16_t>(indicies[6][0]) << 48;
	//result15 |= static_cast<uint16_t>(indicies[6][1]) << 32;
	//result15 |= static_cast<uint16_t>(indicies[6][2]) << 16;
	//result15 |= static_cast<uint8_t>(catalog[texture_type][3].u) << 8;
	//result15 |= static_cast<uint8_t>(catalog[texture_type][3].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result16 = 0;
	//result16 |= static_cast<uint16_t>(indicies[5][0]) << 48;
	//result16 |= static_cast<uint16_t>(indicies[5][1]) << 32;
	//result16 |= static_cast<uint16_t>(indicies[5][2]) << 16;
	//result16 |= static_cast<uint8_t>(catalog[texture_type][0].u) << 8;
	//result16 |= static_cast<uint8_t>(catalog[texture_type][0].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result17 = 0;
	//result17 |= static_cast<uint16_t>(indicies[2][0]) << 48;
	//result17 |= static_cast<uint16_t>(indicies[2][1]) << 32;
	//result17 |= static_cast<uint16_t>(indicies[2][2]) << 16;
	//result17 |= static_cast<uint8_t>(catalog[texture_type + 1][2].u) << 8;
	//result17 |= static_cast<uint8_t>(catalog[texture_type + 1][2].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result18 = 0;
	//result18 |= static_cast<uint16_t>(indicies[3][0]) << 48;
	//result18 |= static_cast<uint16_t>(indicies[3][1]) << 32;
	//result18 |= static_cast<uint16_t>(indicies[3][2]) << 16;
	//result18 |= static_cast<uint8_t>(catalog[texture_type + 1][3].u) << 8;
	//result18 |= static_cast<uint8_t>(catalog[texture_type + 1][3].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result19 = 0;
	//result19 |= static_cast<uint16_t>(indicies[7][0]) << 48;
	//result19 |= static_cast<uint16_t>(indicies[7][1]) << 32;
	//result19 |= static_cast<uint16_t>(indicies[7][2]) << 16;
	//result19 |= static_cast<uint8_t>(catalog[texture_type + 1][0].u) << 8;
	//result19 |= static_cast<uint8_t>(catalog[texture_type + 1][0].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result20 = 0;
	//result20 |= static_cast<uint16_t>(indicies[6][0]) << 48;
	//result20 |= static_cast<uint16_t>(indicies[6][1]) << 32;
	//result20 |= static_cast<uint16_t>(indicies[6][2]) << 16;
	//result20 |= static_cast<uint8_t>(catalog[texture_type + 1][1].u) << 8;
	//result20 |= static_cast<uint8_t>(catalog[texture_type + 1][1].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result21 = 0;
	//result21 |= static_cast<uint16_t>(indicies[0][0]) << 48;
	//result21 |= static_cast<uint16_t>(indicies[0][1]) << 32;
	//result21 |= static_cast<uint16_t>(indicies[0][2]) << 16;
	//result21 |= static_cast<uint8_t>(catalog[texture_type + 2][1].u) << 8;
	//result21 |= static_cast<uint8_t>(catalog[texture_type + 2][1].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result22 = 0;
	//result22 |= static_cast<uint16_t>(indicies[1][0]) << 48;
	//result22 |= static_cast<uint16_t>(indicies[1][1]) << 32;
	//result22 |= static_cast<uint16_t>(indicies[1][2]) << 16;
	//result22 |= static_cast<uint8_t>(catalog[texture_type + 2][0].u) << 8;
	//result22 |= static_cast<uint8_t>(catalog[texture_type + 2][0].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result23 = 0;
	//result23 |= static_cast<uint16_t>(indicies[5][0]) << 48;
	//result23 |= static_cast<uint16_t>(indicies[5][1]) << 32;
	//result23 |= static_cast<uint16_t>(indicies[5][2]) << 16;
	//result23 |= static_cast<uint8_t>(catalog[texture_type + 2][3].u) << 8;
	//result23 |= static_cast<uint8_t>(catalog[texture_type + 2][3].v);
	////result15 |= static_cast<uint64_t>(b3);

	//uint64_t result24 = 0;
	//result24 |= static_cast<uint16_t>(indicies[4][0]) << 48;
	//result24 |= static_cast<uint16_t>(indicies[4][1]) << 32;
	//result24 |= static_cast<uint16_t>(indicies[4][2]) << 16;
	//result24 |= static_cast<uint8_t>(catalog[texture_type + 2][2].u) << 8;
	//result24 |= static_cast<uint8_t>(catalog[texture_type + 2][2].v);
	////result15 |= static_cast<uint64_t>(b3);

	float _vertex[] = {
	//	////one cube wall
	//	////side WALL
		indicies[0][0], indicies[0][1], indicies[0][2],		 catalog[texture_type][1].u, catalog[texture_type][1].v,	b2, 
		indicies[1][0], indicies[1][1], indicies[1][2],		 catalog[texture_type][0].u, catalog[texture_type][0].v,	b2,
		indicies[2][0], indicies[2][1], indicies[2][2],		 catalog[texture_type][3].u, catalog[texture_type][3].v,	b2,
		indicies[3][0], indicies[3][1], indicies[3][2],		 catalog[texture_type][2].u, catalog[texture_type][2].v,	b2,
		
	//	////one cube wall
	//	////side WALL
		indicies[4][0], indicies[4][1], indicies[4][2],		 catalog[texture_type][0].u, catalog[texture_type][0].v,	b2,
		indicies[5][0], indicies[5][1], indicies[5][2],		 catalog[texture_type][1].u, catalog[texture_type][1].v,	b2,
		indicies[6][0], indicies[6][1], indicies[6][2],		 catalog[texture_type][2].u, catalog[texture_type][2].v,	b2,
		indicies[7][0], indicies[7][1], indicies[7][2],		 catalog[texture_type][3].u, catalog[texture_type][3].v,	b2,
	//	////
	//	//////one cube wall
	//	////side WALL
		indicies[0][0], indicies[0][1], indicies[0][2],		 catalog[texture_type][0].u, catalog[texture_type][0].v,	b3,
		indicies[3][0], indicies[3][1], indicies[3][2],		 catalog[texture_type][3].u, catalog[texture_type][3].v,	b3,
		indicies[7][0], indicies[7][1], indicies[7][2],		 catalog[texture_type][2].u, catalog[texture_type][2].v,	b3,
		indicies[4][0], indicies[4][1], indicies[4][2],		 catalog[texture_type][1].u, catalog[texture_type][1].v,	b3,
		////
		//one cube wall
		//side WALL
		indicies[1][0], indicies[1][1], indicies[1][2],		 catalog[texture_type][1].u, catalog[texture_type][1].v,	b3,
		indicies[2][0], indicies[2][1], indicies[2][2],		 catalog[texture_type][2].u, catalog[texture_type][2].v,	b3,
		indicies[6][0], indicies[6][1], indicies[6][2],		 catalog[texture_type][3].u, catalog[texture_type][3].v,	b3,
		indicies[5][0], indicies[5][1], indicies[5][2],		 catalog[texture_type][0].u, catalog[texture_type][0].v,	b3,
		//one cube wall
		//up
		indicies[2][0], indicies[2][1], indicies[2][2],		 catalog[texture_type + 1][2].u, catalog[texture_type + 1][2].v,	b1,
		indicies[3][0], indicies[3][1], indicies[3][2],		 catalog[texture_type + 1][3].u, catalog[texture_type + 1][3].v,	b1,
		indicies[7][0], indicies[7][1], indicies[7][2],		 catalog[texture_type + 1][0].u, catalog[texture_type + 1][0].v,	b1,
		indicies[6][0], indicies[6][1], indicies[6][2],		 catalog[texture_type + 1][1].u, catalog[texture_type + 1][1].v,	b1,
		
		//one cube wall
		//bottom
		indicies[0][0], indicies[0][1], indicies[0][2],		 catalog[texture_type + 2][1].u, catalog[texture_type + 2][1].v,	b1,
		indicies[1][0], indicies[1][1], indicies[1][2],		 catalog[texture_type + 2][0].u, catalog[texture_type + 2][0].v,	b1,
		indicies[5][0], indicies[5][1], indicies[5][2],		 catalog[texture_type + 2][3].u, catalog[texture_type + 2][3].v,	b1,
		indicies[4][0], indicies[4][1], indicies[4][2],		 catalog[texture_type + 2][2].u, catalog[texture_type + 2][2].v,	b1,
		

	};
	
	for (int i = 0; i < 24 * (3 + 2 + 1); i++) {
		vertex[i] = _vertex[i];

	}
	//vertex[0] = result1;
	//vertex[1] = result2;
	//vertex[2] = result3;
	//vertex[3] = result4;
	//vertex[4] = result5;
	//vertex[5] = result6;
	//vertex[6] = result7;
	//vertex[7] = result8;
	//vertex[8] = result9;
	//vertex[9] = result10;
	//vertex[10] = result11;
	//vertex[11] = result12;
	//vertex[12] = result13;
	//vertex[13] = result14;
	//vertex[14] = result15;
	//vertex[15] = result16;
	//vertex[16] = result17;
	//vertex[17] = result18;
	//vertex[18] = result19;
	//vertex[19] = result20;
	//vertex[20] = result21;
	//vertex[21] = result22;
	//vertex[22] = result23;
	//vertex[23] = result24;

	size = sizeof(float) * 6 * 4 * 6;
}

float* block::get_ver(void) {
	return vertex;
}

unsigned int* block::get_ind(void) {
	return draw_indicies;
}

void block::set_ind(wall visible_walls, unsigned int num)
{
	draw_indicies = nullptr;
	draw_indicies = new unsigned int[num * 6];
	if (visible_walls.back_side) {
		draw_indicies[count] = 0; count++;
		draw_indicies[count] = 1; count++;
		draw_indicies[count] = 2; count++;

		draw_indicies[count] = 2; count++;
		draw_indicies[count] = 3; count++;
		draw_indicies[count] = 0; count++;
	}
	if (visible_walls.front_side) {
		draw_indicies[count] = 4; count++;
		draw_indicies[count] = 5; count++;
		draw_indicies[count] = 6; count++;

		draw_indicies[count] = 6; count++;
		draw_indicies[count] = 7; count++;
		draw_indicies[count] = 4; count++;
	}
	if (visible_walls.left_side) {
		draw_indicies[count] = 8; count++;
		draw_indicies[count] = 9; count++;
		draw_indicies[count] = 10; count++;

		draw_indicies[count] = 10; count++;
		draw_indicies[count] = 11; count++;
		draw_indicies[count] = 8; count++;
	}
	if (visible_walls.right_side) {
		draw_indicies[count] = 12; count++;
		draw_indicies[count] = 13; count++;
		draw_indicies[count] = 14; count++;

		draw_indicies[count] = 14; count++;
		draw_indicies[count] = 15; count++;
		draw_indicies[count] = 12; count++;
	}
	if (visible_walls.top) {
		draw_indicies[count] = 16; count++;
		draw_indicies[count] = 17; count++;
		draw_indicies[count] = 18; count++;

		draw_indicies[count] = 18; count++;
		draw_indicies[count] = 19; count++;
		draw_indicies[count] = 16; count++;
	}
	if (visible_walls.bottom) {
		draw_indicies[count] = 20; count++;
		draw_indicies[count] = 21; count++;
		draw_indicies[count] = 22; count++;

		draw_indicies[count] = 22; count++;
		draw_indicies[count] = 23; count++;
		draw_indicies[count] = 20; count++;
	}
}

unsigned int block::get_size(void) {
	return size;
}

void block::set_ver(float* _ver, int v)
{
	//delete[] vertex;
	//vertex = nullptr;
	//vertex = new float[v];
	//for (size_t i = 0; i < v; i++)
	//{
	//	vertex[i] = _ver[i];
	//}
	//size = sizeof(float) * v;
}

void block::set_ind_all(unsigned int* _ind, int v)
{
	delete[] draw_indicies;
	draw_indicies = nullptr;
	draw_indicies = new unsigned int[v];
	for (size_t i = 0; i < v; i++)
	{
		draw_indicies[i] = _ind[i];
	}
	count = v;
}

block::~block()
{
	delete[] vertex;
	delete[] draw_indicies;
}
