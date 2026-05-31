#include "Game.hpp"
#include "COnstants.hpp"

Game::Game() : window(sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT), "Snake") {}

void Game::run()
{
    while (window.isOpen())
    {
        // 1. Input
        processInput();

        // 2. Update
        update();

        // 3. Renderer
        render();
    }
}

void Game::processInput()
{
    sf::Event event;
    while (window.pollEvent(event))
        if (event.type == sf::Event::Closed)
            window.close();
}

void Game::render()
{
    renderer.render(window, serpente, cibo);
}

void Game::update() {}