#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>

using namespace std;
using namespace sf;

class Menu : protected ResourceManager
{
private:
	Text titleText, subText1, subText2;

	RectangleShape button1, button2;

	Sprite background;
	Texture bgTex;

	Font font;

public:
	Menu();

	void drawMainMenu(RenderWindow& window);

	void drawWinScreen(RenderWindow& window);
};

#endif