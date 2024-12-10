#include "Core/Game.h"

const int windowWidth = 320 * 2;
const int windowHeight = 240 * 2;

Game::Game() {
	// default dimensions
	gameWidth = 320;
	gameHeight = 240;
	zoom = 1;

	this->Initialize();
}

Game::~Game() {
	Cleanup();
}

/* Initialize game elements */
void Game::Initialize() {
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
		this->Update(deltaTime);
		this->Render();
	}
}

/* Render the game window */
void Game::Render() {
	window.clear();

	// render player sprite
	player.Render(window);

	window.display();
}

/* Update game elements */
void Game::Update(float deltaTime) {
	// update elements
	player.Update(deltaTime);
}

/* Cleanup game elements */
void Game::Cleanup() {
	
}