#pragma once
#include "Boneco.h"
#include "Collision.h"
#include "Posicionador.h"


class Principal;

class PacMan:public Boneco
{
private:

	Posicionador posPacman;
	bool primeira_colisao;

public:

	PacMan();
	PacMan(std::string s);
	void move(float MOVX, float MOVY, float time);
	bool testaBuffer(Principal* main);
	void analisaMovimento(Principal* main);

	void initialize(std::string s);
};
