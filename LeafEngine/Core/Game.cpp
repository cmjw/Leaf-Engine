#include "Core/Game.h"

const int windowWidth = 320 * 3;
const int windowHeight = 240 * 3;

Game::Game() {
	// default dimensions
	gameWidth = 320;
	gameHeight = 240;
	zoom = 1;

	this->initialize();
}

Game::~Game() {
	cleanup();
}

/* Initialize game elements */
void Game::initialize() {
	this->initGameWindow();

}

/* Initialize game window */
void Game::initGameWindow() {
	// create window
	window.create(sf::VideoMode(windowWidth, windowHeight), "Engine");

	view.setSize(gameWidth, gameHeight);
	view.setCenter(gameWidth / 2, gameHeight / 2);

	// set zoom
	view.zoom(zoom);
	window.setView(view);
}

/* Run the game */
void Game::Run() {
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		float deltaTime = clock.restart().asSeconds();

		// update and render
		this->update(deltaTime);
		this->render();
	}
}

/* Render the game window */
void Game::render() {
	window.clear();

	// render player sprite
	player.render(window);

	window.display();
}

/* Update game elements */
void Game::update(float deltaTime) {
	// update elements
	player.update(deltaTime);
}

/* Cleanup game elements */
void Game::cleanup() {
	
}