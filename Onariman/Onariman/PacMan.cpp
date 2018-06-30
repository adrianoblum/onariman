#include "PacMan.h"
#include "Collision.h"
#include "Principal.h"

PacMan::PacMan()
{

	Collision::CreateTextureAndBitmask(Tboneco, "Recursos/Imagens/Original_PacMan.png");

	Sboneco.setTexture(Tboneco);

	Sboneco.setOrigin(Sboneco.getGlobalBounds().width / 2, Sboneco.getGlobalBounds().height / 2);
	Sboneco.setPosition(50, 50);
	Sboneco.setScale(ESCALA_IMG, ESCALA_IMG);
//	posicao = sprite_personagem.getPosition();

	


}

void PacMan::move(float MOVX, float MOVY, float time)
{
	//Sboneco.move()
	Sboneco.move(MOVX*time, MOVY*time);

}

//void PacMan::initialize(std::string s)
//{
//
//
//}
