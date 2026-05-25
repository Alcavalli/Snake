#pragma once

#include <SFML/Graphics.hpp>
#include "Renderer.hpp"

class Game
{
    private:
        sf::RenderWindow window;        // parametro della finestra
        Renderer renderer;              // oggetto di renderer
        Game();
        void processInput();            // riceve l'input
        void update();                  // aggiorna la logica di gioco
        void render();                  // aggiorna la renderer
    public:
        void run();                     // fa girare il gioco
};