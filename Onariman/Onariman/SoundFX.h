#pragma once
#include <SFML/Audio/Music.hpp>
#include <map>
#include <SFML/Audio/Sound.hpp>

enum SOUND_FX { COMENDO, DEFAULT, POWERUP, POWERUP_ATIVADO };

class SoundFX
{
private:
	std::map<SOUND_FX, sf::SoundBuffer> sound_buffer;        // empty map container
	std::map<SOUND_FX, sf::Sound> sound_fx;        // empty map container
	//std::vector<sf::Music> vector_sfx;


public:
	SoundFX();
	void play(SOUND_FX selection);
	void stop(SOUND_FX selection);
	void play(sf::Music sound);


};
