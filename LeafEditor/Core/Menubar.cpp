#include "Editor.h"

/* Initialize menu bar */
void Editor::initMenuBar() {
	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("Load")) {
				// Load a project/data folder
			}

			if (ImGui::MenuItem("Save")) {
				// Save the current data folder 
			}

			if (ImGui::MenuItem("Close")) {
				// Close the current project
			}

			if (ImGui::MenuItem("Exit")) {
				// Exit the editor
				window.close();
			}

			ImGui::EndMenu();
		}

		if (ImGui::BeginMenu("View")) {
			if (ImGui::MenuItem("Toggle Dark/Light Mode")) {
				// Switch between light and dark mode
				isDarkMode = !isDarkMode;

				if (isDarkMode) {
					ImGui::StyleColorsDark();
				}
				else {
					ImGui::StyleColorsLight();
				}
			}
			ImGui::EndMenu();
		}

		if (ImGui::MenuItem("Playtest")) {
			STARTUPINFO si;
			PROCESS_INFORMATION pi;

			// Zero out the structures
			ZeroMemory(&si, sizeof(si));
			si.cb = sizeof(si);
			ZeroMemory(&pi, sizeof(pi));

			// Start the process using a relative path
			if (CreateProcess(
				"Engine.exe",      // Relative path to your executable
				NULL,              // Command line arguments
				NULL,              // Process handle not inheritable
				NULL,              // Thread handle not inheritable
				FALSE,             // Do not inherit handles
				0,                 // No creation flags
				NULL,              // Use parent's environment block
				NULL,              // Use parent's starting directory 
				&si,               // Pointer to STARTUPINFO structure
				&pi)               // Pointer to PROCESS_INFORMATION structure
				) {
				// Successfully started the process
				CloseHandle(pi.hProcess);
				CloseHandle(pi.hThread);
			}
			else {
				MessageBox(NULL, "Failed to launch the executable", "Error", MB_OK | MB_ICONERROR);
			}
		}

		ImGui::EndMainMenuBar();
	}
}

/* Render menu bar */
void Editor::renderMenuBar() {
	sf::Vector2u windowSize = window.getSize();
	float menuBarHeight = ImGui::GetFrameHeight();

	// position window just below the menu bar
	ImGui::SetNextWindowPos(ImVec2(0, menuBarHeight));
	ImGui::SetNextWindowSize(ImVec2(windowSize.x, windowSize.y - menuBarHeight));
}