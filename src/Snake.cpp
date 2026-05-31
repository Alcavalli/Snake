#include "Snake.hpp"
#include "Constants.hpp"

Snake::Snake()
{
    corpo.push_back({Constants::COLS / 5, Constants::ROWS / 2});        // coda in (3,7) in questo caso
    corpo.push_back({Constants::COLS / 5 + 1, Constants::ROWS / 2});            // corpo in (4,7)
    corpo.push_back({Constants::COLS / 5 + 2, Constants::ROWS / 2});        // testa in (5,7)
}

const std::deque<sf::Vector2i>& Snake::getCorpo() const { return corpo; }

void Snake::cambiaDir(Direzione nuova_dir)
{
    if (static_cast<int>(this->dir) + static_cast<int>(nuova_dir) != 3)             // guardare valori enum
        this->dir = nuova_dir;
}

void Snake::aggiornaCorpo()
{
    sf::Vector2i temp = corpo.back();       // .front() = coda, .back() = testa
    switch(dir)
    {
        case Direzione::Su:
            --temp.y;           // con SFML y cresce andando verso il basso e sale verso l'alto
            break;
        case Direzione::Giu:
            ++temp.y;
            break;
        case Direzione::Destra:
            ++temp.x;
            break;
        case Direzione::Sinistra:
            --temp.x;
            break;
    }
    corpo.push_back(temp);
    corpo.pop_front();
}