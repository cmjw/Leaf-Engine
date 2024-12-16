#include "Editor.h"

Editor::Editor() {
	this->initialize();
}

Editor::~Editor() {
	this->cleanup();
}

/* Initialize editor */
void Editor::initialize() {
	// make fullscreen
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

	// create window
	window.create(sf::VideoMode(desktopMode.width, desktopMode.height), "Leaf Editor", sf::Style::Default);
	
	ImGui::SFML::Init(window);

	// maximize window
	window.setPosition(sf::Vector2i(0, 0));
	window.setSize(sf::Vector2u(desktopMode.width, desktopMode.height));
}

/* Run editor program */
void Editor::run() {
	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			// if window is closed
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			ImGui::SFML::ProcessEvent(event);
		}

		// start ImGui frame
		ImGui::SFML::Update(window, deltaClock.restart());

		sf::Vector2u windowSize = window.getSize();
		
		// menu bar
		initMenuBar();
		renderMenuBar();

		// create main content area
		ImGui::Begin("Editor", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

		// end content area
		ImGui::End();

		this->render();
	}

	// if window is closed
	this->cleanup();
}

/* Render editor window */
void Editor::render() {
	window.clear();
	
	ImGui::SFML::Render(window);

	window.display();
}

/* Cleanup resources */
void Editor::cleanup() {
	ImGui::SFML::Shutdown();
}

/* Initialize menu bar */
void Editor::initMenuBar() {
	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("Load Project")) {
				// Load a project/data folder
			}
			if (ImGui::MenuItem("Save")) {
				// Save the current data folder 
			}
			if (ImGui::MenuItem("Close Project")) {

			}
			if (ImGui::MenuItem("Exit")) {
				window.close();
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}

/* Render menu bar */
void Editor::renderMenuBar() {
	sf::Vector2u windowSize = window.getSize();
	float menuBarHeight = ImGui::GetFrameHeight();

	ImGui::SetNextWindowPos(ImVec2(0, menuBarHeight));  // Position window just below the menu bar
	ImGui::SetNextWindowSize(ImVec2(windowSize.x, windowSize.y - menuBarHeight));
}