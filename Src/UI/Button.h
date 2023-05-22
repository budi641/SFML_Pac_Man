#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include "SFML\System.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

// Button states enumeration
enum button_states {
    BTN_IDLE = 0,       // Button is idle (not interacted with)
    BTN_HOVER,          // Button is being hovered over
    BTN_ACTIVE          // Button is being clicked/activated
};

class Button
{
private:
    short unsigned buttonState;     // Current state of the button

    sf::RectangleShape shape;       // Shape of the button
    sf::Font font;                  // Font for the button text
    sf::Text text;                  // Text displayed on the button

    sf::Color textIdleColor;        // Color of the text when the button is idle
    sf::Color textHoverColor;       // Color of the text when the button is being hovered over
    sf::Color textActiveColor;      // Color of the text when the button is being clicked/activated

public:
    Button(float x, float y, float width, float height,
        std::string text, unsigned character_size,
        sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color);
    ~Button();

    // Accessor to check if the button is pressed
    const bool isPressed() const;

    // Update the button based on the mouse position
    void update(const sf::Vector2f mousePos);

    // Render the button to the target window
    void render(sf::RenderWindow* target);
};
