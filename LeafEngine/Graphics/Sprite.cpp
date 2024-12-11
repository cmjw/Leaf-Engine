#include "Graphics/Sprite.h"

Sprite::Sprite() {
	this->initialize();
}

Sprite::~Sprite() {

}

/* Initialize sprite */
void Sprite::initialize() {
	// test data
	width = 16;
	height = 24;

	// placeholder
	loadTextureImage("../../gameData/starting_graphic.png");

	movementSpeed = 200.f;
}

/* Render sprite */
void Sprite::render(sf::RenderWindow& window) {
	window.draw(sprite);
}

/* Update sprite */
void Sprite::update(float deltaTime) {

}

/* Move sprite */
void Sprite::move(float dx, float dy, float deltaTime) {
	float newX = dx * movementSpeed * deltaTime;
	float newY = dy * movementSpeed * deltaTime;

	sprite.move(newX, newY);
}

/* Handle user input */
void Sprite::handleInput(float deltaTime) {
	if (Input::upPressed()) {
		move(0, -1, deltaTime);
	}
	if (Input::downPressed()) {
		move(0, 1, deltaTime);
	}
	if (Input::leftPressed()) {
		move(-1, 0, deltaTime);
	}
	if (Input::rightPressed()) {
		move(1, 0, deltaTime);
	}
}

/* Load a texture image for this Sprite */
void Sprite::loadTextureImage(const std::string filename) {
	if (!texture.loadFromFile(filename)) {
		exit(-1);
	}
	sprite.setTexture(texture);
}