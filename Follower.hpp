#ifndef FOLLOWER_H
#define FOLLOWER_H

#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
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

	float buffer, mult, time_interval, noiseTime;

	int currentEra;

	random_device random;

public:
	Follower(Vector2f mapSize, int era);

	void moveAsResource(float dt);

	void followPlayer(Vector2f playerPos, float dt);

	void changeCurrentEra(int era);

	void changeToFollower();

	FloatRect getGlobalBounds();

	bool hasPlayerCollided() const;

	void drawTo(RenderWindow& window) const;

	void setPosition(Vector2f pos);

	void setBuffer(float num);
};

#endif