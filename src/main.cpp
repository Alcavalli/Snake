#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Titolo");

    while (window.isOpen())
    {
        // 1. Input
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        // 2. Update
        // logica gioco

        // 3. Render
        window.clear();
        // disegna cose
        window.display();
    }

    return 0;
}