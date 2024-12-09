#ifndef INPUT_H
#define INPUT_H

#include "SFML/Graphics.hpp"

const sf::Keyboard::Key UP    = sf::Keyboard::W;
const sf::Keyboard::Key DOWN  = sf::Keyboard::S;
const sf::Keyboard::Key LEFT  = sf::Keyboard::A;
const sf::Keyboard::Key RIGHT = sf::Keyboard::D;

class Input {
public:
	static bool upPressed();
	static bool downPressed();
	static bool leftPressed();
	static bool rightPressed();
};

#endif // !INPUT_H
