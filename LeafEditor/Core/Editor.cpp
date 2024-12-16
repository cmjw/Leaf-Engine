#include "Editor.h"

Editor::Editor() {
	this->initialize();
}

Editor::~Editor() {

}

/* Initialize editor */
void Editor::initialize() {
	// make fullscreen
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

	// create window
	window.create(sf::VideoMode(desktopMode.width, desktopMode.height), "Game Editor", sf::Style::Default);
	
	//ImGui::SFML::Init(window);
}

/* Run editor program */
void Editor::run() {

}

/* Render editor window */
void Editor::render() {

}