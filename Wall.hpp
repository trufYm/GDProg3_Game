#ifndef WALL_HPP
#define WALL_HPP

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>
#include <Player.hpp>

class Wall : protected ResourceManager
{
private:
	Texture texture;

	FloatRect collisionRect;

	Sprite sprite;

	Vector2f pos;

	int currentEra, version;

public:
	Wall(Vector2f mapSize, int ver);

	void movePlayer(Player& player) const;

	void changeCurrentEra(int era);

	void changeWallBounds();

	void changeObstBounds();

	void drawTo(RenderWindow& window) const;
};

#endif