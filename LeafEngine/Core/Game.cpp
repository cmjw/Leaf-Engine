#include "Core/Game.h"

Game::Game() {
	// default dimensions
	gameWidth = 640;
	gameHeight = 480;
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
	window.create(sf::VideoMode(gameWidth * zoom, gameHeight * zoom), "Engine");

	view.setSize(gameWidth, gameHeight);
	view.setCenter(gameWidth / 2, gameHeight / 2);

	// set zoom
	view.zoom(zoom / 2);
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

	window.display();
}

/* Update game elements */
void Game::Update(float deltaTime) {
	// update elements
}

/* Cleanup game elements */
void Game::Cleanup() {
	
}