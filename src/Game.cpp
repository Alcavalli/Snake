#include "Game.hpp"

Game::Game() : window(sf::VideoMode(800, 600), "Snake") {}

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