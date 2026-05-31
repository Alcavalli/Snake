#include "Game.hpp"
#include "Constants.hpp"

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
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
                serpente.cambiaDir(Direzione::Su);
            if (event.key.code == sf::Keyboard::Down)
                serpente.cambiaDir(Direzione::Giu);
            if (event.key.code == sf::Keyboard::Right)
                serpente.cambiaDir(Direzione::Destra);
            if (event.key.code == sf::Keyboard::Left)
                serpente.cambiaDir(Direzione::Sinistra);
        }
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::render()
{
    renderer.render(window, serpente, cibo);
}

void Game::update()
{
    sf::Time elapsed = clock.getElapsedTime();      // salva quanto tempo è passato da quando è partito l'orologio
    if (elapsed.asMilliseconds() >= Constants::MOVE_INTERVAL_MS)
    {
        serpente.aggiornaCorpo();       // aggiorna il corpo del serpente (lo fa muovere)
        clock.restart();        // resetta l'orologio
    }
}