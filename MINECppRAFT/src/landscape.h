#pragma once
#include "chunk.h"

class landscape :
    public chunk
{
private:
    //unsigned int wall_count;
    void set_render_data();
    void add_tree(int x, int y, int h);
public:
    landscape(int x, int y, int z);
    void set_blocks(unsigned int** map);
};

