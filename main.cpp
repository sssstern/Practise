#include <SFML/Graphics.hpp>
#include "map.h"
#include "view.h"
#include "Preview.h"
#include "Player.h"
#include "Outro.h"
#include <iostream>
#include <sstream>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(640, 640), "MIGRAINE");
	view.reset(FloatRect(0, 0, 640, 640));
	Font font;//шрифт 
	font.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/fonts/Minecraft Rus NEW.otf");
	Text text("", font, 20);
	Image map_image;
	map_image.loadFromFile("C:/Users/Asus/source/repos/SimpleGame/images/map3.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	Player p("miu.png", 64, 704, 26, 26);
	Preview(window);

	float CurrentFrame = 0;
	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 1344;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		



		if ((Keyboard::isKeyPressed(Keyboard::Left))|| (Keyboard::isKeyPressed(Keyboard::A))) {
			p.dir = 1; p.speed = 0.32;
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 30, 32, 32));
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right))|| (Keyboard::isKeyPressed(Keyboard::D))) {
			p.dir = 0; p.speed = 0.32;
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 30, 32, 32));
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::W))) {
			p.dir = 3; p.speed = 0.32;
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 90, 32, 32)); 
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::S))) {
			p.dir = 2; p.speed = 0.32;
			CurrentFrame += 0.009 * time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
			p.sprite.setTextureRect(IntRect(30 * int(CurrentFrame), 0, 32, 32));
		}
		getplayercoordinateforview(p.getplayercoordinateX(), p.getplayercoordinateY());
		p.update(time);
		window.setView(view);
		window.clear();
		



		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(65, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(32, 0, 32, 32));
				s_map.setPosition(j * 32, i * 32);
				window.draw(s_map);
			}
		
		
		window.draw(p.sprite);
		window.display();
		if(p.playerScore==1)Outro(window);
	}
	return 1;
}