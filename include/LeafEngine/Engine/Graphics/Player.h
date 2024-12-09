#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"

class Player {
public:
	int width;
	int height;

	sf::RectangleShape sprite;

	Player();
	~Player();

	// main functions
	void Render(sf::RenderWindow& window);
	void Update(float deltaTime);
	
private:
	void initialize();
};

#endif // !PLAYER_H
