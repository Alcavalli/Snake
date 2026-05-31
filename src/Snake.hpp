#pragma once

#include <deque>
#include <SFML/Graphics.hpp>

enum class Direzione
{
    Su = 0,
    Giu = 3,            // senza accento per evitare possibili errori
    Destra = 1,
    Sinistra = 2
};

class Snake
{
    private:
        std::deque<sf::Vector2i> corpo;
        Direzione dir = Direzione::Destra;      // per buona prassi meglio non avere valori spazzatura
    public:
        Snake();
        void cambiaDir(Direzione nuova_dir);
        void aggiornaCorpo();
        const std::deque<sf::Vector2i>& getCorpo() const;       // il primo const indica che la deque restituita non può essere modifica, il secondo assicura che nel metodo non venga modificato alcun elemento della classe Snake (buona prassi per tutti i getter)
};