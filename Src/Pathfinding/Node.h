#pragma once

#include "../States/GameState/GameState.h"
#include "../Entity/Entity.h"

// Structure representing a node in the pathfinding grid
struct sNode
{
	sNode* parent;                  // Pointer to the parent node
	GameState* gameState;           // Pointer to the game state
	Directions ignoreDirection;     // Direction to ignore when generating neighbors
	sf::Vector2i pos;               // Position of the node in the grid

	int gCost = 0;                  // Cost from the start node to this node
	int hCost = 0;                  // Heuristic cost from this node to the target node
	int fCost() { return (gCost + hCost); }    // Total cost of the node (gCost + hCost)

	bool visited = false;           // Flag indicating if the node has been visited
	bool walkable = true;           // Flag indicating if the node is walkable

	// Constructor
	sNode(sf::Vector2i pos, GameState* gameState) { this->pos = pos; this->gameState = gameState; }

	// Set the parent node
	void SetParent(sNode p)
	{
		parent = new sNode(p);
	}

	// Destructor
	~sNode()
	{
		// Delete the parent node
	}

	// Get the neighboring nodes
	std::vector<sNode> GetNeighbours()
	{
		std::vector<sNode> neighbours;
		if (ignoreDirection != Left) {
			sNode left = CreateNode(sf::Vector2i(pos.x - 1, pos.y));
			if (left.pos != sf::Vector2i(-100, -100))	neighbours.push_back(left);
		}
		if (ignoreDirection != Right) {
			sNode right = CreateNode(sf::Vector2i(pos.x + 1, pos.y));
			if (right.pos != sf::Vector2i(-100, -100))	neighbours.push_back(right);
		}
		if (ignoreDirection != Up) {
			sNode up = CreateNode(sf::Vector2i(pos.x, pos.y - 1));
			if (up.pos != sf::Vector2i(-100, -100))	neighbours.push_back(up);
		}
		if (ignoreDirection != Down) {
			sNode down = CreateNode(sf::Vector2i(pos.x, pos.y + 1));
			if (down.pos != sf::Vector2i(-100, -100))	neighbours.push_back(down);
		}

		return neighbours;
	}

	// Create a node at the specified position
	sNode CreateNode(sf::Vector2i pos)
	{
		sTile* tile = &gameState->tileArray[pos.x][pos.y];
		sNode node = sNode(pos, gameState);
		if (tile != NULL) {

			if (pos.x < 0 || pos.y < 0 || pos.x >= NumberOfTilesX || pos.y >= NumberOfTilesY)
				return sNode(sf::Vector2i(-100, -100), gameState);

			if (tile->DoesTileHaveOnlyType(sTile::Wall))
				node.walkable = false;
			else
				node.walkable = true;

			return node;
		}
		return sNode(sf::Vector2i(-100, -100), gameState);
	}
};
