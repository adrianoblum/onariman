#pragma once
#include "Menu.h"
#define NUM_OPTIONS 2
class Pause :public Menu
{
private:
	

public:
	Pause(int width, int height);
	void selection(sf::RenderWindow* window);
	void draw(sf::RenderWindow* window);
	void setDim(int w, int h);
};
