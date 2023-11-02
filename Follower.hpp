#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Follower
{
private:
	RectangleShape rect;
	Player player;

public:
	Follower()
	{
		rect.setFillColor(Color::Red);
		rect.setPosition(100.f, 100.f);
		rect.setSize(Vector2f(50.f, 50.f));
	}

	//NOT WORKING
	void detectCollision()
	{
		if (rect.getGlobalBounds().intersects(player.getSprite().getGlobalBounds()))
		{
			rect.move(player.getPosition());
		}
	}

	void drawTo(RenderWindow &window)
	{
		window.draw(rect);
	}
};