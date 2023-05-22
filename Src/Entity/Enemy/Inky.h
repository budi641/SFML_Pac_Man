#pragma once

#include "Enemy.h"

// Inky class derived from Enemy class
class Inky : public Enemy
{
public:
    // Constructor
    Inky(sf::Vector2i gridPos, GameState* gameState);

    // Destructor
    ~Inky();

private:
    // Get the scatter target position for Inky
    sf::Vector2i GetScatterTargetPosition() override;

    // Get the chase target position for Inky
    sf::Vector2i GetChaseTargetPosition() override;

    // Setup animations for Inky
    void SetupAnimations() override;
};
