#pragma once
#include "Boneco.h"

class Blinky:public Boneco
{
public:
	Blinky();
	virtual ~Blinky();
	void move(float MOVX, float MOVY, float time);
};

