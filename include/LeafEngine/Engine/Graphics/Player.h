#ifndef PLAYER_H
#define PLAYER_H

#include "Input/Input.h"

class Player {
public:
	int width;
	int height;

	float movementSpeed;

	sf::RectangleShape sprite;

	Player();
	~Player();

	// main functions
	void Render(sf::RenderWindow& window);
	void Update(float deltaTime);
	
private:
	void initialize();
	void updateMovement(float deltaTime);
	void movePlayer(float dx, float dy, float deltaTime);
};

#endif // !PLAYER_H
