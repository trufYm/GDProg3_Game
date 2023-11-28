#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class ResourceManager
{
protected:
	Texture backgroundTex;

	Texture followerTexCaveman;
	Texture followerTexAncient;
	Texture followerTexMedieval;
	Texture followerTexPreModern;
	Texture followerTexModern;

	Texture resourceTexCaveman;
	Texture resourceTexAncient;
	Texture resourceTexMedieval;
	Texture resourceTexPreModern;
	Texture resourceTexModern;

	Texture playerTexCaveman;
	Texture playerTexAncient;
	Texture playerTexMedieval;
	Texture playerTexPreModern;
	Texture playerTexModern;

	Music music;

public:
	ResourceManager();

	Texture loadPlayerTexture(int currentEra);

	Texture loadResourceTexture(int currentEra);

	Texture loadFollowerTexture(int currentEra);

	Texture loadBackgroundTexture();

	void playMusic();
};

#endif