#include "Graphics/Map.h"

/* Map default constructor */
Map::Map() {

}

/* Map constructor.
	Width and height are in multiples of TILESET_SIZE. Eg. 10 x 20 tiles. */
Map::Map(int width, int height, const std::string& mapDataPath, const std::string& tilesetPath) {
	this->width = width;
	this->height = height;

	// load tileset data
	if (!tileset.loadFromFile(tilesetPath)) {
		std::cerr << "Error: could not open tileset file at " << tilesetPath << std::endl;
		exit(-1);
	}

	// load map data
	// ...
}

/* Map deconstructor */
Map::~Map() {

}

/* Get the Map width in tiles */
int Map::getWidth() {
	return this->width;
}

/* Get the Map height in tiles */
int Map::getHeight() {
	return this->height;
}