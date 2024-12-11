#ifndef SPRITE_H
#define SPRITE_H

#include "Input/Input.h"

#include "SFML/Graphics.hpp"

class Sprite {
public:
	int width;
	int height;

	float movementSpeed;

	sf::Sprite sprite;
	sf::Texture texture;

	Sprite();
	~Sprite();

	void render(sf::RenderWindow& window);
	void update(float deltaTime);

	void handleInput(float deltaTime);
	void move(float dx, float dy, float deltaTime);

private:
	void initialize();
};

#endif // !SPRITE_H
