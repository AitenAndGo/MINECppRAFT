#include "landscape.h"
#include <iostream>

void landscape::set_render_data()
{
		delete[] vertex;
		delete[] draw_indicies;
		vertex = new float[count * 144];
		draw_indicies = new unsigned int[count * 6 * 6];
		wall_count = count * 6;
		int index1 = 0;
		int index2 = 0;
		for (size_t i = 0; i < count; i++) {
			memcpy(&vertex[index1], blocks[i]->get_ver(), sizeof(float) * 144);
			//std::cout << index1 << std::endl;
			index1 += 144;
			//vertex[i] = blocks[i]->get_ver()[i];
			for (size_t j = 0; j < blocks[i]->get_count(); j++)
			{
				draw_indicies[index2] = blocks[i]->get_ind()[j] + (i * 24);
				index2++;
			}
			delete blocks[i];
		}
		blocks.clear();
}

void landscape::add_tree(int x, int y, int h)
{
	wall w1;
	w1.back_side = true;
	w1.bottom = true;
	w1.back_side = true;
	w1.front_side = true;
	w1.left_side = true;
	w1.right_side = true;
	int num = 6;

	for (int i = 0; i < 5; i++) {
		block* b = new block(WOOD, 1, x, h + i, y);
		b->set_ind(w1, num);
		blocks.push_back(b);
		count++;
		if (i > 2) {
			for (size_t j = x - 2; j < x + 3; j++)
			{
				for (size_t k = y - 2; k < y + 3; k++) {
					if (k != 0 && j != 0) {
						block* b1 = new block(LEAFS, 1, j, h + i, k);
						blocks.push_back(b);
						b1->set_ind(w1, num);
						count++;
					}
				}
			}
		}
	}

}

landscape::landscape(int x, int y, int z)
{
	count = 0;
	position[0] = x;
	position[1] = y;
	position[2] = z;
}

void landscape::set_blocks(unsigned int** map)
{
	count = 0;
	add_tree(1024, 0, 1024);
	//for (size_t i = position[0]; i < position[0] + 9 * 16; i += 4)
	//{
	//	for (size_t j = position[2]; j < position[2] + 9 * 16; j += 4) {
	//		if (i > 5 && i < 2040) {
	//			if (j > 5 && j < 2040) {
	//				if (map[i][j] <= 40) {
	//					if (rand() % 10 == 1) {
	//						add_tree(i, j, map[i][j]);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	set_render_data();
}
