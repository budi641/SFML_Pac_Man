#pragma once

#include "../../Common.h"
#include "../Entity.h"
#include "../../Animation/Animator.h"
#include "../../Animation/Animation.h"

// Snack class derived from Entity class
class Snack : public Entity {
public:
    // Enumeration for snack types
    enum SnackType { SmallSnack, BigSnack };

    // Type of the snack
    SnackType snackType;

    // Constructor
    Snack(SnackType type, sf::Vector2i gridPos, GameState* gameState);

    // Update the tile array based on the new position
    void UpdateTileArray(sf::Vector2i newPos) {};

    // Move the snack based on delta time
    void Move(const float& deltaTime) override {};

    // Update the snack logic
    void Update(const float& deltaTime) override;

    // Draw the snack
    void Draw(sf::RenderWindow& rw) override;

private:
    // Animator object for the snack
    Animator* animator;

    // Animation object for the big snack flickering
    Animation* bigSnackFlickerAnimation;

    // Setup animations for the snack
    void SetupAnimation();
};
