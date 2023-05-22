#pragma once

#include "SFML/Audio.hpp"
#include "AudioAssets.h"

// AudioManager class responsible for managing game audio
class AudioManager
{
public:
    AudioManager();

    // Play a sound with the specified sound type, loop, and volume
    void PlaySound(Sounds soundType, bool loop, int volume);

    // Stop playing the sound with the specified sound type, or stop all sounds if no sound type is provided
    void StopSound(Sounds soundType = Sounds::None);

    // Check if a sound with the specified sound type is currently playing
    bool IsPlayingAudio(Sounds soundType);

private:
    // Sound buffers
    sf::SoundBuffer gameStartBuffer;
    sf::SoundBuffer munchSoundBuffer;
    sf::SoundBuffer powerSnackBuffer;
    sf::SoundBuffer eatGhostBuffer;
    sf::SoundBuffer deathBuffer;
    sf::SoundBuffer sirenBuffer;
    sf::SoundBuffer retreatingBuffer;

    // Sound objects
    sf::Sound gameStartSound;
    sf::Sound munchSound;
    sf::Sound powerSnackSound;
    sf::Sound eatGhostSound;
    sf::Sound deathSound;
    sf::Sound sirenSound;
    sf::Sound retreatingSound;
};
