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
	Texture followerTex;
	Texture playerTex;
	Music music;

public:
	ResourceManager();
};

#endif