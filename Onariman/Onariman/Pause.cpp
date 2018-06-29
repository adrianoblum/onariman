#include "Pause.h"
#include <iostream>

Pause::Pause(int width, int height)
{
	
		sf::FloatRect textRect;
		if (!font.loadFromFile("vgafix.ttf"))
		{
			// handle error
		}


		options[0].setFont(font);
		options[0].setColor(sf::Color::Yellow);
		options[0].setString("CONTINUE");
		//Menu[0].setPosition(sf::Vector2f((width / 2)-50, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
		options[0].setOutlineColor(sf::Color::Black);
		textRect = options[0].getLocalBounds();
		options[0].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		options[0].setPosition(sf::Vector2f(width / 2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));


		options[1].setFont(font);
		options[1].setColor(sf::Color::White);
		options[1].setString("RETURN");
		//Menu[1].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
		options[1].setOutlineColor(sf::Color::Black);
		textRect = options[1].getLocalBounds();
		options[1].setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		options[1].setPosition(sf::Vector2f(width / 2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));


		skin = "default";
		selectedItemIndex = 0;
	

}

void Pause::selection(sf::RenderWindow* window)
{

	//sf::RenderWindow window(sf::VideoMode(SWIDTH, SHEIGHT), "Onari");
	//play_music();
	bool isout = false;
	sf::Event event;	
	//window.setFramerateLimit(60);
	//texMenu.loadTexture("fundo.png", 0, 0);
	//texMenu.loadTexture("oooooo2.png", 380, 553);
	//texMenu.loadTexture("onaaaaa.png", 0, 0);
	//loadTeste("teste onari.png");
	while (isout==false)
	{


		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					MoveUp();
					break;

				case sf::Keyboard::Down:
					MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (GetPressedItem())
					{
					case 0:
						std::cout << "Play button has been pressed" << std::endl;
						isout = true;
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						window->close();
						break;
					
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window->close();

				break;

			}
		}

		window->clear();

		//window.draw(fundo);
		for (int i = 0; i<texMenu.getSpriteSize(); i++)
		{
			texMenu.imprimeTextura(i, window);

		}
		draw(window);




		window->display();


	}
}

void Pause::draw(sf::RenderWindow* window)
{

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window->draw(options[i]);
	}
}

//void Pause::setDim(int w, int h)
//{
//
//
//}
