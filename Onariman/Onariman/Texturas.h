#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "SFML/Graphics.hpp"
namespace sf {
	class RenderWindow;
}

class Texturas
{
public:
	Texturas();
	~Texturas();
	
private:
	std::vector<sf::Sprite> sprites_vector;
	std::vector<sf::Texture> texturas_vector;

public:
	int loadTexture(std::string file, int x, int y);
	int getSpriteSize() { return sprites_vector.size(); }
	int getTextureSize() { return texturas_vector.size(); }
	int imprimeTextura(int pos, sf::RenderWindow* janela);
};

