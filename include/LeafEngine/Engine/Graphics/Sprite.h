#ifndef SPRITE_H
#define SPRITE_H

#include "Input/Input.h"
#include "SFML/Graphics.hpp"

const int SPRITE_WIDTH = 20;
const int SPRITE_HEIGHT = 28;

const int NUM_SPRITE_DIRS = 4;
const int NUM_FRAMES_PER_DIR = 3;
 
const int FORWARD_ROW  = 0;
const int LEFT_ROW     = 1;
const int RIGHT_ROW    = 2;
const int BACKWARD_ROW = 3;

class Sprite {
public:
	int width;
	int height;

	float movementSpeed;

	float timeSinceLastFrame;
	float animationSpeed;
	int currentFrame;
	int currentDirection;

	sf::Sprite sprite;
	sf::Texture texture;

	Sprite();
	~Sprite();

	void render(sf::RenderWindow& window);
	void update(float deltaTime);

	void handleInput(float deltaTime);
	void move(float dx, float dy, float deltaTime);
	void setPosition(float x, float y);

	void loadTexture(const std::string filename);

private:
	void initialize();

	void handleAnimation(float deltaTime);
};

#endif // !SPRITE_H
