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
            if (stato == StatoGioco::GameOver)
                reset();
            if (coda_input.size() < Constants::MAX_INPUT_QUEUE)
            {
                if (event.key.code == sf::Keyboard::Up)
                    coda_input.push(Direzione::Su);
                if (event.key.code == sf::Keyboard::Down)
                    coda_input.push(Direzione::Giu);
                if (event.key.code == sf::Keyboard::Right)
                    coda_input.push(Direzione::Destra);
                if (event.key.code == sf::Keyboard::Left)
                    coda_input.push(Direzione::Sinistra);
            }
        }
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::render()
{
    renderer.render(window, serpente, cibo, stato);
}

void Game::update()
{
    if (stato == StatoGioco::GameOver)
        return;
    sf::Time elapsed = clock.getElapsedTime();      // salva quanto tempo è passato da quando è partito l'orologio
    if (elapsed.asMilliseconds() >= Constants::MOVE_INTERVAL_MS)
    {
        if (!coda_input.empty())
        {
            serpente.cambiaDir(coda_input.front());
            coda_input.pop();
        }
        if (serpente.getCorpo().back() == cibo.getPosizione())
        {
            serpente.cresci();
            cibo.respawn(serpente.getCorpo());
        }
        else
            serpente.aggiornaCorpo();
        if (serpente.getCorpo().back().x < 0 || serpente.getCorpo().back().x > Constants::COLS - 1 || serpente.getCorpo().back().y < 0 || serpente.getCorpo().back().y > Constants::ROWS - 1)
            stato = StatoGioco::GameOver;
        if (std::find(serpente.getCorpo().begin(), serpente.getCorpo().end(), serpente.getCorpo().back()) != serpente.getCorpo().end() - 1)
            stato = StatoGioco::GameOver;
        clock.restart();        // resetta l'orologio
    }
}

void Game::reset()
{
    serpente = Snake();
    cibo = Food();
    stato = StatoGioco::InCorso;
}