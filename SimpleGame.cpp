// SimpleGame.cpp: определяет точку входа для приложения.
//

#include "SimpleGame.h"
#include "Constants.h"

using namespace std;

#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Title");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.display();
    }

    return 0;
}

