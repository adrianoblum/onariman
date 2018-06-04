#pragma once
#include "Texturas.h"
#include "Ponto.h"



#define ESCALA_IMG 0.18f
#define ESCALA_MAPA (ESCALA_IMG*6.818181f)
#define MOV_SPEED (ESCALA_IMG*1363.636363f)
#define FATOR (ESCALA_IMG*9.090909)

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
	void rotacao(int, int);
private:
	Texturas temp;
	sf::Sprite sprite_personagem;
	sf::Texture textura_personagem;
	sf::Sprite testeboca;
	sf::Texture testebocat;
	sf::Vector2f posicao;
	sf::Font font;
	sf::Text menu[3];

	sf::Sprite testeonaris;
	sf::Texture testeonarit;
	sf::Sprite testemask;
	sf::Texture testemaskt;

	int bufferMOVX;
	int bufferMOVY;
	int MOVX;
	int MOVY;

};

