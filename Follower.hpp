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

public:
	Follower()
	{
		rect.setFillColor(Color::White);
		rect.setPosition(100.f, 100.f);
		rect.setSize(Vector2f(20.f, 20.f));
	}

	void drawTo(RenderWindow &window)
	{
		window.draw(rect);
	}
};