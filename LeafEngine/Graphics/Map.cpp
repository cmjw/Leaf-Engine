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

	sprite.setTexture(tileset);

	// load map data
	loadMapDataFromFile(mapDataPath);
}

/* Load Map tile data from JSON file */
void Map::loadMapDataFromFile(const std::string& mapDataPath) {
	std::ifstream file(mapDataPath);

	if (!file.is_open()) {
		std::cerr << "Error: could not open map data file " << mapDataPath << std::endl;
		return;
	}

	nlohmann::json jsonData;

	try {
		file >> jsonData;
	}
	catch (const nlohmann::json::parse_error& e) {
		std::cerr << "Parse error at byte " << e.byte << ": " << e.what() << std::endl;
		file.close();
		return;
	}
	catch (const std::exception& e) {
		std::cerr << "An error occurred: " << e.what() << std::endl;
		file.close();
		return;
	}
	file.close();

	this->width  = jsonData["map"]["width"];
	this->height = jsonData["map"]["height"];

	// load tile data
	mapData.resize(height, std::vector<int>(width));

	const auto& tiles = jsonData["map"]["tiles"];
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			mapData[y][x] = tiles[y][x];
		}
	}
}

/* Render the Map on window */
void Map::render(sf::RenderWindow& window) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int posX = mapData[j][i];
			int posY = 0;

			// for 4x4 tileset
			sprite.setTextureRect(sf::IntRect(TILE_SIZE * posX, TILE_SIZE * posY, TILE_SIZE, TILE_SIZE));

			sprite.setPosition(i * TILE_SIZE, j * TILE_SIZE);
			window.draw(sprite);
		}
	}
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