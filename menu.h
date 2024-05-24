#pragma once
#include <SFML/Graphics.hpp>
#include "view.h"
using namespace sf;

void menu(RenderWindow& window) {
	Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, aboutTexture, menuBackground, spritesTexture;
	menuTexture1.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/111.png");
	menuTexture2.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/222.png");
	menuTexture3.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/333.png");
	menuTexture4.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/444.png");
	aboutTexture.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/about.jpg");
	spritesTexture.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/sprites.jpg");
	menuBackground.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/background.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), about(aboutTexture), menuBg(menuBackground), sprt(spritesTexture);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(100, 30);
	menu2.setPosition(100, 90);
	menu3.setPosition(100, 200);
	menu4.setPosition(100, 150);
	menuBg.setPosition(0, 0);
	while (isMenu)
	{
		view.reset(FloatRect(0, 0, 640, 640));
		window.setView(view);
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menu4.setColor(Color::White);
		menuNum = 0;
		window.clear(Color::Black);
		if (IntRect(100, 30, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(100, 90, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(100, 200, 300, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		if (IntRect(100, 150, 300, 50).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Blue); menuNum = 4; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;
			if (menuNum == 2) { window.draw(about); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
			if (menuNum == 3) { isMenu = false; window.close(); exit(2); }
			if (menuNum == 4) { window.draw(sprt); window.display(); while (!Keyboard::isKeyPressed(Keyboard::Escape)); }
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
}
