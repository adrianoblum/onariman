#include "Texturas.h"
#include <iostream>



Texturas::Texturas()
{
}


Texturas::~Texturas()
{
}


int Texturas::loadTexture(std::string file, int x, int y)
{
	texturas_vector.resize(texturas_vector.size() + 1);
	sprites_vector.resize(sprites_vector.size() + 1);

	if (!texturas_vector[texturas_vector.size() - 1].loadFromFile(file))
	{
		std::cout << "ERR: Arquivo " << file << "nao pode ser carregado!!";
		return -1;
	}

	for (int i = 0; i < texturas_vector.size(); i++) //Atualiza as referências de memória para o sprite devido ao resize
		sprites_vector[sprites_vector.size() - 1 - i].setTexture(texturas_vector[texturas_vector.size() - 1 - i]);  
	sprites_vector[sprites_vector.size() - 1].setPosition(x, y);
	return 0;
}

int Texturas::imprimeTextura(int pos, sf::RenderWindow* janela)
{

	janela->draw(sprites_vector[pos]);

	return 0;
}


