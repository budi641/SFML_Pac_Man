#include "AudioManager.h"

#include <iostream>

AudioManager::AudioManager()
{
    // Load sound buffers from file
    munchSoundBuffer.loadFromFile(AUDIO_MUNCH);
    powerSnackBuffer.loadFromFile(AUDIO_POWER_SNACK);
    eatGhostBuffer.loadFromFile(AUDIO_EAT_GHOST);
    deathBuffer.loadFromFile(AUDIO_DEATH_1);
    gameStartBuffer.loadFromFile(AUDIO_GAME_START);
    sirenBuffer.loadFromFile(AUDIO_SIREN);
    retreatingBuffer.loadFromFile(AUDIO_RETREATING);

    // Set the loaded sound buffers to the respective sound objects
    munchSound.setBuffer(munchSoundBuffer);
    powerSnackSound.setBuffer(powerSnackBuffer);
    eatGhostSound.setBuffer(eatGhostBuffer);
    deathSound.setBuffer(deathBuffer);
    gameStartSound.setBuffer(gameStartBuffer);
    sirenSound.setBuffer(sirenBuffer);
    retreatingSound.setBuffer(retreatingBuffer);
}

void AudioManager::PlaySound(Sounds soundType, bool loop, int volume)
{
    // Play the corresponding sound based on the sound type
    switch (soundType)
    {
    case Sounds::PowerSnack:
        powerSnackSound.setLoop(loop);
        powerSnackSound.setVolume(volume);
        powerSnackSound.play();
        break;
    case Sounds::EatGhost:
        eatGhostSound.setLoop(loop);
        eatGhostSound.setVolume(volume);
        eatGhostSound.play();
        break;
    case Sounds::Death:
        deathSound.setLoop(loop);
        deathSound.setVolume(volume);
        deathSound.play();
        break;
    case Sounds::Munch:
        munchSound.setLoop(loop);
        munchSound.setVolume(volume);
        munchSound.play();
        break;
    case Sounds::GameStart:
        gameStartSound.setLoop(loop);
        gameStartSound.setVolume(volume);
        gameStartSound.play();
        break;
    case Sounds::Siren:
        sirenSound.setLoop(loop);
        sirenSound.setVolume(volume);
        sirenSound.play();
        break;
    case Sounds::Retreating:
        retreatingSound.setLoop(loop);
        retreatingSound.setVolume(volume);
        retreatingSound.play();
        break;
    }
}

void AudioManager::StopSound(Sounds soundType)
{
    // Stop the corresponding sound based on the sound type
    switch (soundType)
    {
    case Sounds::PowerSnack:
        powerSnackSound.stop();
        break;
    case Sounds::EatGhost:
        eatGhostSound.stop();
        break;
    case Sounds::Death:
        deathSound.stop();
        break;
    case Sounds::Munch:
        munchSound.stop();
        break;
    case Sounds::GameStart:
        gameStartSound.stop();
        break;
    case Sounds::Siren:
        sirenSound.stop();
        break;
    case Sounds::Retreating:
        retreatingSound.stop();
        break;
    case Sounds::None:
        // Stop all sounds if the sound type is "None"
        gameStartSound.stop();
        munchSound.stop();
        deathSound.stop();
        eatGhostSound.stop();
        powerSnackSound.stop();
        sirenSound.stop();
        retreatingSound.stop();
        break;
    }
}

bool AudioManager::IsPlayingAudio(Sounds soundType)
{
    // Check if the corresponding sound is currently playing based on the sound type
    switch (soundType)
    {
    case Sounds::PowerSnack:
        return powerSnackSound.getStatus() == powerSnackSound.Playing;
        break;
    case Sounds::EatGhost:
        return eatGhostSound.getStatus() == eatGhostSound.Playing;
        break;
    case Sounds::Death:
        return deathSound.getStatus() == deathSound.Playing;
        break;
    case Sounds::Munch:
        return munchSound.getStatus() == munchSound.Playing;
        break;
    case Sounds::GameStart:
        return gameStartSound.getStatus() == gameStartSound.Playing;
        break;
    case Sounds::Siren:
        return sirenSound.getStatus() == sirenSound.Playing;
        break;
    case Sounds::Retreating:
        return retreatingSound.getStatus() == retreatingSound.Playing;
        break;
    }
}
