#include <SFML\Graphics.hpp>


int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Onari");

	while (window.isOpen())
	{

		window.clear();


		window.display();

	}
}