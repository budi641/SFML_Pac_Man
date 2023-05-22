#pragma once

#include "../State.h"     // Include the base State class
#include "../../UI/Button.h"   // Include the Button class

// MainMenuState class derived from State class
class MainMenuState : public State
{
public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states, GameManager* gameManager);    // Constructor
    ~MainMenuState();    // Destructor

    // Update the main menu state logic
    void Update(const float& deltaTime);

    // Draw the main menu state
    void Draw();

private:
    std::map<std::string, Button*> buttons;     // Map of buttons in the main menu
    sf::Sprite mapSprite;                       // Sprite for the main menu background
    sf::Texture mapTexture;                     // Texture for the main menu background
};
