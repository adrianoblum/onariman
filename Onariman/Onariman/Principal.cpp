#include "Principal.h"
#include <iostream>
#include "Menu.h"
#include "Pause.h"
#include "Collision.h"


Principal::Principal() : pauseMenu(SWIDTH, SHEIGHT)
{
	
	Collision::CreateTextureAndBitmask(TMapaBackground, "Recursos/Imagens/mapa2.png");
	SMapaBackground.setTexture(TMapaBackground);
	SMapaBackground.setOrigin(SMapaBackground.getGlobalBounds().width / 2, SMapaBackground.getGlobalBounds().height / 2);
	SMapaBackground.setPosition(SWIDTH/2, SHEIGHT/2);
	SMapaBackground.setScale(ESCALA_MAPA, ESCALA_MAPA);
	posPacman.set_skin("Recursos/Imagens/teste2.png");

	Collision::CreateTextureAndBitmask(testemaskt, "Recursos/Imagens/mapa_mask.png");
	testemask.setTexture(testemaskt);

	testemask.setOrigin(testemask.getGlobalBounds().width / 2, testemask.getGlobalBounds().height / 2);
	testemask.setPosition(SWIDTH / 2, SHEIGHT / 2);
	testemask.setScale(ESCALA_MAPA, ESCALA_MAPA);

	MOVX = 0;
	MOVY = 0;
	bufferMOVX = 0;
	bufferMOVY = 0;
	parouMOVY = 0;
	parouMOVX = 0;
	Action = false;
	menuFechou = false;
}


Principal::~Principal()
{
}

void Principal::loop(sf::RenderWindow* janela)
{
	sf::Event event;
	bool podeounao = true;
	bool primeira = true;
	bool OpenMenu = false;
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Clock deltaClock;  
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	carrega_texto_temp();
	while (janela->isOpen())
	{
	
		while (janela->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					
					if (OpenMenu == false)
					{
						bufferMOVY = -MOV_SPEED;
						bufferMOVX = 0;
						//mover_teste(0, -MOV_SPEED);
					}
					break;

				case sf::Keyboard::Down:
					
					if (OpenMenu == false)
					{
						bufferMOVY = MOV_SPEED;
						bufferMOVX = 0;
					}
					break;

				case sf::Keyboard::Right:
					
					if (OpenMenu == false)
					{
						bufferMOVX = MOV_SPEED;
						bufferMOVY = 0;
					}
					break;
				case sf::Keyboard::Left:

					
					if (OpenMenu == false)
					{
						bufferMOVX = -MOV_SPEED;
						bufferMOVY = 0;
					}
					
					break;

				case sf::Keyboard::Return:
					if (OpenMenu == false)
					{

					}
					else
					{
						janela->close();
					}
					break;
				case sf::Keyboard::Escape:
					if (OpenMenu == false)
					{

						//colocar funçao de stand-by p/ todos os entity
						parouMOVX = MOVX;
						parouMOVY = MOVY;
						bufferMOVX = 0;
						bufferMOVY = 0;
						MOVX = 0;
						MOVY = 0;
						OpenMenu = true;
						
					}
					else
					{
						
					}
					break;
				}

				break;
			case sf::Event::Closed:
				janela->close();

				break;
			}
		}

		

		sf::Time deltaTime = deltaClock.restart();  // Restart returns the time since the last restart call
		timeSinceLastUpdate += deltaTime;
		
		while (timeSinceLastUpdate >= timePerFrame) //controle do framerate 
		{
			
			timeSinceLastUpdate -= timePerFrame;
			podeounao = testaBuffer();
			if (podeounao)
			{

				MOVX = bufferMOVX;
				MOVY = bufferMOVY;
				//rotacao(MOVX, MOVY);
				pacman.girar(MOVX, MOVY);
				posPacman.girar(MOVX, MOVY);
			}
			posPacman.move(MOVX, MOVY,timePerFrame.asSeconds());
			if (!posPacman.colidiu(SMapaBackground, 50))
			{
				primeira = true;
				pacman.move(MOVX, MOVY, timePerFrame.asSeconds());
				//posPacman.move(-MOVX, -MOVY, timePerFrame.asSeconds());
				//sprite_personagem.move(MOVX*timePerFrame.asSeconds(), MOVY*timePerFrame.asSeconds());
				
			}
			else
			{
				if (primeira)
				{
					posPacman.move(MOVX, MOVY, timePerFrame.asSeconds());
					pacman.move(MOVX*2, MOVY*2, timePerFrame.asSeconds());
					primeira = false;
				}
				else
				{
					posPacman.move(-MOVX, -MOVY, timePerFrame.asSeconds());

				}
				
				
			}
			
			
		}
		
		//posicao = sprite_personagem.getPosition();				
		
		
		//mover_teste(MOVX, MOVY);
		janela->clear();
		while (OpenMenu == true)
		{
			
			OpenMenu = false;
			//Action = selection(janela);
			menuFechou = true;
			
		
		}
		
			janela->draw(SMapaBackground);
			//janela->draw(testemask);
			janela->draw(testemask);
			pacman.draw(janela);
			posPacman.draw(janela);

			janela->draw(Fantasma);			
			janela->display();
		
		if (Action)
			janela->close();
		
			

	}



}


bool Principal::testaBuffer()
{
	bool podeounao = true;
	float movx=static_cast<float>(bufferMOVX)/60;
	float movy=static_cast<float>(bufferMOVY)/60;
	pacman.girar(movx, movy);
	posPacman.girar(movx, movy);
	//rotacao(movx, movy);
	posPacman.move(movx*4, movy*4,1);
	//testeboca.move(movx*4, movy*4);
	if (posPacman.colidiu(SMapaBackground,50))
	{
		podeounao = false;

	}	
	pacman.girar(MOVX, MOVY);
	posPacman.girar(MOVX, MOVY);
	posPacman.move(-movx*4, -movy*4, 1);

	return podeounao;



}



void Principal::carrega_texto_temp()
{
	
	sf::FloatRect textRect;
	if (!font.loadFromFile("vgafix.ttf"))
	{
		// handle error
	}


	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Yellow);
	menu[0].setString("DEDUZIU ERRADO MORREU DE CANCER");
	//menu[0].setPosition(sf::Vector2f((width / 2)-50, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[0].setOutlineColor(sf::Color::Black);
	textRect = menu[0].getLocalBounds();
	menu[0].setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	menu[0].setPosition(sf::Vector2f(SWIDTH / 2.0f, SWIDTH / (MAX_NUMBER_OF_ITEMS + 1) * 1));


}