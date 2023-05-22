#pragma once

// Define audio file paths
#define AUDIO_GAME_START "Resources/Sound/game_start.wav"
#define AUDIO_EAT_GHOST "Resources/Sound/eat_ghost.wav"
#define AUDIO_DEATH_1 "Resources/Sound/death_1.wav"
#define AUDIO_POWER_SNACK "Resources/Sound/power_pellet.wav"
#define AUDIO_MUNCH "Resources/Sound/munch.wav"
#define AUDIO_SIREN "Resources/Sound/siren_1.wav"
#define AUDIO_RETREATING "Resources/Sound/retreating.wav"

// Define default volume
#define VOLUME 50
#define VOLUME_MUNCH 10
#define VOLUME_SIREN 60

// Enum class for different sound types
enum class Sounds {
    None,           // No sound
    PowerSnack,     // Power snack sound
    EatGhost,       // Eat ghost sound
    Death,          // Death sound
    Munch,          // Munch sound
    GameStart,      // Game start sound
    Siren,          // Siren sound
    Retreating      // Retreating sound
};
