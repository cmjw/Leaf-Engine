#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "ImGui/imgui.h"

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

	// core functions
	void Initialize();
	void Render();
	void Update(float deltaTime);
	void Cleanup();

	void initGameWindow();
};

#endif // !GAME_H
