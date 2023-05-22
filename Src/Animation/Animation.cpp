#include "Animation.h"

Animation::Animation(std::vector<sf::Texture> textures)
{
	// Initialize the animation with the given textures
	this->textures = textures;
}

Animation::Animation(std::vector<sf::Texture> textures, bool loop)
{
	// Initialize the animation with the given textures and loop flag
	this->textures = textures;
	this->loop = loop;
}

Animation::Animation(std::vector<sf::Texture> textures, bool loop, float switchTime)
{
	// Initialize the animation with the given textures, loop flag, and switch time
	this->textures = textures;
	this->loop = loop;
	this->switchTime = switchTime;
}

void Animation::Reset()
{
	// Reset the animation to its initial state
	currentTexture = 0;
}

sf::Texture* Animation::GetTexture()
{
	// Get the current texture in the animation sequence

	// Get a pointer to the current texture
	sf::Texture* textToReturn = &textures[currentTexture];

	// Check if the animation has reached the end
	if (currentTexture == textures.size() - 1)
	{
		// If the animation is set to loop, reset to the first texture
		if (loop)
			currentTexture = 0;
	}
	else
	{
		// Move to the next texture in the sequence
		currentTexture++;
	}

	// Return the current texture
	return textToReturn;
}
