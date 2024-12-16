#ifndef EDITOR_H
#define EDITOR_H

#include "Core/Game.h"

#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>

#include <windows.h>
#include <iostream>
#include <fstream>

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

	bool isDarkMode;

	// main functions
	void initialize();
	void render();
	void cleanup();

	// menu bar
	void initMenuBar();
	void renderMenuBar();
};

#endif // !EDITOR_H
