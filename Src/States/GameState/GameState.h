#pragma once

#include "../State.h"               // Include the base State class
#include "../../Tile.h"              // Include the Tile class
#include "../../Entity/Snack/Snack.h" // Include the Snack class
#include "../../Audio/AudioManager.h" // Include the AudioManager class

// Forward declarations
class Enemy;
class Pacman;

// Number of tiles in the game grid
#define NumberOfTilesX 28
#define NumberOfTilesY 31

// GameState class derived from State class
class GameState : public State
{
public:
    Pacman* pacman;                            // Pointer to the Pacman object
    Enemy* enemys[4];                          // Array of pointers to Enemy objects

    sTile tileArray[NumberOfTilesX][NumberOfTilesY];    // 2D array of tiles representing the game grid
    std::vector<Snack*> SnackList;             // List of snack objects
    sf::Sprite mapSprite;                      // Sprite for the game map
    sf::Texture mapTexture;                    // Texture for the game map

    sf::Sprite readyTextSprite;                // Sprite for the "Ready!" text
    sf::Texture readyTextTexture;              // Texture for the "Ready!" text

    sf::Sprite gameOverTextSprite;             // Sprite for the "Game Over" text
    sf::Texture gameOverTextTexture;           // Texture for the "Game Over" text

    AudioManager audioManager;                 // AudioManager object for handling audio

    int score = 0;                             // Current score

    float tileWidth = 800 / (float)NumberOfTilesX;    // Width of each tile
    float tileHeight = 800 / (float)NumberOfTilesY;   // Height of each tile

    bool isPacmanDead = false;                 // Flag indicating whether Pacman is dead
    bool powerSnackActive = false;             // Flag indicating whether a power snack is active

    // Constructor
    GameState(sf::RenderWindow* window, std::stack<State*>* states, GameManager* gameManager);

    // Destructor
    ~GameState();

    // Update the game state logic
    void Update(const float& deltaTime);

    // Draw the game state
    void Draw();

    // Perform actions when Pacman dies
    void OnPacmanDeath();

    // Find the ID of the snack at the given position
    int FindSnackID(sf::Vector2i snackPos);

    // Delete the snack at the given position
    void DeleteSnack(sf::Vector2i snackPos);

    // Activate the power snack and scare the enemies
    void ScareEnemys();

    // Freeze the game, except for the specified entity
    void FreezeGame(Entities entityThatWontFreeze);

    // Unfreeze the game
    void UnfreezeGame();

    // Stop the power snack sound
    void StopPowerSnackSound();

    // Find the enemy at the given position
    Enemy* FindEnemyByPosition(sf::Vector2i pos);

private:
    int lifes = 3;                            // Remaining lives of the player

    bool isFreezed = false;                   // Flag indicating whether the game is frozen
    bool gameHasStarted = false;              // Flag indicating whether the game has started
    Entities entityThatWontFreeze = Entities::NotDefined;   // Entity that won't be frozen during game freeze

    sf::Font font;                            // Font for the UI text
    sf::Text scoreText;                       // Text displaying the score
    sf::Text lifesText;                       // Text displaying the remaining lives

    // Restart the game
    void Restart();

    // Load textures for the game objects
    void LoadTextures();

    // Create colliders and snacks for the game map
    void CreateMapCollidersAndSnacks();

    // Clear the tile array
    void EmptyTileArray();

    // Create Pacman and enemies
    void CreatePacmanAndEnemys();

    // Create UI elements
    void CreateUI();

    // Update the UI elements
    void UpdateUI();

    // Delete all snacks
    void DeleteSnacks();
};
