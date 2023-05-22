#pragma once
#include "../Common.h"

// Forward declaration of GameState class
class GameState;

// Enum for directions
enum Directions {
    Up,
    Down,
    Left,
    Right,
    None
};

// Enum class for entity types
enum class Entities {
    NotDefined,
    Pacman,
    Blinky,
    Clyde,
    Inky,
    Pinky,
};

// Base Entity class
class Entity
{
public:
    // Constructor
    Entity(GameState* gameState, Entities entityType);

    // Speed of the entity
    float speed = 140;

    // Position on the grid
    sf::Vector2i gridPos;

    // Current direction of movement
    Directions currentDir = Directions::None;

    // Type of entity
    Entities entityType;

    // Body shape of the entity
    sf::RectangleShape body;

    // Texture of the entity
    sf::Texture texture;

    // Pure virtual function for updating entity logic
    virtual void Update(const float& deltaTime) = 0;

    // Pure virtual function for drawing entity
    virtual void Draw(sf::RenderWindow& rw) = 0;

protected:
    // Pointer to the GameState object
    GameState* gameState;

    // Get the final position on the grid
    sf::Vector2f GetFinalTilePosition();

    // Check if a neighboring tile is available for movement
    bool IsNeighbourTileAvailable(Directions dir);

    // Check if the current tile is a teleport tile
    bool IsTeleportTile(sf::Vector2i pos);

    // Teleport the entity to the specified direction
    void Teleport(Directions teleportTo);

    // Pure virtual function for updating the tile array
    virtual void UpdateTileArray(sf::Vector2i newPos) = 0;

    // Move the entity based on delta time
    virtual void Move(const float& deltaTime) = 0;
};

// Get the opposite direction of the given direction
Directions GetOppositeDirection(Directions dir);
