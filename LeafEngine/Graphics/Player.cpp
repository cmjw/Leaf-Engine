#include "Graphics/Player.h"

Player::Player() {
	this->initialize();
}

Player::~Player() {

}

/* Initialize the player */
void Player::initialize() {
	this->width = 20;
	this->height = 20;

	sprite.setSize(sf::Vector2f(width, height));
	sprite.setFillColor(sf::Color::Blue);
	sprite.setPosition(200, 200);
}

/* Render the player sprite */
void Player::Render(sf::RenderWindow& window) {
	window.draw(sprite);
}

/* Update the player */
void Player::Update(float deltaTime) {

}