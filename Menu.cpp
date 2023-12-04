#include <Menu.hpp>

Menu::Menu(RenderWindow& mainWindow) : window(mainWindow)
{
	bgTex = loadBackgroundTexture(1);

	background.setTexture(bgTex);
	background.setScale(6.3f, 6.3f);

	font = loadFont();
}

void Menu::drawMainMenu()
{
	Event event;
	Vector2f windowSize = Vector2f(window.getSize());

	titleText.setFont(font);
	titleText.setString("EPOCH");
	titleText.setCharacterSize(180);
	titleText.setPosition(float(windowSize.x / 3.3), 100);
	titleText.setFillColor(Color::White);
	titleText.setStyle(Text::Bold);

	subText1.setFont(font);
	subText1.setString("PLAY");
	subText1.setCharacterSize(80);
	subText1.setPosition(float(windowSize.x / 2.3), windowSize.y - 500);
	subText1.setFillColor(Color::White);
	subText1.setStyle(Text::Regular);

	subText2.setFont(font);
	subText2.setString("EXIT");
	subText2.setCharacterSize(80);
	subText2.setPosition(float(windowSize.x / 2.27), windowSize.y - 350);
	subText2.setFillColor(Color::White);
	subText2.setStyle(Text::Regular);

	button1.setSize(Vector2f(220.0f, 100.0f));
	button1.setOutlineColor(Color::White);
	button1.setOutlineThickness(10);
	button1.setFillColor(Color::Transparent);
	button1.setPosition(float(windowSize.x / 2.35), windowSize.y - 495);

	button2.setSize(Vector2f(220.0f, 100.0f));
	button2.setOutlineColor(Color::White);
	button2.setOutlineThickness(10);
	button2.setFillColor(Color::Transparent);
	button2.setPosition(float(windowSize.x / 2.35), windowSize.y - 345);


	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
				window.close();

			if (event.type == Event::MouseMoved)
			{
				if (button1.getGlobalBounds().contains(float(event.mouseMove.x), float(event.mouseMove.y)))
				{
					button1.setOutlineThickness(15);
					subText1.setStyle(Text::Bold);
				}
				else
				{
					button1.setOutlineThickness(10);
					subText1.setStyle(Text::Regular);
				}

				if (button2.getGlobalBounds().contains(float(event.mouseMove.x), float(event.mouseMove.y)))
				{
					button2.setOutlineThickness(15);
					subText2.setStyle(Text::Bold);
				}
				else
				{
					button2.setOutlineThickness(10);
					subText2.setStyle(Text::Regular);
				}
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (button1.getGlobalBounds().contains(float(event.mouseButton.x), float(event.mouseButton.y)))
					return;

				if (button2.getGlobalBounds().contains(float(event.mouseButton.x), float(event.mouseButton.y)))
					window.close();
			}
		}

		window.clear();

		window.draw(background);

		window.draw(titleText);
		window.draw(button1);
		window.draw(subText1);
		window.draw(button2);
		window.draw(subText2);

		window.display();
	}
}

void Menu::drawWinScreen()
{
	Event event;
	Vector2f windowSize = Vector2f(window.getSize());

	titleText.setFont(font);
	titleText.setString("You Win!");
	titleText.setCharacterSize(150);
	titleText.setPosition(windowSize.x / 4, 100);
	titleText.setFillColor(Color::White);
	titleText.setStyle(Text::Bold);

	subText1.setFont(font);
	subText1.setString("Press Esc to Exit...");
	subText1.setCharacterSize(50);
	subText1.setPosition(float(windowSize.x / 3), windowSize.y - 200);
	subText1.setFillColor(Color::White);
	subText1.setStyle(Text::Regular);

	bgTex = loadBackgroundTexture(6);

	background.setTexture(bgTex);
	background.setScale(5, 5);

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
		window.draw(subText1);

		window.display();
	}
}