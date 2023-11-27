#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>
#include <Player.hpp>

using namespace std;
using namespace sf;

class Follower : protected ResourceManager
{
private:
	Sprite rect;
	Texture texture;
	Vector2f pos;
	Player player;

	bool playerCollided;

	float buffer;

	int currentEra;

public:
	Follower();

	Follower(Vector2f size, int era);

	void followPlayer(Vector2f playerPos, float dt);

	FloatRect getGlobalBounds();

	void setPlayerCollided(bool state);

	bool hasPlayerCollided() const;

	void drawTo(RenderWindow& window) const;

	void setPosition(Vector2f pos);

	void setBuffer(float num);

	void changeCurrentEra(int era);
};

#endif