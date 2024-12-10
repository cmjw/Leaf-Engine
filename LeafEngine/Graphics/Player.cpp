#include "Graphics/Player.h"

Player::Player() {
	this->initialize();
}

Player::~Player() {

}

/* Initialize the player */
void Player::initialize() {

	// test data
	this->width = 24;
	this->height = 48;

	sprite.setSize(sf::Vector2f(width, height));
	sprite.setFillColor(sf::Color::Blue);
	sprite.setPosition(200, 200);

	movementSpeed = 200.f;
}

/* Render the player sprite */
void Player::Render(sf::RenderWindow& window) {
	window.draw(sprite);
}

/* Update the player */
void Player::Update(float deltaTime) {
	updateMovement(deltaTime);
}

/* Handle movement */
void Player::updateMovement(float deltaTime) {
	if (Input::upPressed()) {
		movePlayer(0, -1, deltaTime);
	}
	if (Input::downPressed()) {
		movePlayer(0, 1, deltaTime);
	}
	if (Input::leftPressed()) {
		movePlayer(-1, 0, deltaTime);
	}
	if (Input::rightPressed()) {
		movePlayer(1, 0, deltaTime);
	}
}

/* Move the player sprite */
void Player::movePlayer(float dx, float dy, float deltaTime) {
	float newX = dx * movementSpeed * deltaTime;
	float newY = dy * movementSpeed * deltaTime;

	sprite.move(newX, newY);
}