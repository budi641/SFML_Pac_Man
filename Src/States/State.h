#pragma once

#include "SFML/Graphics.hpp"
#include "../Common.h"

// Forward declaration of GameManager class
class GameManager;

// State class representing a game state
class State
{
protected:
    sf::RenderWindow* window;        // Pointer to the game window
    std::stack<State*>* states;      // Pointer to the state stack
    bool quit;                       // Flag indicating whether to quit the state
    GameManager* gameManager;        // Pointer to the game manager

public:
    // Constructor
    State(sf::RenderWindow* window, std::stack<State*>* states, GameManager* gameManager);

    // Update the state logic
    virtual void Update(const float& deltaTime) = 0;

    // Draw the state
    virtual void Draw() = 0;

    // Get the quit flag
    const bool& GetQuit() const;

    // End the state
    void EndState();
};
