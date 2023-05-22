#pragma once

#include "Enemy.h"

// Blinky class derived from Enemy class
class Blinky : public Enemy
{
public:
    // Constructor
    Blinky(sf::Vector2i gridPos, GameState* gameState);

    // Destructor
    ~Blinky();

private:
    // Get the scatter target position for Blinky
    sf::Vector2i GetScatterTargetPosition() override;

    // Setup animations for Blinky
    void SetupAnimations() override;
};
