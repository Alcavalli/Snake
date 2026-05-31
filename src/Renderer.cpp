#include "Renderer.hpp"
#include "Constants.hpp"

sf::Vector2f Renderer::toPixel(const sf::Vector2i& cella) const
{
    return sf::Vector2f(static_cast<float>(cella.x) * Constants::CELL_SIZE, static_cast<float>(cella.y) * Constants::CELL_SIZE);
}

void Renderer::render(sf::RenderWindow& window, const Snake& serpente, const Food& cibo)
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
    cella.setFillColor(sf::Color(6, 147, 0));
    for (const auto& cella_serpente : serpente.getCorpo())
    {    
        cella.setPosition(toPixel(cella_serpente));      // inserisco ciascuna cella del serpente
        window.draw(cella);
    }

    // 3. Mostrare il frame
    window.display();
}