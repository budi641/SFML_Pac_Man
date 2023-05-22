#pragma once

#include "../../Common.h"
#include "../../GameManager.h"
#include "../Entity.h"
#include "../../Animation/Animation.h"
#include "../../Animation/Animator.h"
#include "../../Audio/AudioManager.h"

// Pacman class derived from Entity class
class Pacman : public Entity
{
public:
    // Constructor
    Pacman(int x, int y, GameState* gameState);

    // Destructor
    ~Pacman();

    // Update the Pacman logic
    void Update(const float& deltaTime) override;

    // Draw the Pacman
    void Draw(sf::RenderWindow& rw) override;

    // Handle Pacman's death
    void Die();

private:
    Animator* animator;
    AudioManager audio;
    Animation* animations[5]; //left, right, up, down, death
    Directions nextDir = None;
    bool hasCompletedMovement = false;
    bool isEatingSnacks = false;

    // Move the Pacman based on delta time
    void Move(const float& deltaTime) override;

    // Eat the snack at the given grid position
    void EatSnack(sf::Vector2i snackGridPosition);

    // Update the Pacman's tile position
    void UpdatePlayerTilePosition();

    // Update the tile array based on the new position
    void UpdateTileArray(sf::Vector2i newPos);

    // Setup animations for the Pacman
    void SetupAnimations();

    // Change the animation based on the direction
    void ChangeAnimation(Directions dir);
};
