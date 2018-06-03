#include "Principal.h"
#include <iostream>
#include "Menu.h"
#include "Collision.h"


Principal::Principal()
{
	//carrega_xarater();
	Collision::CreateTextureAndBitmask(textura_personagem, "Original_PacMan.png");
	sprite_personagem.setTexture(textura_personagem);
	sprite_personagem.setOrigin(sprite_personagem.getGlobalBounds().height/2, sprite_personagem.getGlobalBounds().width/2);
	sprite_personagem.setPosition(350, 350);
	sprite_personagem.setScale(ESCALA_IMG, ESCALA_IMG);
	posicao = sprite_personagem.getPosition();



	Collision::CreateTextureAndBitmask(testeonarit, "mapa.png");
	testeonaris.setTexture(testeonarit);
	testeonaris.setOrigin(testeonaris.getGlobalBounds().height / 2, testeonaris.getGlobalBounds().width / 2);
	testeonaris.setPosition(SWIDTH/2, SHEIGHT/2);
	testeonaris.setScale(ESCALA_MAPA, ESCALA_MAPA);

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
					
					sprite_personagem.setRotation(270);
					sprite_personagem.setScale({ -ESCALA_IMG, ESCALA_IMG });
					bufferMOVY = -MOV_SPEED;
					bufferMOVX = 0;
					//mover_teste(0, -MOV_SPEED);
					break;

				case sf::Keyboard::Down:
					
					sprite_personagem.setRotation(90);
					sprite_personagem.setScale({ -ESCALA_IMG, ESCALA_IMG });
					bufferMOVY = MOV_SPEED;
					bufferMOVX = 0;
					break;

				case sf::Keyboard::Right:
					
					sprite_personagem.setRotation(0);
					sprite_personagem.setScale({ -ESCALA_IMG, ESCALA_IMG });
					bufferMOVX = MOV_SPEED;
					bufferMOVY = 0;
					break;
				case sf::Keyboard::Left:
					
					sprite_personagem.setRotation(0);
					//std::cout << sprite_personagem.getGlobalBounds().width << std::endl << sprite_personagem.getGlobalBounds().height;
					//sprite_personagem.setOrigin({ sprite_personagem.getLocalBounds().width, 0 });
					sprite_personagem.setScale({ ESCALA_IMG, ESCALA_IMG });
					//sprite_personagem.setScale()
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
			//if (bufferMOVX != MOVX || bufferMOVY != MOVY)
			//	podeounao = testaBuffer();
			//if(podeounao)
			//{
				MOVX = bufferMOVX;
				MOVY = bufferMOVY;
//
		//	}
			//sprite_personagem.move(MOVX*frame.asSeconds(), MOVY*frame.asSeconds());
			/*if (Collision::BoundingBoxTest(sprite_personagem, testeonaris))
			{
				

			}*/
			//if (!podeounao)
		//		podeounao = false;
			
			sprite_personagem.move(MOVX*timePerFrame.asSeconds(), MOVY*timePerFrame.asSeconds());
			if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
			{
				sprite_personagem.move(-MOVX*timePerFrame.asSeconds(), -MOVY*timePerFrame.asSeconds());

			}
			//if(Collision::PixelPerfectTest(sprite_personagem, testeonaris))
			//{
			//	sprite_personagem.move(-3*MOVX*timePerFrame.asSeconds(), -3*MOVY*timePerFrame.asSeconds());
			//
			//}
			//else
			//{
			//	
			//	sprite_personagem.move(-3 * MOVX*timePerFrame.asSeconds(), -3 * MOVY*timePerFrame.asSeconds());
			//	sprite_personagem.move( MOVX*timePerFrame.asSeconds(), MOVY*timePerFrame.asSeconds());
			//}
			//mover_teste(timePerFrame);

			//sprite_personagem.move(xi, yi);
			
		}
		
		posicao = sprite_personagem.getPosition();				
		
		
		//mover_teste(MOVX, MOVY);
		janela->clear();
		janela->draw(sprite_personagem);
		janela->draw(testeonaris);
		janela->display();



	}



}

void Principal::mover_teste(sf::Time frame)
{
	
	sprite_personagem.move(MOVX*frame.asSeconds(), MOVY*frame.asSeconds());

	
	int i, j = MOV_SPEED*frame.asSeconds();
	bool flag = false;
	
	while(flag!=true)
	{
		flag = true;
		for (i = 0; i<4; i++)
		{
			
			if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
			{
				flag = false;
			}

			sprite_personagem.rotate(90);

		}
		if (!flag)
		{
			sprite_personagem.move(-MOVX / j, -MOVY / j);
			
		}
		if(j>1)
			j--;


	}

		
	
	
	

}

bool Principal::testaBuffer()
{
	int i = 0,j;
	bool podeounao = true;
	int aux;
	bufferMOVX /= 30;
	bufferMOVY /= 30;
	if (bufferMOVX != 0 && bufferMOVY != 0)
		aux = 1;
	if (bufferMOVX > 0)
	{
		for (j = 0; j < bufferMOVX; j++)
		{
			sprite_personagem.move(1, 0);

			if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
			{
				podeounao = false;
				break;
			}
		}

		if (podeounao)
		{
			for (i = 0; i < 4; i++)
			{
				if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
				{
					podeounao = false;
				}

				sprite_personagem.rotate(90);
			}
		}

		sprite_personagem.move(-j, 0);
		

	}
		
	else if (bufferMOVX < 0)
	{
		for (j = 0; j < abs(bufferMOVX); j++)
		{
			sprite_personagem.move(-1, 0);

			if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
			{
				podeounao = false;
				break;
			}
		}

		if (podeounao)
		{
			for (i = 0; i < 4; i++)
			{
				if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
				{
					podeounao = false;
				}

				sprite_personagem.rotate(90);
			}
		}

		sprite_personagem.move(j, 0);


	}
		
	else if(bufferMOVX==0)
	{
		if (bufferMOVY > 0)
		{
			for (j = 0; j < bufferMOVY; j++)
			{
				sprite_personagem.move(0, 1);

				if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
				{
					podeounao = false;
					break;
				}
			}

			if (podeounao)
			{
				for (i = 0; i < 4; i++)
				{
					if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
					{
						podeounao = false;
					}

					sprite_personagem.rotate(90);
				}
			}

			sprite_personagem.move(0, -j);


		}

		else
		{
			for (j = 0; j < abs(bufferMOVY); j++)
			{
				sprite_personagem.move(0, -1);

				if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
				{
					podeounao = false;
					break;
				}
			}

			if (podeounao)
			{
				for (i = 0; i < 4; i++)
				{
					if (Collision::PixelPerfectTest(sprite_personagem, testeonaris))
					{
						podeounao = false;
					}

					sprite_personagem.rotate(90);
				}
			}

			sprite_personagem.move(0, j);
	
			


		}

	}
	else
		podeounao = false;

	bufferMOVX *= 30;
	bufferMOVY *= 30;
	return podeounao;
	//sprite_personagem.move(bufferMOVX*0.2, bufferMOVY*0.2);



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