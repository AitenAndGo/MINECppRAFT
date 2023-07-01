#pragma once

#define UNIT			0.0625
#define SIZE			24
#define GRASS			 0
#define STONE			 3
#define SAND			 6
#define DIRT			 9
#define SNOW			12
#define WATER			15
#define WOOD			18
#define LEAFS			21

typedef struct {
	float u;
	float v;
} tcor;

const tcor catalog[SIZE][4] = {
	//GRASS
	{{3 * UNIT, UNIT}, {4 * UNIT, UNIT}, {4 * UNIT, 0}, {3 * UNIT, 0} },
	{{0 * UNIT, UNIT}, {1 * UNIT, UNIT}, {1 * UNIT, 0}, {0 * UNIT, 0} },
	{{2 * UNIT, UNIT}, {3 * UNIT, UNIT}, {3 * UNIT, 0}, {2 * UNIT, 0} },
	//STONE
	{{1 * UNIT, UNIT}, {2 * UNIT, UNIT}, {2 * UNIT, 0}, {1 * UNIT, 0} },
	{{1 * UNIT, UNIT}, {2 * UNIT, UNIT}, {2 * UNIT, 0}, {1 * UNIT, 0} },
	{{1 * UNIT, UNIT}, {2 * UNIT, UNIT}, {2 * UNIT, 0}, {1 * UNIT, 0} },
	//SAND
	{{2 * UNIT, 2 * UNIT}, {3 * UNIT, 2 * UNIT}, {3 * UNIT, UNIT}, {2 * UNIT, UNIT} },
	{{2 * UNIT, 2 * UNIT}, {3 * UNIT, 2 * UNIT}, {3 * UNIT, UNIT}, {2 * UNIT, UNIT} },
	{{2 * UNIT, 2 * UNIT}, {3 * UNIT, 2 * UNIT}, {3 * UNIT, UNIT}, {2 * UNIT, UNIT} },
	//DIRT
	{{2 * UNIT, UNIT}, {3 * UNIT, UNIT}, {3 * UNIT, 0}, {2 * UNIT, 0} },
	{{2 * UNIT, UNIT}, {3 * UNIT, UNIT}, {3 * UNIT, 0}, {2 * UNIT, 0} },
	{{2 * UNIT, UNIT}, {3 * UNIT, UNIT}, {3 * UNIT, 0}, {2 * UNIT, 0} },
	//SNOW
	{{4 * UNIT, 5 * UNIT}, {5 * UNIT, 5 * UNIT}, {5 * UNIT, 4 * UNIT}, {4 * UNIT, 4 * UNIT} },
	{{2 * UNIT, 5 * UNIT}, {3 * UNIT, 5 * UNIT}, {3 * UNIT, 4 * UNIT}, {2 * UNIT, 4 * UNIT} },
	{{2 * UNIT, UNIT}, {3 * UNIT, UNIT}, {3 * UNIT, 0}, {2 * UNIT, 0} },
	//WATER
	{{14 * UNIT, UNIT}, {15 * UNIT, UNIT}, {15 * UNIT, 0}, {14 * UNIT, 0} },
	{{14 * UNIT, UNIT}, {15 * UNIT, UNIT}, {15 * UNIT, 0}, {14 * UNIT, 0} },
	{{14 * UNIT, UNIT}, {15 * UNIT, UNIT}, {15 * UNIT, 0}, {14 * UNIT, 0} },
	//WOOD
	{{5 * UNIT, 2 * UNIT}, {6 * UNIT, 2 * UNIT}, {6 * UNIT, UNIT}, {5 * UNIT, UNIT} },
	{{4 * UNIT, 2 * UNIT}, {5 * UNIT, 2 * UNIT}, {5 * UNIT, UNIT}, {4 * UNIT, UNIT} },
	{{5 * UNIT, 2 * UNIT}, {6 * UNIT, 2 * UNIT}, {6 * UNIT, UNIT}, {5 * UNIT, UNIT} },
	//LEAFS
	{{5 * UNIT, 4 * UNIT}, {6 * UNIT, 4 * UNIT}, {6 * UNIT, 3 * UNIT}, {5 * UNIT, 3 * UNIT} },
	{{5 * UNIT, 4 * UNIT}, {6 * UNIT, 4 * UNIT}, {6 * UNIT, 3 * UNIT}, {5 * UNIT, 3 * UNIT} },
	{{5 * UNIT, 4 * UNIT}, {6 * UNIT, 4 * UNIT}, {6 * UNIT, 3 * UNIT}, {5 * UNIT, 3 * UNIT} },
};

