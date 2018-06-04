#include "Principal.h"
#include <iostream>
#include "Menu.h"
#include "Collision.h"


Principal::Principal()
{
	//carrega_xarater();
	

	Collision::CreateTextureAndBitmask(testeonarit, "mapa2.png");
	testeonaris.setTexture(testeonarit);
	testeonaris.setOrigin(testeonaris.getGlobalBounds().width / 2, testeonaris.getGlobalBounds().height / 2);
	testeonaris.setPosition(SWIDTH/2, SHEIGHT/2);
	testeonaris.setScale(ESCALA_MAPA, ESCALA_MAPA);

	Collision::CreateTextureAndBitmask(testemaskt, "mapa_mask.png");
	testemask.setTexture(testemaskt);

	testemask.setOrigin(testemask.getGlobalBounds().width / 2, testemask.getGlobalBounds().height / 2);
	testemask.setPosition(SWIDTH / 2, SHEIGHT / 2);
	testemask.setScale(ESCALA_MAPA, ESCALA_MAPA);

	Collision::CreateTextureAndBitmask(textura_personagem, "Original_PacMan.png");
	
	sprite_personagem.setTexture(textura_personagem);

	sprite_personagem.setOrigin(sprite_personagem.getGlobalBounds().width /2, sprite_personagem.getGlobalBounds().height/2);
	sprite_personagem.setPosition(testeonaris.getGlobalBounds().width / 2, testeonaris.getGlobalBounds().height / 2+73);
	sprite_personagem.setScale(ESCALA_IMG, ESCALA_IMG);
	posicao = sprite_personagem.getPosition();

	Collision::CreateTextureAndBitmask(testebocat, "teste2.png");
	
	testeboca.setTexture(testebocat);
	
	testeboca.setOrigin(testeboca.getGlobalBounds().height/2, testeboca.getGlobalBounds().width/2);
	testeboca.setPosition(testeonaris.getGlobalBounds().width / 2, testeonaris.getGlobalBounds().height / 2+73);
	testeboca.setScale(ESCALA_IMG, ESCALA_IMG);
	//posicao = sprite_personagem.getPosition();
	MOVX = 0;
	MOVY = 0;
	bufferMOVX = 0;
	bufferMOVY = 0;


}


Principal::~Principal()
{
}

void Principal::loop(sf::RenderWindow* janela)
{
	sf::Event event;
	bool podeounao = true;
	bool primeira = true;
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
					
					
					bufferMOVY = -MOV_SPEED;
					bufferMOVX = 0;
					//mover_teste(0, -MOV_SPEED);
					break;

				case sf::Keyboard::Down:
					
					
					bufferMOVY = MOV_SPEED;
					bufferMOVX = 0;
					break;

				case sf::Keyboard::Right:
					
					
					bufferMOVX = MOV_SPEED;
					bufferMOVY = 0;
					break;
				case sf::Keyboard::Left:

					

					bufferMOVX = -MOV_SPEED;
					bufferMOVY = 0;
					
					break;

				case sf::Keyboard::Return:

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
				rotacao(MOVX, MOVY);
			}
			testeboca.move(MOVX*timePerFrame.asSeconds(), MOVY*timePerFrame.asSeconds());
			if (!Collision::PixelPerfectTest(testeboca, testeonaris,50))
			{
				primeira = true;
				sprite_personagem.move(MOVX*timePerFrame.asSeconds(), MOVY*timePerFrame.asSeconds());
				
			}
			else
			{
				if (primeira)
				{
					testeboca.move(MOVX*timePerFrame.asSeconds(), MOVY*timePerFrame.asSeconds());
					sprite_personagem.move(MOVX*timePerFrame.asSeconds()*2, MOVY*timePerFrame.asSeconds()*2);
					primeira = false;
				}
				else
				{
					testeboca.move(-MOVX*timePerFrame.asSeconds(), -MOVY*timePerFrame.asSeconds());

				}
				
				//for(i=0;i>)
			}
			
			
		}
		
		posicao = sprite_personagem.getPosition();				
		
		
		//mover_teste(MOVX, MOVY);
		janela->clear();
		
		janela->draw(testeonaris);
		janela->draw(testemask);
		janela->draw(sprite_personagem);
		janela->draw(testeboca);
		janela->display();



	}



}


bool Principal::testaBuffer()
{
	bool podeounao = true;
	float movx=static_cast<float>(bufferMOVX)/60;
	float movy=static_cast<float>(bufferMOVY)/60;
	rotacao(movx, movy);
	testeboca.move(movx*4, movy*4);
	if (Collision::PixelPerfectTest(testeboca, testeonaris,50))
	{
		podeounao = false;

	}
	rotacao(MOVX, MOVY);
	testeboca.move(-movx*4, -movy*4);
	return podeounao;



}

void Principal::carrega_xarater()
{
	
	if(!textura_personagem.loadFromFile("Original_PacMan.png"))
	{
		std::cout << "chabugao no char";
		return;
	}
	sprite_personagem.setTexture(textura_personagem);


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

void Principal::rotacao(int movx, int movy)
{
	if(movy<0)
	{
		sprite_personagem.setRotation(270);
		sprite_personagem.setScale({ -ESCALA_IMG, ESCALA_IMG });
		testeboca.setRotation(270);
		testeboca.setScale({ -ESCALA_IMG, ESCALA_IMG });

	}
	else if(movy>0)
	{
		
		sprite_personagem.setRotation(90);
		sprite_personagem.setScale({ -ESCALA_IMG, ESCALA_IMG });
		testeboca.setRotation(90);
		testeboca.setScale({ -ESCALA_IMG, ESCALA_IMG });

	}
	else if(movx>0)
	{
		sprite_personagem.setRotation(0);
		sprite_personagem.setScale({ -ESCALA_IMG, ESCALA_IMG });
		testeboca.setRotation(0);
		testeboca.setScale({ -ESCALA_IMG, ESCALA_IMG });

	}

	else if(movx<0)
	{
		sprite_personagem.setRotation(0);

		sprite_personagem.setScale({ ESCALA_IMG, ESCALA_IMG });
		testeboca.setRotation(0);

		testeboca.setScale({ ESCALA_IMG, ESCALA_IMG });


	}
	else
	{
		sprite_personagem.setRotation(0);
		sprite_personagem.setScale({ -ESCALA_IMG, ESCALA_IMG });
		testeboca.setRotation(0);
		testeboca.setScale({ -ESCALA_IMG, ESCALA_IMG });

	}
	

}
