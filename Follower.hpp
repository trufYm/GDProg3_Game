#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
//#include <Player.hpp>

using namespace std;
using namespace sf;

class Follower
{
private:
	Sprite rect;
	//Player player;
	Texture texture;
	Vector2f pos;
	bool collided;

public:
	Follower()
	{
		if (!texture.loadFromFile("akame(2).png"))
			cout << "Bad" << endl;
		
		pos.x = 500;
		pos.y = 500;

		collided = false;

		rect.setTexture(texture);
		rect.setScale(2, 2);
		rect.setPosition(pos);
	}

	//I THINK THIS SHOULD WORK BUT IT DOESNT BECAUSE IM BAD AT PROGRAMMING AND DONT KNOW HOW TO DO SHIT
	void followPlayer(Vector2f playerPos)
	{
		Vector2f currentPos;

		currentPos.x = rect.getPosition().x;
		currentPos.y = rect.getPosition().y;

		cout << "Following!" << endl;

		while (collided)
		{
			//Player is to the left, same y level
			if (playerPos.x < currentPos.x && playerPos.y == currentPos.y)
				rect.move(-5.0f, 0);

			//Player is to the right, same y level
			else if (playerPos.x > currentPos.x && playerPos.y == currentPos.y)
				rect.move(5.0f, 0);

			//Player is above, same x level
			else if (playerPos.x == currentPos.x && playerPos.y > currentPos.y)
				rect.move(0, -5.0f);

			//Player is below, same x level
			else if (playerPos.x == currentPos.x && playerPos.y < currentPos.y)
				rect.move(0, 5.0f);

			//THIS CAUSES CRASH
			/*Player is to the bottom left
			else if (playerPos.x < currentPos.x && playerPos.y < currentPos.y)
				rect.move(-5.0f, 5.0f);

			//Player is to the bottom right
			else if (playerPos.x > currentPos.x && playerPos.y < currentPos.y)
				rect.move(5.0f, 5.0f);

			//Player is to the top left
			else if (playerPos.x < currentPos.x && playerPos.y > currentPos.y)
				rect.move(-5.0f, -5.0f);

			//Player is to the top right
			else if (playerPos.x > currentPos.x && playerPos.y > currentPos.y)
				rect.move(5.0f, -5.0f);
			*/

			else
				break;
		}
	}

	FloatRect getGlobalBounds()
	{
		return rect.getGlobalBounds();
	}

	//WHY THIS NO WORKY???????????????
	void setCollided(bool state)
	{
		this->collided = state;
		cout << collided << " set" << endl;
	}

	//THIS FUCKING RETURNS FALSE WHY????????
	bool hasCollided()
	{
		cout << collided << " has" << endl;
		return collided;
	}

	void drawTo(RenderWindow& window)
	{
		window.draw(rect);
	}
	
};