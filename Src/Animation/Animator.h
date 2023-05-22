#pragma once

#include "Animation.h"
#include <SFML/Graphics.hpp>

class Animator
{
public:
    Animator(sf::RectangleShape* body);
    // Constructor that takes a pointer to a RectangleShape representing the animated body

    void SetAnimationClip(Animation* anim);
    // Sets the current animation clip to play

    void Update(float deltaTime);
    // Updates the animator and progresses the animation

private:
    Animation* currentClip;
    // Pointer to the current animation clip being played

    sf::RectangleShape* body;
    // Pointer to the RectangleShape representing the animated body

    float totalTime;
    // Total time elapsed since the start of the animation clip
};
