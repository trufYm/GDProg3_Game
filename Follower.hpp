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
	Sprite rect;
	//Player player;
	float xPos = 100, yPos = 100;
	Texture texture;

public:
	Follower()
	{
		if (!texture.loadFromFile("akame(2).png"))
			cout << "Bad" << endl;
		
		rect.setTexture(texture);
		rect.setScale(1, 1);
		rect.setPosition(500.f, 500.f);
	}

	FloatRect getGlobalBounds()
	{
		return rect.getGlobalBounds();
	}

	void move(Vector2f pos)
	{
		rect.move(pos);
	}

	void drawTo(RenderWindow &window)
	{
		window.draw(rect);
	}
};