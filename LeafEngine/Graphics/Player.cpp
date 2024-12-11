#include "Graphics/Player.h"

Player::Player() {
	this->initialize();

	playerSprite.loadTexture(STARTING_PLAYER_GRAPHIC);
}

Player::~Player() {

}

/* Initialize the player */
void Player::initialize() {

}

/* Render the player sprite */
void Player::render(sf::RenderWindow& window) {
	playerSprite.render(window);
}

/* Update the player */
void Player::update(float deltaTime) {
	playerSprite.update(deltaTime);
}

/* Handle movement */
void Player::updateMovement(float deltaTime) {
	// sprite movement handled in Sprite class
}

/* Set the player position */
void Player::setPosition(float x, float y) {
	playerSprite.setPosition(x, y);
	
	// set position of any other Player elements
}