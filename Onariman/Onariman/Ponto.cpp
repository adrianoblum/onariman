#include "Ponto.h"



Ponto::Ponto()
{
	x = 0;
	y = 0;
}

Ponto::Ponto(int xi, int yi)
{
	x = xi;
	y = yi;

}


Ponto::~Ponto()
{
}

void Ponto::inc_x(int q)
{

	x += q;

}

void Ponto::inc_x()
{
	x++;
}

void Ponto::inc_y(int q)
{
	y += q;
}
void Ponto::inc_y()
{
	y++;
}

void Ponto::setX(int q)
{
	x = q;
}

void Ponto::setY(int q)
{
	y = q;
}
