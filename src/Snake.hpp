#pragma once

#include <deque>
#include <SFML/Graphics.hpp>
#include "Enums.hpp"

class Snake
{
    private:
        std::deque<sf::Vector2i> corpo;
        Direzione dir = Direzione::Destra;      // per buona prassi meglio non avere valori spazzatura
    public:
        Snake();
        void cambiaDir(Direzione nuova_dir);
        void aggiornaCorpo();
        void cresci();
        const std::deque<sf::Vector2i>& getCorpo() const;       // il primo const indica che la deque restituita non può essere modifica, il secondo assicura che nel metodo non venga modificato alcun elemento della classe Snake (buona prassi per tutti i getter)
};