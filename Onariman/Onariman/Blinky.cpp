#include "Blinky.h"
#include "Collision.h"
#include "Principal.h"

Blinky::Blinky()
{
	Collision::CreateTextureAndBitmask(Tboneco, "Recursos/Imagens/blinky.png");

	Sboneco.setTexture(Tboneco);

	Sboneco.setOrigin(Sboneco.getGlobalBounds().width / 2, Sboneco.getGlobalBounds().height / 2);
	Sboneco.setPosition(0, 0);
	Sboneco.setScale(ESCALA_IMG, ESCALA_IMG);
	//	posicao = sprite_personagem.getPosition();

	Collision::CreateTextureAndBitmask(Tposicionador, "Recursos/Imagens/teste2.png");

	Sposicionador.setTexture(Tposicionador);

	Sposicionador.setOrigin(Sposicionador.getGlobalBounds().height / 2, Sposicionador.getGlobalBounds().width / 2);
	Sposicionador.setPosition(0, 0);
	Sposicionador.setScale(ESCALA_IMG, ESCALA_IMG);
}


Blinky::~Blinky()
{
}

void Blinky::move(float MOVX, float MOVY, float time){	Sboneco.move(MOVX*time, MOVY*time); }
