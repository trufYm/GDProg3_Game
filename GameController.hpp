#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class GameController
{
private:
    RenderWindow window;
    Player player;
    Texture backgroundTexture;
    Sprite background;
    Music music;
    //Clock clock;  needed in future for real-time updating

public:
    GameController()
    {
        //Default constructor
        if (!backgroundTexture.loadFromFile("grass-bg.jpg"))
        {
            cout << "Error loading background." << endl;
        }

        if (!music.openFromFile("holoBossaNova.wav"))
        {
            cout << "Error loading music file." << endl;
        }
        music.play();

        Vector2u size = backgroundTexture.getSize();
        background.setTexture(backgroundTexture);

        window.create(VideoMode(size.x, size.y), "GDPROG3 MCO1 PROTOTYPE");
        //window.setFramerateLimit(60);     used for testing framerate independent gameplay
    }

    void render()
    {
        window.clear();
        window.draw(background);
        player.drawTo(window);
        player.update();
        window.display();
    }

    //Handles events and sends them to appropriate function
    void eventHandler(Event event)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::KeyPressed)
            {
                player.processEvents(event.key.code, true);
            }
            else if (event.type == Event::KeyReleased)
            {
                player.processEvents(event.key.code, false);
            }
        }
    }

    void run()
    {
        while (window.isOpen())
        {
            Event event{};
            eventHandler(event);
            render();
        }
    }

};