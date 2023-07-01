#pragma once
#include "block.h"
#include <vector>

class chunk
{
protected:
	unsigned int* draw_indicies;
	float* vertex;
	std::vector<block*> blocks;
	float position[3];
	unsigned int count;
	unsigned int wall_count;
private:
	unsigned int id_count;


	//double height[16][16];
	//std::vector<block*> all_in_one;

	//wall get_visible_walls(const float* pos, unsigned int* num);
	block* get_block(unsigned int** map, int x, int z, int h);
	void set_render_data();
	//void set_render_input(void);
	VertexArray* voa;
	VertexBuffer* vb;
	IndexBuffer* ib;
public:
	chunk(const chunk& w) = delete;
	chunk(float x = 0, float y = 0, float z = 0);
	~chunk();
	//void set_blocks_height(unsigned int word_generation_chunk_map[][16], unsigned int block_type);
	void set_blocks(unsigned int** map);

	inline VertexArray* get_voa() { return voa; };
	inline VertexBuffer* get_vb() { return vb; };
	inline IndexBuffer* get_ib() { return ib; };

	inline void set_voa(VertexArray* VOA) { voa = VOA; };
	inline void set_vb(VertexBuffer* VB) { vb = VB; };
	inline void set_ib(IndexBuffer* IB) { ib = IB; };

	inline float* get_vertex_data() { return vertex; };
	inline unsigned int* get_ind_data() { return draw_indicies; };
	inline unsigned int get_id_count() { return id_count; };
	inline unsigned int get_vertex_size() { return sizeof(float) * count * 144; };

	inline float* get_position() { return position; };
	inline void set_position(float x, float y, float z) { position[0] = x; position[1] = y; position[2] = z; };

	std::vector<block*>* get_blocks(void);
	//std::vector<block*>* get_chunk(void);
	inline unsigned int get_size() { return (count * 144 * sizeof(float)); };
	inline unsigned int get_count() { return wall_count * 6; };
};

