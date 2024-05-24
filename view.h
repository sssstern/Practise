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