#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Food.hpp"
#include "Enums.hpp"

class Renderer
{
    private:
        sf::Font font;
        sf::Text testo;
    public:
        void render(sf::RenderWindow& window, const Snake& serpente, const Food& cibo, const StatoGioco& stato);      // aggiorna ogni volta la finestra, ci serve passare anche il serpente e il cibo
        sf::Vector2f toPixel(const sf::Vector2i& cella) const;       // pixel converter
};