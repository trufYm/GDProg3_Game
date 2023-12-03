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
	Texture backgroundTex,

		followerTexCaveman,
		followerTexAncient,
		followerTexMedieval,
		followerTexPreModern,
		followerTexModern,

		resourceTexCaveman,
		resourceTexAncient,
		resourceTexMedieval,
		resourceTexPreModern,
		resourceTexModern,

		playerTexCaveman,
		playerTexAncient,
		playerTexMedieval,
		playerTexPreModern,
		playerTexModern,

		wallTexCaveman,
		wallTexAncient,
		wallTexMedieval,
		wallTexPreModern,
		wallTexModern,

		obstTexCaveman,
		obstTexAncient,
		obstTexMedieval,
		obstTexPreModern,
		obstTexModern;

	Music music;

	Font font;

public:
	ResourceManager();

	Texture loadPlayerTexture(int currentEra);

	Texture loadResourceTexture(int currentEra);

	Texture loadFollowerTexture(int currentEra);

	Texture loadWallTexture(int currentEra);

	Texture loadObstTexture(int currentEra);

	Texture loadBackgroundTexture();

	Font loadFont();

	void playMusic();
};

#endif