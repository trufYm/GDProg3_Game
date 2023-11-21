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
	Vector2f mapBorder;

public:
	Map()
	{
		//default
		mapBorder = { 650, 960 };
	}

	void detectPlayer(Player* player, vector<Follower *> &npcList)
	{
		Vector2f playerOldPos = player->getPosition();

		if (playerOldPos.x > mapSize.x - mapBorder.x)
		{
			Vector2f playerNewPos = { 800, playerOldPos.y };

			player->setPosition(playerNewPos);

			for (int i = 0; i < (npcList).size(); i++)
			{
				if ((*npcList[i]).hasPlayerCollided())
				{
					(*npcList[i]).setPosition(playerNewPos);
				}
				
			}
		}
	}

	void setMapSize(Vector2u size)
	{
		mapSize = size;
	}

};