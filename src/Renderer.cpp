#include "Renderer.hpp"
#include "Constants.hpp"

Renderer::Renderer()
{
    font.loadFromFile("assets/font.ttf");              // carica il file

    testo_end.setFont(font);
    testo_end.setString("GAME OVER");
    testo_end.setCharacterSize(60);
    testo_end.setFillColor(sf::Color::Red);
    sf::FloatRect bounds_end = testo_end.getLocalBounds();
    testo_end.setOrigin(bounds_end.left + bounds_end.width / 2.f, bounds_end.top + bounds_end.height / 2.f);
    testo_end.setPosition(Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f);

    testo_restart.setFont(font);
    testo_restart.setString("Premere un tasto per ricominciare...");
    testo_restart.setCharacterSize(25);
    testo_restart.setFillColor(sf::Color::White);
    sf::FloatRect bounds_restart = testo_restart.getLocalBounds();
    testo_restart.setOrigin(bounds_restart.left + bounds_restart.width / 2.f, bounds_restart.top + bounds_restart.height / 2.f);
    testo_restart.setPosition(Constants::WINDOW_WIDTH / 2.f, Constants::WINDOW_HEIGHT / 2.f + 50.f);
}

sf::Vector2f Renderer::toPixel(const sf::Vector2i& cella) const
{
    return sf::Vector2f(static_cast<float>(cella.x) * Constants::CELL_SIZE, static_cast<float>(cella.y) * Constants::CELL_SIZE);
}

void Renderer::render(sf::RenderWindow& window, const Snake& serpente, const Food& cibo, const StatoGioco& stato)
{
    // 1. Pulire la finestra
    window.clear();

    // 2. Disegnare gli elementi
    sf::RectangleShape cella;           // crea un rettangolo
    cella.setSize(sf::Vector2f(static_cast<float>(Constants::CELL_SIZE), static_cast<float>(Constants::CELL_SIZE)));        // diamo le dimensioni in float
    
    // Disegnare il terreno di gioco
    for (int i{}; i < Constants::ROWS; ++i)
    {
        for (int j{}; j < Constants::COLS; ++j)
        {
            if ((i + j) % 2)     cella.setFillColor(sf::Color(18, 160, 215));
            else        cella.setFillColor(sf::Color(135, 224, 224));
            cella.setPosition(toPixel({j,i}));
            window.draw(cella);
        }
    }

    // Disegnare il cibo
    cella.setFillColor(sf::Color(215, 5, 0));
    cella.setPosition(toPixel(cibo.getPosizione()));
    window.draw(cella);

    // Disegnare il serpente
    cella.setFillColor(sf::Color(0, 150, 0));
    for (const auto& cella_serpente : serpente.getCorpo())
    {    
        cella.setPosition(toPixel(cella_serpente));      // inserisco ciascuna cella del serpente
        window.draw(cella);
    }
    cella.setFillColor(sf::Color(0, 125, 0));
    cella.setPosition(toPixel(serpente.getCorpo().back()));
    window.draw(cella);

    if (stato == StatoGioco::GameOver)
    {
        window.draw(testo_end);
        window.draw(testo_restart);
    }

    // 3. Mostrare il frame
    window.display();
}