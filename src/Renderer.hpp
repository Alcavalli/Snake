#pragma once

#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Food.hpp"

class Renderer
{
    public:
        void render(sf::RenderWindow& window, const Snake& serpente, const Food& cibo);      // aggiorna ogni volta la finestra, ci serve passare anche il serpente e il cibo
        sf::Vector2f toPixel(const sf::Vector2i& cella) const;       // pixel converter
};