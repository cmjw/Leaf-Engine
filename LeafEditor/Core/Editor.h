#ifndef EDITOR_H
#define EDITOR_H

#include "Core/Game.h"

#include <SFML/Graphics.hpp>

#include <ImGui/imgui.h>
#include <ImGui/imgui-SFML.h>

const int EDITOR_WIDTH = 1200;
const int EDITOR_HEIGHT = 800;

class Editor {
public:
	Editor();
	~Editor();

	void run();

private:
	sf::RenderWindow window;
	sf::Clock deltaClock;

	// main functions
	void initialize();
	void render();

	// menu bar
	// ...
};

#endif // !EDITOR_H
