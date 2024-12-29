#ifndef GAME_H
#define GAME_H

#include "Graphics/Player.h"
#include "Graphics/Map.h"

class Game {
public:
	Game();
	~Game();

	void Run();

private:
	int gameWidth;
	int gameHeight;
	float zoom;

	std::string gameTitle;

	sf::RenderWindow window;
	sf::View view;

	// player
	Player player;

	// core functions
	void initialize();
	void render();
	void update(float deltaTime);
	void cleanup();

	void initGameWindow();
};

#endif // !GAME_H
