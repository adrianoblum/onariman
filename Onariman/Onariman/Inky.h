#pragma once
#include "Boneco.h"

class Inky :public Boneco
{
public:
	Inky();
	virtual ~Inky();
	void move(float MOVX, float MOVY, float time);
};

