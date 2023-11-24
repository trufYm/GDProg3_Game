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

class Follower //: protected ResourceManager
{
private:
	Sprite rect;
	Texture texture;
	Vector2f pos;
	Player player;

	bool playerCollided;
	bool npcCollided;

	float buffer;

public:
	Follower();

	Follower(Vector2f size, Texture* texture);

	void followPlayer(Vector2f playerPos, float dt);

	FloatRect getGlobalBounds();

	void setPlayerCollided(bool state);

	bool hasPlayerCollided() const;

	void drawTo(RenderWindow& window) const;

	void setPosition(Vector2f pos);

	void setPosition(float x, float y);

	void setBuffer(float num);

};

#endif