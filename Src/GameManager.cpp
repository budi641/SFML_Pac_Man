#include "GameManager.h"
#include "States/MainMenuState/MainMenuState.h"

// Start the game manager
void GameManager::StartGameManager()
{
    window = new sf::RenderWindow();
    window->create(sf::VideoMode(1280, 720), "Mesh_Pacman", sf::Style::Default);
    //window->create(sf::VideoMode::getFullscreenModes()[0], "Pacman", sf::Style::Resize);

    aspectRatio = float(window->getSize().x) / float(window->getSize().y - 100);
    sf::View v(sf::Vector2f(400, 450), sf::Vector2f(800 * aspectRatio, 900));
    window->setView(v);

    // Push the main menu state onto the stack
    states.push(new MainMenuState(window, &states, this));
}

GameManager::~GameManager()
{

}

void GameManager::Update()
{
    while (window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        // Get input
        sf::Event event;
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::Resized:
                aspectRatio = float(window->getSize().x) / float(window->getSize().y);
                sf::View v(sf::Vector2f(400, 450), sf::Vector2f(800 * aspectRatio, 900));
                window->setView(v);
                break;
            }
        }

        // Handle states
        if (!this->states.empty())
        {
            this->states.top()->Update(deltaTime);

            // Check if the current state wants to quit
            if (this->states.top()->GetQuit())
            {
                // End the current state
                this->states.top()->EndState();
                delete this->states.top();
                this->states.pop();
            }
        }
        // Application end
        else
        {
            this->window->close();
        }
    }
}
