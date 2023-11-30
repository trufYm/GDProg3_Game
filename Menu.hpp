#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>

using namespace std;
using namespace sf;

class Menu : protected ResourceManager
{
private:
	Text titleText, subText;

	Sprite background;
	Texture bgTex;

	Font font;

public:
	Menu();

	void drawMainMenu(RenderWindow& window);

	void drawWinScreen(RenderWindow& window);
};

#endif