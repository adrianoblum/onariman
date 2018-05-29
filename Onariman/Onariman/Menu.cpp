#include "Menu.h"
#include <iostream>
#include "Principal.h"


Menu::Menu(float width, float height)
{
	sf::FloatRect textRect;
	if (!font.loadFromFile("vgafix.ttf"))
	{
		// handle error
	}
	

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Yellow);
	menu[0].setString("Play");
	//menu[0].setPosition(sf::Vector2f((width / 2)-50, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[0].setOutlineColor(sf::Color::Black);
	textRect = menu[0].getLocalBounds();
	menu[0].setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	menu[0].setPosition(sf::Vector2f(width / 2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));


	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	//menu[1].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[1].setOutlineColor(sf::Color::Black);
	textRect = menu[1].getLocalBounds();
	menu[1].setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	menu[1].setPosition(sf::Vector2f(width / 2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));


	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	//menu[2].setPosition(sf::Vector2f((width / 2) - 50, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu[2].setOutlineColor(sf::Color::Black);


	textRect = menu[2].getLocalBounds();
	menu[2].setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	menu[2].setPosition(sf::Vector2f(width / 2.0f, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	skin = "default";
	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Yellow);
	}
}

void Menu::selection()
{
	sf::RenderWindow window(sf::VideoMode(SWIDTH, SHEIGHT), "Onari");
	play_music();

	sf::Event event;
	Principal jogo;
	
	texMenu.loadTexture("fundo.png", 0, 0);
	texMenu.loadTexture("oooooo2.png", 380, 553);
	//texMenu.loadTexture("onaaaaa.png", 0, 0);
	//loadTeste("teste onari.png");
	while (window.isOpen())
	{

		
		while (window.pollEvent(event))
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
						music.stop();
						jogo.loop(&window);
						break;
					case 1:
						std::cout << "Option button has been pressed" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}

					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();

		//window.draw(fundo);
		for(int i=0;i<texMenu.getSpriteSize();i++)
		{
			texMenu.imprimeTextura(i, &window);

		}
		draw(window);
		



		window.display();
		

	}


}


int Menu::play_music()
{
	
	if (!music.openFromFile("Smoke Weed Everyday.ogg"))
		return -1; // error
	music.setLoop(true);
	music.play();
	
	return 0;
}


