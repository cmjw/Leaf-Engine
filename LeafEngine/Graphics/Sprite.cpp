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
	loadTexture("../../gameData/starting_graphic.png");

	movementSpeed = 150.f;
	
	timeSinceLastFrame = 0.0f;
	animationSpeed = 0.5f;

	currentDirection = FORWARD_ROW;
}

/* Render sprite */
void Sprite::render(sf::RenderWindow& window) {
	window.draw(sprite);
}

/* Update sprite */
void Sprite::update(float deltaTime) {
	handleAnimation(deltaTime);
	handleInput(deltaTime);
}

/* Move sprite */
void Sprite::move(float dx, float dy, float deltaTime) {
	float newX = dx * movementSpeed * deltaTime;
	float newY = dy * movementSpeed * deltaTime;

	sprite.move(newX, newY);
}

/* Set sprite position */
void Sprite::setPosition(float x, float y) {
	sprite.setPosition(x, y);
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

/* Handle sprite animation based on input */
void Sprite::handleAnimation(float deltaTime) {
	timeSinceLastFrame += deltaTime;

	int lastDirection = currentDirection;

	if (Input::upPressed()) {
		currentDirection = BACKWARD_ROW;
	}
	if (Input::downPressed()) {
		currentDirection = FORWARD_ROW;
	}
	if (Input::leftPressed()) {
		currentDirection = LEFT_ROW;
	}
	if (Input::rightPressed()) {
		currentDirection = RIGHT_ROW;
	}

	// if direction has changed, immediately show new frame
	if (currentDirection != lastDirection) {
		currentFrame = 0;

		this->nextFrame();
	}

	// otherwise animate frames normally
	else if (timeSinceLastFrame >= animationSpeed) {
		currentFrame = (currentFrame + 1) % NUM_FRAMES_PER_DIR;

		this->nextFrame();
	}
}

/* Change sprite frame */
void Sprite::nextFrame() {
	int x1 = currentFrame * SPRITE_WIDTH;
	int y1 = currentDirection * SPRITE_HEIGHT;

	sprite.setTextureRect(sf::IntRect(x1, y1, SPRITE_WIDTH, SPRITE_HEIGHT));

	timeSinceLastFrame = 0.f;
}


/* Load a texture image for this Sprite */
void Sprite::loadTexture(const std::string filename) {
	if (!texture.loadFromFile(filename)) {
		exit(-1);
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_WIDTH, SPRITE_HEIGHT));
}