#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <Player.hpp>

using namespace std;
using namespace sf;

class Follower
{
private:
	Sprite rect;
	Texture texture;
	Vector2f pos;
	//Clock clock;
	Player player;
	bool collided = false;

public:
	Follower()
	{
		if (!texture.loadFromFile("akame(2).png"))
			cout << "Bad" << endl;
		
		//NOTE: Need to change initial position to rand once multiple follower instances are implemented
		pos.x = 500;
		pos.y = 500;

		rect.setTexture(texture);
		rect.setPosition(pos);
	}

	/*Take player's current position and move towards it.
	Uses same frame independent movement as player.
	Buffer value is to separate follower from player sprite*/
	void followPlayer(Vector2f playerPos, float dt)
	{
		Vector2f currentPos = rect.getPosition();
		Vector2f movement(0,0);

		float mult = 60.f;
		float buffer = 60.0f;
		
		if (collided)
		{
			float step = (player.getSpeed() * 0.80f) * dt * mult;
			
			if (playerPos.x > currentPos.x + buffer)
				movement.x += step;
			else if (playerPos.x < currentPos.x - buffer)
				movement.x -= step;

			if (playerPos.y > currentPos.y + buffer)
				movement.y += step;
			else if (playerPos.y < currentPos.y - buffer)
				movement.y -= step;

			if (movement.x != 0 || movement.y != 0)
				rect.move(movement);
		}
	}

	//HELPER FUNCTIONS

	FloatRect getGlobalBounds()
	{
		return rect.getGlobalBounds();
	}

	void setCollided(bool state)
	{
		collided = state;
	}

	bool hasCollided()
	{
		return collided;
	}

	void drawTo(RenderWindow& window)
	{
		window.draw(rect);
	}

};