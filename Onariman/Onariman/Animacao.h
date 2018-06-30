#pragma once
#include <SFML/Graphics/Texture.hpp>

class Animacao
{

public:
	Animacao();
	Animacao(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animacao();

	void update(int row, float deltaTime);
	

public:
	sf::IntRect uvRect;

private:

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;

};
