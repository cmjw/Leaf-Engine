#include "Graphics/Player.h"

Player::Player() {
	this->initialize();
}

Player::~Player() {

}

/* Initialize the player */
void Player::initialize() {

}

/* Render the player sprite */
void Player::Render(sf::RenderWindow& window) {
	playerSprite.render(window);
}

/* Update the player */
void Player::Update(float deltaTime) {
	updateMovement(deltaTime);
}

/* Handle movement */
void Player::updateMovement(float deltaTime) {
	if (Input::upPressed()) {
		playerSprite.move(0, -1, deltaTime);
	}
	if (Input::downPressed()) {
		playerSprite.move(0, 1, deltaTime);
	}
	if (Input::leftPressed()) {
		playerSprite.move(-1, 0, deltaTime);
	}
	if (Input::rightPressed()) {
		playerSprite.move(1, 0, deltaTime);
	}
}