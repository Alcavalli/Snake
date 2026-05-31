#pragma once

#include <SFML/Graphics.hpp>
#include <deque>

class Food
{
    private:
        sf::Vector2i pos{0,0};
    public:
        void respawn(const std::deque<sf::Vector2i>& corpo);
        const sf::Vector2i& getPosizione() const;
};