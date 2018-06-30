#include "Posicionador.h"
#include "Principal.h"
#include "Collision.h"

Posicionador::Posicionador()
{

	Collision::CreateTextureAndBitmask(Tboneco, "Recursos/Imagens/teste2.png");

	Sboneco.setTexture(Tboneco);


	Sboneco.setOrigin(90, 90);
	Sboneco.setPosition(50, 50);
	Sboneco.setScale(ESCALA_IMG, ESCALA_IMG);


}
