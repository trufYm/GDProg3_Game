#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>
#include <Player.hpp>
#include <Follower.hpp>

using namespace std;
using namespace sf;

class Map : protected ResourceManager
{
private:
	Vector2f mapSize, mapBorder, spriteSize;

	Texture bgTexture;
	Sprite background;

	int currentEra;

public:
	Map();

	void changeCurrentEra(int era);

	void movePlayer(Player* player, vector<Follower*>& npcList, Vector2f playerNewPos);

	void detectPlayer(Player* player, vector<Follower*>& npcList);

	void drawTo(RenderWindow& window) const;

	Vector2f getMapBorder() const;

	Vector2f getMapSize() const;
};

#endif