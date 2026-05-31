#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include <random>

class Food
{
    private:
        sf::Vector2i posizione{};
        std::mt19937 rng;               // generatore numero casuale
        std::uniform_int_distribution<int> num_x;       // range numeri per la coord x
        std::uniform_int_distribution<int> num_y;       // range numeri per la coord y
    public:
        Food();
        void respawn(const std::deque<sf::Vector2i>& corpo);
        const sf::Vector2i& getPosizione() const;
};