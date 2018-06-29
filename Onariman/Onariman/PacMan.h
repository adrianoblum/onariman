#pragma once
#include "Boneco.h"

class PacMan:public Boneco
{



public:

	PacMan();
	PacMan(std::string s);
	void move(float MOVX, float MOVY, float time);
	bool movimentar(float MOVX, float MOVY, float bufferMOVX, float bufferMOVY, float time, sf::Sprite* SMapaBackground);
	void initialize(std::string s);
	
};
