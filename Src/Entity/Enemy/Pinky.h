#pragma once

#include "Enemy.h"

// Pinky class derived from Enemy class
class Pinky : public Enemy
{
public:
    // Constructor
    Pinky(sf::Vector2i gridPos, GameState* gameState);

    // Destructor
    ~Pinky();

private:
    // Get the chase target position for Pinky
    sf::Vector2i GetChaseTargetPosition() override;

    // Setup animations for Pinky
    void SetupAnimations() override;
};
