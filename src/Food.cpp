#include "Food.hpp"
#include "Constants.hpp"

Food::Food() : rng(std::random_device{}()), num_x(0, Constants::COLS - 1), num_y(0, Constants::ROWS - 1)
{
    posizione = {Constants::COLS * 3 / 4, Constants::ROWS / 2};
}

const sf::Vector2i& Food::getPosizione() const { return posizione; }

void Food::respawn(const std::deque<sf::Vector2i>& corpo)
{
    sf::Vector2i temp{};
    do
    {
        temp.x = num_x(rng);
        temp.y = num_y(rng);
    } while (std::find(corpo.begin(), corpo.end(), temp) != corpo.end());
    posizione = temp;
}