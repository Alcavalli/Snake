#pragma once

#include <SFML/Graphics.hpp>
#include "Renderer.hpp"
#include "Snake.hpp"
#include "Food.hpp"
#include "Enums.hpp"

class Game
{
    private:
        sf::RenderWindow window;                    // parametro della finestra
        Renderer renderer;                          // oggetto di renderer
        StatoGioco stato = StatoGioco::InCorso;     // stato del gioco
        sf::Clock clock;                            // orlogio per aggiornare i frame
        Snake serpente;                             // creazione serpente
        Food cibo;                                  // creazione cibo
        void processInput();                        // riceve l'input
        void update();                              // aggiorna la logica di gioco
        void render();                              // aggiorna la renderer
    public:
        Game();                                     // costruttore
        void run();                                 // fa girare il gioco
};