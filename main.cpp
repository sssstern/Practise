#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include "Player.h"
#include <iostream>
#include <sstream>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 640), "MIGRANE");
	view.reset(FloatRect(0, 0, 640, 640));
	Font font;//шрифт 
	font.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/fonts/Minecraft Rus NEW.otf");
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	Image map_image;
	map_image.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/map.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	Player p("miu.png", 62, 704, 25, 25);
	
	float CurrentFrame = 0;
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 600;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left))|| (Keyboard::isKeyPressed(Keyboard::A))) {
			p.dir = 1; p.speed = 0.1;
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 30, 32, 32));
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right))|| (Keyboard::isKeyPressed(Keyboard::D))) {
			p.dir = 0; p.speed = 0.1;
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 30, 32, 32));
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W))) {
			p.dir = 3; p.speed = 0.1;
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 90, 32, 32));// 
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S))) {
			p.dir = 2; p.speed = 0.1;
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 0, 32, 32));
		}
		getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		p.update(time);
		window.setView(view);
		window.clear();
		/////////////////////////////Рисуем карту/////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(64, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(32, 0, 32, 32));
				s_map.setPosition(j * 32, i * 32);
				window.draw(s_map);
			}
		std::ostringstream playerScoreString;    // объявили переменную
		playerScoreString << p.playerScore;		//занесли в нее число очков, то есть формируем строку
		text.setString("miu" + playerScoreString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		text.setPosition(view.getCenter().x - 165, view.getCenter().y - 200);//задаем позицию текста, отступая от центра камеры
		window.draw(text);//рисую этот текст
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}