#pragma once

#include "../Common.h"
#include "../Entity/Entity.h"

// Forward declaration of the GameState class
class GameState;

// Function to find a path from startNode to endNode
std::vector<sf::Vector2i> FindPath(sf::Vector2i startNode, sf::Vector2i endNode, Directions currentDir, GameState* gameState);
