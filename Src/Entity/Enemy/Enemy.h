#pragma once

#include "../Entity.h"
#include "../../Animation/Animator.h"
#include "../../Animation/Animation.h"
#include "../../Audio/AudioManager.h"

// Enum class for enemy states
enum class EnemyState {
    Scatter,
    Chase,
    Frightened,
    Eaten_FreezedGame,
    Eaten_Retreating
};

// Enemy class derived from Entity class
class Enemy : public Entity
{
public:
    // Current state of the enemy
    EnemyState state = EnemyState::Scatter;

    // Constructor
    Enemy(sf::Vector2i gridPos, sf::Vector2i texturePos, GameState* gameState, Entities entityType);

    // Destructor
    ~Enemy();

    // Set the enemy in a scared state
    void Scare();

    // Update the tile array based on the new position
    void UpdateTileArray(sf::Vector2i newPos) override;

    // Update the enemy logic
    void Update(const float& deltaTime) override;

    // Draw the enemy
    void Draw(sf::RenderWindow& rw) override;

    // Handle the enemy being eaten
    void Eaten();

private:
    int currentWave = 0;
    float totalWaveTime = 0;
    float scaredTimer = 0;
    bool hasStartedflickeringAnim = false;
    AudioManager audio;
    std::vector<sf::Vector2i> currentPath;

    // Structure to define waves of enemy states
    struct Wave {
        EnemyState waveState;
        float duration;
        Wave(EnemyState s, float d) { waveState = s; duration = d; }
    };

    // Array of waves
    Wave waves[8] = {
        Wave(EnemyState::Scatter, 7),
        Wave(EnemyState::Chase, 20),
        Wave(EnemyState::Scatter, 7),
        Wave(EnemyState::Chase, 20),
        Wave(EnemyState::Scatter, 5),
        Wave(EnemyState::Chase, 20),
        Wave(EnemyState::Scatter, 5),
        Wave(EnemyState::Chase, -1)
    };

    // Update the enemy's tile position
    void UpdateEnemyTilePosition();

    // Change the animation of the enemy
    void ChangeAnimation();

    // Get the position of the neighbor in the opposite direction
    sf::Vector2i GetOppositeDirectionNeighbour();

    // Move the enemy based on delta time
    void Move(const float& deltaTime) override;

protected:
    Animator* animator;
    Animation* animations[6]; //left, right, up, down, frightened, flickeringFrightened

    // Setup animations for the enemy
    virtual void SetupAnimations();

    // Get the scatter target position for the enemy
    virtual sf::Vector2i GetScatterTargetPosition();

    // Get the chase target position for the enemy
    virtual sf::Vector2i GetChaseTargetPosition();

    // Get the frightened target position for the enemy
    virtual sf::Vector2i GetFrightenedTargetPosition();
};
