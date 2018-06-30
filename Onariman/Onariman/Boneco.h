#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "Animacao.h"


namespace sf {
	class RenderWindow;
}

class Boneco
{
public:

	float speed;
	sf::Sprite Sboneco;
	sf::Texture Tboneco;
	Animacao animacao;


public:

	void girar(int movx, int movy);
	void animation();

	sf::Sprite getSpriteBoneco(void){return Sboneco;}
	sf::Texture getTextureBoneco(void) { return Tboneco; }
	//void loadTextureBoneco(std::string s);
	void set_skin(std::string s);
	bool colidiu(sf::Sprite objeto, int alpha);
	void draw(sf::RenderWindow* janela);
	void move(float MOVX, float MOVY, float time);
	void update_animation(int row, float time);
	bool testaBuffer(float bufferMOVX, float bufferMOVY, sf::Sprite SMapaBackground);
};
