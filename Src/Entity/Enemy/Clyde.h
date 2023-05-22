#pragma once

#include "Enemy.h"

// Clyde class derived from Enemy class
class Clyde : public Enemy
{
public:
    // Constructor
    Clyde(sf::Vector2i gridPos, GameState* gameState);

    // Destructor
    ~Clyde();

private:
    // Get the scatter target position for Clyde
    sf::Vector2i GetScatterTargetPosition() override;

    // Get the chase target position for Clyde
    sf::Vector2i GetChaseTargetPosition() override;

    // Setup animations for Clyde
    void SetupAnimations() override;
};
