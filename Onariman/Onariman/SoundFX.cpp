#include "SoundFX.h"

#include <iostream>
#include <SFML/Audio/SoundBuffer.hpp>

SoundFX::SoundFX()
{
	

	sound_buffer[COMENDO].loadFromFile("Recursos/Sons/COMENDO2.ogg");
	sound_buffer[DEFAULT].loadFromFile("Recursos/Sons/DEFAULT.ogg");

	sound_fx[COMENDO].setBuffer(sound_buffer[COMENDO]);
	//sound_fx[COMENDO].setLoop(true);
	sound_fx[DEFAULT].setBuffer(sound_buffer[DEFAULT]);
	sound_fx[DEFAULT].setLoop(true);
	//sound_fx[POWERUP].openFromFile("Recursos/Sons/POWERUP.ogg");
	//sound_fx[POWERUP_ATIVADO].openFromFile("Recursos/Sons/POWERUP_ATIVADO.ogg");
}

void SoundFX::play(SOUND_FX selection)
{

	//sf::Music sound;
	if(sound_fx[selection].getStatus()!=sf::SoundSource::Playing)
	{
		/*switch (selection)
		{

		case COMENDO:
			if (!sound_fx[selection].openFromFile("Recursos/Sons/COMENDO.ogg"))
				return; // error
			break;
		case DEFAULT:
			if (!sound_fx[selection].openFromFile("Recursos/Sons/DEFAULT.ogg"))
				sound_fx[selection].setLoop(true);
				return; // error
			break;
		case POWERUP:
			if (!sound_fx[selection].openFromFile("Recursos/Sons/POWERUP.ogg"))
				return; // error
			break;
		case POWERUP_ATIVADO:
			if (!sound_fx[selection].openFromFile("Recursos/Sons/POWERUP_ATIVADO.ogg"))
				return; // error
			break;


		}*/

		
		//sound_fx.emplace_hint(selection, sound);
		//sound_fx.emplace(selection, sound);
		//sound_fx[selection].stop();
		sound_fx[selection].play();
		//sound_fx.at(selection).play();



	}
	

	
}
void SoundFX::stop(SOUND_FX selection)
{

	sound_fx.at(selection).stop();
	//sound_fx.erase(selection);

}