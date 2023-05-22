#include "Button.h"

Button::Button(float x, float y, float width, float height,
	std::string text, unsigned character_size,
	sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color)
{
	this->buttonState = BTN_IDLE;

	// Set up button shape
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(sf::Color::Transparent);

	// Set up button text
	font.loadFromFile("Fonts/Dosis-Light.ttf");
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setFillColor(text_idle_color);
	this->text.setCharacterSize(character_size);
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 1.5f
	);

	// Set up color states
	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;
}

Button::~Button()
{

}

const bool Button::isPressed() const
{
	// Check if button is in active state
	if (this->buttonState == BTN_ACTIVE)
		return true;

	return false;
}

void Button::update(const sf::Vector2f mousePos)
{
	// Set button state to idle by default
	this->buttonState = BTN_IDLE;

	// Check if mouse is hovering over the button
	if (this->shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = BTN_HOVER;

		// Check if left mouse button is pressed
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	// Update text color based on button state
	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->text.setFillColor(this->textIdleColor);
		break;

	case BTN_HOVER:
		this->text.setFillColor(this->textHoverColor);
		break;

	case BTN_ACTIVE:
		this->text.setFillColor(this->textActiveColor);
		break;

	default:
		// Set default color for unexpected state (Red for shape, Blue for text)
		this->shape.setFillColor(sf::Color::Red);
		this->text.setFillColor(sf::Color::Blue);
		break;
	}
}

void Button::render(sf::RenderWindow* target)
{
	// Draw the button shape and text
	target->draw(this->shape);
	target->draw(this->text);
}
