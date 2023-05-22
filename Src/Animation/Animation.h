#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
public:
    float switchTime = 0.05f;
    // The time interval between switching frames of the animation

    Animation(std::vector<sf::Texture> textures);
    // Constructor that takes a vector of textures representing the frames of the animation

    Animation(std::vector<sf::Texture> textures, bool loop);
    // Constructor that takes a vector of textures and a loop flag indicating whether the animation should loop

    Animation(std::vector<sf::Texture> textures, bool loop, float switchTime);
    // Constructor that takes a vector of textures, a loop flag, and a custom switch time

    sf::Texture* GetTexture();
    // Returns a pointer to the current texture to be displayed in the animation

    void Reset();
    // Resets the animation to its initial state

private:
    bool loop = true;
    // Flag indicating whether the animation should loop

    std::vector<sf::Texture> textures;
    // Vector of textures representing the frames of the animation

    int currentTexture = 0;
    // Index of the current texture/frame being displayed
};
