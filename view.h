#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
sf::View view;
void getplayercoordinateforview(float x, float y) { 
	float tempX = x; float tempY = y;
	if (x < 320) tempX = 320;
	if (x > 480) tempX = 480;
	if (y < 320) tempY = 320;
	if (y > 480) tempY = 480;	
	view.setCenter(tempX, tempY); 
}
void viewmap(float time) { 
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		view.move(0.1 * time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		view.move(0, 0.1 * time);
	}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		view.move(-0.1 * time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		view.move(0, -0.1 * time);
	}
}
