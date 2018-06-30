#include "PacMan.h"
#include "Principal.h"
#include "Posicionador.h"
#include <iostream>

PacMan::PacMan()
{

	Collision::CreateTextureAndBitmask(Tboneco, "Recursos/Imagens/Original_PacMan.png");

	Sboneco.setTexture(Tboneco);

	Sboneco.setOrigin(Sboneco.getGlobalBounds().width / 2, Sboneco.getGlobalBounds().height / 2);
	Sboneco.setPosition(50, 50);
	Sboneco.setScale(ESCALA_IMG, ESCALA_IMG);
//	posicao = sprite_personagem.getPosition();
	primeira_colisao = false;
	


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

bool PacMan::testaBuffer(Principal* main)
{
	bool podeounao = true;
	float movx = static_cast<float>(*main->getBufferX() / 60);
	float movy = static_cast<float>(*main->getBufferY() / 60);
	main->getPacMan()->girar(movx, movy);
	posPacman.girar(movx, movy);
	//rotacao(movx, movy);
	posPacman.move(movx * 4, movy * 4, 1);

	//testeboca.move(movx*4, movy*4);
	if (posPacman.colidiu(*main->getMap(), 50))
	{
		podeounao = false;

	}
	main->getPacMan()->girar(*main->getMOVX(), *main->getMOVY());
	posPacman.girar(*main->getMOVX(), *main->getMOVY());
	posPacman.move(-movx * 4, -movy * 4, 1);

	return podeounao;



}

void PacMan::analisaMovimento(Principal* main)
{
	
	bool podeounao;
	podeounao = testaBuffer(main);
	if (podeounao)
	{

		*main->getMOVX() = *main->getBufferX();
		*main->getMOVY() = *main->getBufferY();
		//rotacao(MOVX, MOVY);
		main->getPacMan()->girar(*main->getMOVX(), *main->getMOVY());
		posPacman.girar(*main->getMOVX(), *main->getMOVY());
		
	}
	
		posPacman.move(*main->getMOVX(), *main->getMOVY(), main->getFrameTime());


		if (!Collision::PixelPerfectTest(posPacman.Sboneco, *main->getMap(), 50))
		{
			primeira_colisao = true;
			main->getPacMan()->move(*main->getMOVX(), *main->getMOVY(), main->getFrameTime());
			//posPacman.move(-MOVX, -MOVY, timePerFrame.asSeconds());
			//sprite_personagem.move(MOVX*timePerFrame.asSeconds(), MOVY*timePerFrame.asSeconds());
		}
		else
		{

			if (primeira_colisao)
			{
				posPacman.move(*main->getMOVX(), *main->getMOVY(), main->getFrameTime());
				main->getPacMan()->move(*main->getMOVX() * 2, *main->getMOVY() * 2, main->getFrameTime());
				primeira_colisao = false;
			}
			else
			{
				//if(debug_var==false)
				posPacman.move(-*main->getMOVX(), -*main->getMOVY(), main->getFrameTime());
			}
		}

	
}