#pragma once
#include "Boneco.h"
class Clyde:public Boneco
{
public:
	Clyde();
	virtual ~Clyde();
	void move(float MOVX, float MOVY, float time);
};

