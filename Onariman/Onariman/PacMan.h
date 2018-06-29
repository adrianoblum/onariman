#pragma once
#include "Boneco.h"

class PacMan:public Boneco
{



public:

	PacMan();
	PacMan(std::string s);
	void move(float MOVX, float MOVY, float time);
	
	void initialize(std::string s);
};
