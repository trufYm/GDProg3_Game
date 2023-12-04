#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>
#include <Player.hpp>

using namespace std;
using namespace sf;

class Menu : protected ResourceManager
{
private:
	Text titleText, subText1, subText2;

	RectangleShape button1, button2;

	RenderWindow& window;

	Sprite background;
	Texture bgTex;

	Font font;

public:
	Menu(RenderWindow& mainWindow);

	void drawMainMenu();

	void drawWinScreen();
};

#endif