#ifndef MAP_H
#define MAP_H

#include "Input/Input.h"
#include <nlohmann/json.hpp>
#include <fstream>

const std::string STARTING_TILESET = "../../data/tileset.png";
const std::string STARTING_PLAYER_MAP = "../../data/map.json";

#define TILE_SIZE 16 // for now restrict to assume 16x16 tiles

class Map {
public:
	Map();
	~Map();

	Map(int width, int height, const std::string& mapDataPath, const std::string& tilesetPath);

	int getWidth();
	int getHeight();

	void loadMapDataFromFile(const std::string& mapDataPath);

private:
	int width; /* width in tiles */
	int height; /* height in tiles */

	sf::Texture tileset;
	sf::Sprite sprite;

	std::vector<std::vector<int>> mapData;
};

#endif // !MAP_H
