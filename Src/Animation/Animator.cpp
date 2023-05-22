#include "Animator.h"

Animator::Animator(sf::RectangleShape* body)
{
	this->body = body;
}

void Animator::SetAnimationClip(Animation* anim)
{
	// Reset the total time
	totalTime = 0;

	// Reset the current animation clip if it exists
	if (currentClip != NULL)
		currentClip->Reset();

	// Set the new animation clip
	currentClip = anim;
}

void Animator::Update(float deltaTime)
{
	// Increment the total time by the elapsed time
	totalTime += deltaTime;

	// Check if there is a current animation clip
	if (currentClip != NULL)
	{
		// Check if enough time has passed to switch to the next frame
		if (totalTime >= currentClip->switchTime)
		{
			// Subtract the switch time from the total time
			totalTime -= currentClip->switchTime;

			// Get the next texture from the animation clip
			sf::Texture* t = currentClip->GetTexture();

			// Set the texture of the body to the new texture
			if (t != NULL)
				body->setTexture(t);
		}
	}
}
