#pragma once
class Ponto
{
public:
	Ponto();
	Ponto(int xi, int yi);
	~Ponto();
	void inc_x(int q);
	void inc_x();
	void inc_y(int q);
	void inc_y();

	void setX(int q);
	void setY(int q);
	int getX() { return x; };
	int getY() { return y; };
private:
	int x;
	int y;


};

