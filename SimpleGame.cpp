// SimpleGame.cpp: определяет точку входа для приложения.
//

#include "SimpleGame.h"

using namespace std;

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setPosition(100, 100);
    shape.setFillColor(sf::Color(200, 30, 10));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(20, 5, 5));
        window.draw(shape);
        window.display();
    }

    return 0;
}
