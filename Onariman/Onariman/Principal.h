#pragma once
#include "Texturas.h"
#include "Ponto.h"


#define MOV_SPEED 300
#define ESCALA_IMG 0.22f
#define ESCALA_MAPA 1.5f

class Principal
{
public:
	Principal();
	~Principal();
	void loop(sf::RenderWindow* janela);
	void mover_teste(sf::Time frame);
	bool testaBuffer();
	void carrega_xarater();
	void carrega_texto_temp();
private:
	Texturas temp;
	sf::Sprite sprite_personagem;
	sf::Texture textura_personagem;
	sf::Vector2f posicao;
	sf::Font font;
	sf::Text menu[3];

	sf::Sprite testeonaris;
	sf::Texture testeonarit;

	int bufferMOVX;
	int bufferMOVY;
	int MOVX;
	int MOVY;

};

