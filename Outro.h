#pragma once
#include "menu.h"
#include <SFML/Graphics.hpp>
using namespace sf;

void Outro(RenderWindow& window) {
	bool isOutro = 1;

	while (isOutro)
	{
		window.clear(sf::Color::Black);

		sf::Text Text;
		Text.setString("you've done a great job\n now it's your time to take\n a good rest\n\n\n\n\n\n\n\n\n\n press 'tab' to exit...");
		Text.setCharacterSize(25);
		Font font;
		font.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/fonts/Minecraft Rus NEW.otf");
		Text.setFont(font);
		Text.setColor(sf::Color::White);
		Text.setPosition(260, 220);
		window.draw(Text);
		window.display();
		if (Keyboard::isKeyPressed(Keyboard::Tab))
		{
			isOutro = false;
			window.close();

		}
		
	}
}