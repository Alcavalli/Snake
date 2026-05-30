#include "Snake.hpp"

const std::deque<sf::Vector2i>& Snake::getCorpo() const { return corpo; }

void Snake::cambiaDir(Direzione nuova_dir) { this->dir = nuova_dir; }

void Snake::aggiornaCorpo()
{

}