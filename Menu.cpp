#include <Menu.hpp>

Menu::Menu()
{
	bgTex = loadBackgroundTexture();

	background.setTexture(bgTex);
	
	font = loadFont();
}

void Menu::drawMainMenu(RenderWindow& window)
{
	Event event;
	Vector2f windowSize = Vector2f(window.getSize());

	titleText.setFont(font);
	titleText.setString("EPOCH");
	titleText.setCharacterSize(150);
	titleText.setPosition(windowSize.x / 3, 100);
	titleText.setFillColor(Color::White);
	titleText.setStyle(Text::Bold);

	subText.setFont(font);
	subText.setString("Press Enter to Continue...");
	subText.setCharacterSize(50);
	subText.setPosition(float(windowSize.x / 3.5), windowSize.y - 200);
	subText.setFillColor(Color::White);
	subText.setStyle(Text::Regular);


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return)
				return;
		}

		window.clear();

		window.draw(background);

		window.draw(titleText);
		window.draw(subText);

		window.display();
	}
}

void Menu::drawWinScreen(RenderWindow& window)
{
	Event event;
	Vector2f windowSize = Vector2f(window.getSize());

	titleText.setFont(font);
	titleText.setString("You Win!");
	titleText.setCharacterSize(150);
	titleText.setPosition(windowSize.x / 4, 100);
	titleText.setFillColor(Color::White);
	titleText.setStyle(Text::Bold);

	subText.setFont(font);
	subText.setString("Press Esc to Exit...");
	subText.setCharacterSize(50);
	subText.setPosition(float(windowSize.x / 3), windowSize.y - 200);
	subText.setFillColor(Color::White);
	subText.setStyle(Text::Regular);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}

		window.clear();

		window.setView(window.getDefaultView());

		window.draw(background);

		window.draw(titleText);
		window.draw(subText);

		window.display();
	}
}