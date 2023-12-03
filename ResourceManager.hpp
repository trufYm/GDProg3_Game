#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class ResourceManager
{
protected:
	static Texture backgroundTex,

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

	static Music music;

	static Font font;

	static SoundBuffer buffer;

	static Sound sound;

public:
	ResourceManager();

	static void loadAssets();

	static Texture loadPlayerTexture(int currentEra);

	static Texture loadResourceTexture(int currentEra);

	static Texture loadFollowerTexture(int currentEra);

	static Texture loadWallTexture(int currentEra);

	static Texture loadObstTexture(int currentEra);

	static Texture loadBackgroundTexture();

	static Font loadFont();

	static void playMusic();

	static void playEraChangeSound();
};

#endif