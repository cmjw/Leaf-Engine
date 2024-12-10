#ifndef PLAYER_H
#define PLAYER_H

#include "Input/Input.h"
#include "Graphics/Sprite.h"

#include <nlohmann/json.hpp>

class Player {
public:
	Player();
	~Player();

	Sprite playerSprite;

	// main functions
	void Render(sf::RenderWindow& window);
	void Update(float deltaTime);
	
private:
	void initialize();
	void updateMovement(float deltaTime);
	//void movePlayer(float dx, float dy, float deltaTime);
};

#endif // !PLAYER_H
