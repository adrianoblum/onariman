#include "Boneco.h"
#include "Principal.h"
#include "Collision.h"

void Boneco::girar(int movx,int movy)
{
	
	if (movy<0)
	{
		Sboneco.setRotation(270);
		Sboneco.setScale({ -ESCALA_IMG, ESCALA_IMG });
		

	}
	else if (movy>0)
	{

		Sboneco.setRotation(90);
		Sboneco.setScale({ -ESCALA_IMG, ESCALA_IMG });
		

	}
	else if (movx>0)
	{
		Sboneco.setRotation(0);
		Sboneco.setScale({ -ESCALA_IMG, ESCALA_IMG });
		

	}

	else if (movx<0)
	{
		Sboneco.setRotation(0);
		Sboneco.setScale({ ESCALA_IMG, ESCALA_IMG });
		


	}
	else
	{
		//Sboneco.setRotation(0);
		//Sboneco.setScale({ -ESCALA_IMG, ESCALA_IMG });
		

	}
		


	
		




}

//void Boneco::animation()
//{
//
//
//}
//
//
//void Boneco::setSpriteBoneco(sf::Texture textura)
//{
//
//
//}

void Boneco::set_skin(std::string s)
{
	Collision::CreateTextureAndBitmask(Tboneco, s);

	Sboneco.setTexture(Tboneco);

}

bool Boneco::colidiu(sf::Sprite objeto, int alpha)
{
	
	return (Collision::PixelPerfectTest(Sboneco, objeto, alpha));

}

void Boneco::draw(sf::RenderWindow* janela)
{
	janela->draw(Sboneco);
}

void Boneco::move(float MOVX, float MOVY, float time)
{

	Sboneco.move(MOVX*time, MOVY*time);

}


