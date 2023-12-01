#ifndef WALL_HPP
#define WALL_HPP

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>
#include <Player.hpp>

class Wall : protected ResourceManager
{
private:
	//Texture texture;

	Player player;

	FloatRect collisionRect;

	Sprite sprite;

	Vector2f pos;

	int currentEra;

public:
	Wall(Vector2f mapSize);

	void movePlayer();

	FloatRect getCollisionBounds();

	void drawTo(RenderWindow& window) const;

};

#endif