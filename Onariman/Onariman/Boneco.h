#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>


namespace sf {
	class RenderWindow;
}

class Boneco
{
public:

	float speed;
	sf::Sprite Sboneco;
	sf::Texture Tboneco;
	sf::Sprite Sposicionador;
	sf::Texture Tposicionador;


public:

	void girar(int movx, int movy);
	void animation();

	sf::Sprite getSpriteBoneco(void){return Sboneco;}
	sf::Texture getTextureBoneco(void) { return Tboneco; }
	sf::Sprite getSpritePosicionador(void) { return Sposicionador; }
	sf::Texture getTexturePosicionador(void) { return Tposicionador; }
	//void loadTextureBoneco(std::string s);
	void setSpriteBoneco(sf::Texture textura);
	void loadTexturePosicionador(std::string s);
	void setSpritePosicionador(std::string s);
	void initialize();
	void set_skin(std::string s);
	bool colidiu(sf::Sprite objeto, int alpha);
	void draw(sf::RenderWindow* janela);
};
