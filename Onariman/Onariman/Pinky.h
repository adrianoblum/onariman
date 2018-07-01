#pragma once
#include "Boneco.h"
class Pinky:public Boneco
{
public:
	Pinky();
	virtual ~Pinky();
	void move(float MOVX, float MOVY, float time);
};

