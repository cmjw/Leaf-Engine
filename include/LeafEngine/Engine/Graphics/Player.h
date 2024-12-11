#ifndef PLAYER_H
#define PLAYER_H

#include "Input/Input.h"
#include "Graphics/Sprite.h"

#include <nlohmann/json.hpp>

const std::string STARTING_PLAYER_GRAPHIC = "../../gameData/starting_graphic.png";

class Player {
public:
	Player();
	~Player();

	Sprite playerSprite;

	// main functions
	void render(sf::RenderWindow& window);
	void update(float deltaTime);

	void setPosition(float x, float y);
	
private:
	void initialize();
	void updateMovement(float deltaTime);
	
};

#endif // !PLAYER_H
