#include "Graphics/Player.h"

Player::Player() {
	this->initialize();

	playerSprite.loadTextureImage(STARTING_PLAYER_GRAPHIC);
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
	playerSprite.handleInput(deltaTime);
}

/* Handle movement */
void Player::updateMovement(float deltaTime) {
	// sprite movement handled in Sprite class
}