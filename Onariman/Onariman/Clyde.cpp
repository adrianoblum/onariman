#include "Clyde.h"
#include "Collision.h"
#include "Principal.h"

Clyde::Clyde()
{
	Collision::CreateTextureAndBitmask(Tboneco, "Recursos/Imagens/clyde.png");

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


Clyde::~Clyde()
{
}

void Clyde::move(float MOVX, float MOVY, float time) {
	bool primeira = true;
	Sboneco.move(MOVX, 0);
	if (!posPacman.colidiu(SMapaBackground, 50)) {
		primeira = true;
		sprite_clyde.move(movxclyde, 0);
	}
	else {
		int i = rand() % 4 + 1;
		switch (i)
		{
		case 1:
			sprite_clyde.move(movxclyde, 0);
			break;
		case 2:
			sprite_clyde.move(0, movyclyde);
			break;
		case 3:
			sprite_clyde.move(0, -movyclyde);
			break;
		case 4:
			sprite_clyde.move(-movxclyde, 0);
			break;
		default:
			break;
		}

	}


}