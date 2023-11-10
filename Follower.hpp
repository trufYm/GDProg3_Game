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
	Clock clock;
	Player player;
	bool collided = false;
	float dt = 0;

public:
	Follower()
	{
		if (!texture.loadFromFile("akame(2).png"))
			cout << "Bad" << endl;
		
		//NOTE: Need to change initial position to rand once multiple follower instances are implemented
		pos.x = 500;
		pos.y = 500;

		dt = clock.restart().asSeconds();
		
		rect.setTexture(texture);
		rect.setPosition(pos);
	}

	/*Take player's current position and move towards it.
	Uses same frame independent movement as player.*/
	void followPlayer(Vector2f playerPos)
	{
		Vector2f currentPos = rect.getPosition();
		Vector2f movement(0,0);

		 //First instance is too high and makes sprite too fast. Idea: lock framerate and get rid of jittery movement
		float mult = 60.f;
		float buffer = 60.0f;

		if (collided)
		{
			float step = (player.getSpeed() * 0.50f) * dt * mult;
			
			/*
			//Player is to the left, same y level
			if (playerPos.x < currentPos.x && playerPos.y == currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * mult;
				movement.y = 0;
				
				rect.move(movement);
			}

			//Player is to the right, same y level
			else if (playerPos.x > currentPos.x && playerPos.y == currentPos.y)
			{
				movement.x += (player.getSpeed() * 0.60f) * dt * mult;
				movement.y = 0;
				
				rect.move(movement);
			}

			//Player is below, same x level
			else if (playerPos.x == currentPos.x && playerPos.y > currentPos.y)
			{
				movement.x = 0;
				movement.y += (player.getSpeed() * 0.60f) * dt * mult;
				
				rect.move(movement);
			}

			//Player is above, same x level
			else if (playerPos.x == currentPos.x && playerPos.y < currentPos.y)
			{
				movement.x = 0;
				movement.y -= (player.getSpeed() * 0.60f) * dt * mult;
				
				rect.move(movement);
			}

			//Player is to the top left
			else if (playerPos.x < currentPos.x && playerPos.y < currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * mult;
				movement.y -= (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			//Player is to the top right
			else if (playerPos.x > currentPos.x && playerPos.y < currentPos.y)
			{
				movement.x += (player.getSpeed() * 0.60f) * dt * mult;
				movement.y -= (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			//Player is to the bottom left
			else if (playerPos.x < currentPos.x && playerPos.y > currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * mult;
				movement.y += (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			//Player is to the bottom right
			else if (playerPos.x > currentPos.x && playerPos.y > currentPos.y)
			{
				movement.x += (player.getSpeed() * 0.60f) * dt * mult;
				movement.y += (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			else
				rect.move(0,0);
				break;
			*/

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
			//else
				//rect.move(0,0);
				//break;
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