#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

void Preview(RenderWindow& window) {
	bool isPreview = 1;

	while (isPreview)
	{
		window.clear(sf::Color::Black);

		sf::Text Text;
		Text.setString("you've been wondering here \n for too long\n find the way out \n unless it's too late...\n\n\n\n\n\n\n\n\n press 'tab' to start");
		Text.setCharacterSize(25);
		Font font;
		font.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/fonts/Minecraft Rus NEW.otf");
		Text.setFont(font);
		Text.setColor(sf::Color::White);
		Text.setPosition(80, 170);
		window.draw(Text);

		if (Keyboard::isKeyPressed(Keyboard::Tab))
		{
			isPreview = false;

		}
		window.display();
	}
}