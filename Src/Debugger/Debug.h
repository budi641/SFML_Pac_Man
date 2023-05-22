#pragma once

#include "../Common.h"
#include "../States/GameState/GameState.h"

// Function to draw the grid
void DrawGrid(sf::RenderWindow& window, GameState* gameState);

// Function to draw a cube at a specific position
void DrawCube(sf::RenderWindow& window, sf::Vector2i pos, GameState* gameState);

// Function to draw the pathfinding path
void DrawPathfinding(sf::RenderWindow& window, std::vector<sf::Vector2i>& path, sf::Vector2i pathStart, sf::Vector2i pathTarget, GameState* gameState);
