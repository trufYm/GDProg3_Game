#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>
#include <Player.hpp>
#include <Follower.hpp>

using namespace std;
using namespace sf;

class Map : protected ResourceManager
{
private:
	Vector2f mapSize, mapBorder;

	Texture bgTexture;
	Sprite background;

public:
	Map();

	void movePlayer(Player* player, vector<Follower*>& npcList, Vector2f playerNewPos);

	void detectPlayer(Player* player, vector<Follower*>& npcList);

	void drawTo(RenderWindow& window) const;

	Vector2f getMapBorder() const;

	Vector2f getMapSize() const;
};

#endif