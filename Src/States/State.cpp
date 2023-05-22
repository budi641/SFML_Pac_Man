#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states, GameManager* gameManager)
{
	this->window = window;
	this->states = states;
	this->gameManager = gameManager;
	this->quit = false;
}

// Getter for the quit flag
const bool& State::GetQuit() const
{
	return this->quit;
}

// Sets the quit flag to true, indicating the state should end
void State::EndState()
{
	this->quit = true;
}
