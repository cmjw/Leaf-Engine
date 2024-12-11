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

	/*sprite.setSize(sf::Vector2f(width, height));
	sprite.setFillColor(sf::Color::Red);
	sprite.setPosition(20, 20);*/

	if (!texture.loadFromFile("../../gameData/starting_graphic.png")) {
		exit(-1);
	}
	sprite.setTexture(texture);

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