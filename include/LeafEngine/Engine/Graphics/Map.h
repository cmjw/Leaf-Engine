#ifndef MAP_H
#define MAP_H

#include "Input/Input.h"

class Map {
public:
	Map();
	~Map();

	int getWidth();
	int getHeight();

private:
	int mapWidth;
	int mapHeight;
};

#endif // !MAP_H
