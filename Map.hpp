#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <Player.hpp>
#include <Follower.hpp>

using namespace std;
using namespace sf;

class Map
{
private:
	Vector2u mapSize;
	Vector2u windowSize;

public:
	Map()
	{
		//default
		windowSize = { 1280, 960 };
	}

	void detectPlayer(Player* player, vector<Follower *> npcList)
	{
		if (player->getPosition().x > mapSize.x - windowSize.x)
		{
			player->setPosition(windowSize);

			for (int i = 0; i < (npcList).size(); i++)
			{
				(*npcList[i]).setPosition(windowSize);
			}
		}
	}

	void setMapSize(Vector2u size)
	{
		mapSize = size;
	}

};