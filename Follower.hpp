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

	//Take player's current position and move towards it. Uses same frame independent movement as player
	void followPlayer(Vector2f playerPos)
	{
		Vector2f currentPos = rect.getPosition();
		Vector2f movement;

		float dt = clock.restart().asSeconds();

		while (collided)
		{
			//Player is to the left, same y level
			if (playerPos.x < currentPos.x && playerPos.y == currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * 60.f;
				//movement.y = 0;
				rect.move(movement);
			}

			//Player is to the right, same y level
			else if (playerPos.x > currentPos.x && playerPos.y == currentPos.y)
			{
				movement.x += (player.getSpeed() * 0.60f) * dt * 60.f;
				//movement.y = 0;
				rect.move(movement);
			}

			//Player is above, same x level
			else if (playerPos.x == currentPos.x && playerPos.y > currentPos.y)
			{
				//movement.x = 0;
				movement.y += (player.getSpeed() * 0.60f) * dt * 60.f;
				rect.move(movement);
			}

			//Player is below, same x level
			else if (playerPos.x == currentPos.x && playerPos.y < currentPos.y)
			{
				//movement.x = 0;
				movement.y -= (player.getSpeed() * 0.60f) * dt * 60.f;
				rect.move(movement);
			}

			//Player is to the bottom left
			else if (playerPos.x < currentPos.x && playerPos.y < currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * 60.f;
				movement.y -= (player.getSpeed() * 0.60f) * dt * 60.f;
				rect.move(movement);
			}

			//Player is to the bottom right
			else if (playerPos.x > currentPos.x && playerPos.y < currentPos.y)
			{
				movement.x = (player.getSpeed() * 0.60f) * dt * 60.f;
				movement.y -= (player.getSpeed() * 0.60f) * dt * 60.f;
				rect.move(movement);
			}

			//Player is to the top left
			else if (playerPos.x < currentPos.x && playerPos.y > currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * 60.f;
				movement.y = (player.getSpeed() * 0.60f) * dt * 60.f;
				rect.move(movement);
			}

			//Player is to the top right
			else if (playerPos.x > currentPos.x && playerPos.y > currentPos.y)
			{
				movement.x = (player.getSpeed() * 0.60f) * dt * 60.f;
				movement.y = (player.getSpeed() * 0.60f) * dt * 60.f;
				rect.move(movement);
			}

			else
				rect.move(0,0);
				break;
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