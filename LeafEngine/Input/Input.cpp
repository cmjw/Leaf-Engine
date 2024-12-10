#include "Input/Input.h"

/* Return up key pressed */
bool Input::upPressed() {
	return sf::Keyboard::isKeyPressed(UP);
}

/* Return down key pressed */
bool Input::downPressed() {
	return sf::Keyboard::isKeyPressed(DOWN);
}

/* Return left key pressed */
bool Input::leftPressed() {
	return sf::Keyboard::isKeyPressed(LEFT);
}

/* Return right key pressed */
bool Input::rightPressed() {
	return sf::Keyboard::isKeyPressed(RIGHT);
}