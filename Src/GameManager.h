#pragma once

#include "Common.h"

// Forward declaration of the State class
class State;

class GameManager
{
public:
	sf::RenderWindow* window;     // Pointer to the SFML window
	std::stack<State*> states;    // Stack to hold the game states
	float deltaTime = 0;          // Time elapsed between frames
	float aspectRatio;            // Aspect ratio of the game window

	// Function to update the game
	void Update();

	// Function to start the game manager
	void StartGameManager();

	// Destructor
	~GameManager();
private:
	sf::Clock clock;   // SFML clock object to measure time
};
