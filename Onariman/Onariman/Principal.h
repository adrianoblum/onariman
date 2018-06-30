#pragma once
#include "Texturas.h"
#include "Ponto.h"
#include "Pause.h"

#include "Posicionador.h"
#include "PacMan.h"

#define SWIDTH 1680
#define SHEIGHT 1050
#define MAX_NUMBER_OF_ITEMS 3
#define ESCALA_IMG 0.18f
#define ESCALA_MAPA (ESCALA_IMG*6.818181f)
#define MOV_SPEED (ESCALA_IMG*1363.636363f)
//#define MOV_SPEED 250
#define FATOR (ESCALA_IMG*9.090909)



class Principal
{
public:
	Principal();
	~Principal();
	void loop(sf::RenderWindow* janela);
	void mover_teste(sf::Time frame);
	void carrega_texto_temp();
	void refresh_screen(sf::RenderWindow* janela);
	bool selection(sf::RenderWindow* janela);
	void draw(sf::RenderWindow* janela);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }
	int play_music();
	int fim;

		
	PacMan* getPacMan();
	int* getBufferX() { return &bufferMOVX; }
	int* getBufferY() { return &bufferMOVY; }
	int* getMOVX() { return &MOVX; }
	int* getMOVY() { return &MOVY; }
	sf::Sprite* getMap() { return &SMapaBackground; }
	float getFrameTime() { return timePerFrame.asSeconds(); }

private:
	Texturas temp;
	//sf::Sprite sprite_personagem;
	//sf::Texture textura_personagem;
	//sf::Sprite testeboca;
	//sf::Texture testebocat;
	sf::Vector2f posicao;
	sf::Font font;
	sf::Text menu[3];

	sf::Sprite SMapaBackground;
	sf::Texture TMapaBackground;
	sf::Sprite testemask;
	sf::Texture testemaskt;
	sf::Sprite Fantasma;
	sf::Texture FantasmaTexture;
	//coisa
	int selectedItemIndex;
	sf::Time timePerFrame;
	
	
	sf::Sprite fundo;
	sf::Texture texturafundo;
	std::vector<sf::Sprite> sprites_vector;
	std::vector<sf::Texture> texturas_vector;
	Texturas texMenu;
	std::string skin;
	//
	Pause pauseMenu;
	PacMan pacman;
	Posicionador posPacman;
	int bufferMOVX;
	int bufferMOVY;
	int MOVX;
	int MOVY;
	int parouMOVY;
	int parouMOVX;
	bool Action;
	bool menuFechou;
};

