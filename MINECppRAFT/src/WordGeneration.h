#pragma once
#include "landscape.h"

class WordGeneration
{
private:
	int last_mid_chunk_x;
	int last_mid_chunk_z;
	int world_size;
	int chunk_vision;

	int last_chunk_map[81][2];

	unsigned int** map;
	std::vector<chunk*> world;
public:
	WordGeneration(const WordGeneration& w) = delete;
	inline std::vector<chunk*> get_world() { return world; };
	void generate_world_map(int64_t seed = 15623584);
	std::vector<chunk*> get_render_input();
	void AddChunk(chunk* _chunk);
	WordGeneration();
	~WordGeneration();
	bool upgrade_chunks(float x, float y);
	inline unsigned int** get_map(void) { return map; };
};

