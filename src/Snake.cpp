#include "Snake.hpp"
#include "Constants.hpp"

const std::deque<sf::Vector2i>& Snake::getCorpo() const { return corpo; }

void Snake::cambiaDir(Direzione nuova_dir) { this->dir = nuova_dir; }

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