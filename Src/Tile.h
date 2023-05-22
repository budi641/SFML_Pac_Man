#pragma once

struct sTile {
    // Enumeration for different types of tiles
    enum TileType { None, Wall, Ghost, GhostHouse, Player, Snack };

    // Flag indicating whether the tile is empty
    bool isEmpty = true;

    // Vector to store the types of the tile
    std::vector<TileType> tileTypes;

    // Calculates the distance between two tiles based on their positions
    static int GetDistanceBetweenTiles(sf::Vector2i a, sf::Vector2i b)
    {
        return std::sqrt(std::pow(a.x - b.x, 2) +
            std::pow(a.y - b.y, 2) * 1.0);
    }

    // Checks if the tile has a specific type
    bool DoesTileHaveType(TileType type) {
        for (TileType t : tileTypes)
        {
            if (type == t) return true;
        }
        return false;
    }

    // Checks if the tile has only a specific type
    bool DoesTileHaveOnlyType(TileType type) {
        if (tileTypes.size() == 1) {
            if (tileTypes[0] == Wall) return true;
        }
        return false;
    }

    // Removes a specific type from the tile's types
    void EraseTileType(TileType type) {
        for (int i = 0; i < tileTypes.size(); i++) {
            if (tileTypes[i] == type)
                tileTypes.erase(tileTypes.begin() + i);
        }
    }
};
