#include "Pathfinding.h"
#include "Node.h"
#include "../Entity/Entity.h"

// Function to check if a given node is present in a list of nodes
bool IsNodeInsideList(sNode& n, std::vector<sNode>& list)
{
    for (sNode node : list)
    {
        if (node.pos == n.pos)
            return true;
    }
    return false;
}

// Function to delete a node from a list of nodes
void DeleteNodeOnList(sNode& n, std::vector<sNode>& list)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].pos == n.pos) {
            list.erase(list.begin() + i);
            break;
        }
    }
}

// Function to calculate the Manhattan distance between two nodes
int GetDistance(sNode& a, sNode& b)
{
    int disX = a.pos.x - b.pos.x;
    int disY = a.pos.y - b.pos.y;

    if (disX < 0)
        disX *= -1;
    if (disY < 0)
        disY *= -1;

    int totalDis = disX + disY;

    return totalDis;
}

// Function to find a path from the start node to the end node using the A* algorithm
std::vector<sf::Vector2i> FindPath(sf::Vector2i startNodePos, sf::Vector2i endNodePos, Directions currentDir, GameState* gameState)
{
    std::vector<sNode> openList;
    std::vector<sNode> closedList;

    sNode startNode = sNode(startNodePos, gameState);
    sNode endNode = sNode(endNodePos, gameState);
    startNode.ignoreDirection = GetOppositeDirection(currentDir);
    openList.push_back(startNode);

    bool foundPath = false;

    sNode currentNode = openList[0];
    while (!openList.empty())
    {
        // Select the node with the lowest fCost from the open list
        currentNode = openList[0];
        int i = 0;
        for (; i < openList.size(); i++)
        {
            if (openList[i].fCost() < currentNode.fCost() || (openList[i].fCost() == currentNode.fCost() && openList[i].hCost < currentNode.hCost))
            {
                currentNode = openList[i];
            }
        }

        // Move the selected node from the open list to the closed list
        DeleteNodeOnList(currentNode, openList);
        closedList.push_back(currentNode);

        // Check if the current node is the end node
        if (currentNode.pos == endNodePos)
        {
            foundPath = true;
            break;
        }

        // Generate the neighbors of the current node
        std::vector<sNode> neighbours = currentNode.GetNeighbours();
        for (sNode neighbour : neighbours)
        {
            // Skip non-walkable nodes and nodes already in the closed list
            if (!neighbour.walkable || IsNodeInsideList(neighbour, closedList))
                continue;

            // Calculate the new cost to move to the neighbor node
            int newMovementCostToNeighbour = currentNode.gCost + GetDistance(currentNode, neighbour);
            // Check if the new cost is lower than the neighbor's current cost or if the neighbor is not in the open list
            if (newMovementCostToNeighbour < neighbour.gCost || !IsNodeInsideList(neighbour, openList))
            {
                // Update the neighbor's cost and parent node
                neighbour.gCost = newMovementCostToNeighbour;
                neighbour.hCost = GetDistance(neighbour, endNode);
                neighbour.SetParent(currentNode);

                // Add the neighbor to the open list if it's not already present
                if (!IsNodeInsideList(neighbour, openList))
                    openList.push_back(neighbour);
            }
        }
    }

    // Reconstruct the path if a path was found
    if (foundPath)
    {
        std::vector<sf::Vector2i> pathPositionsList;
        while (currentNode.pos != startNode.pos)
        {
            pathPositionsList.push_back(currentNode.pos);
            currentNode = *currentNode.parent;
        }
        std::reverse(pathPositionsList.begin(), pathPositionsList.end());
        return pathPositionsList;
    }
    else
        return std::vector<sf::Vector2i>();
}
