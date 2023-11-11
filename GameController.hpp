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
    vector<Follower> npcList;
    Clock clock;
    int followerCount = 0;

public:
    GameController()
    {
        //Default constructor
        if (!backgroundTexture.loadFromFile("grass-bg.jpg"))
            cout << "Error loading background." << endl;

        if (!music.openFromFile("holoBossaNova.wav"))
            cout << "Error loading music file." << endl;

        music.play();

        Vector2u size = backgroundTexture.getSize(); //Should change this to make background size depend on window size

        background.setTexture(backgroundTexture);

        window.create(VideoMode(size.x, size.y), "GDPROG3 MCO1 PROTOTYPE");
        //window.setFramerateLimit(30);     //used for testing framerate independent gameplay
    }

    //Detect collision between follower object and player
    void detectPlayerCollision()
    {
        for (int i = 0; i < npcList.size(); i++)
        {
            if (npcList[i].getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                npcList[i].setCollided(true);
            }
        }
    }

    //Draws all elements
    void render()
    {
        window.clear();
        window.draw(background);

        logicUpdate();
        
        for (int i = 0; i < npcList.size(); i++)
        {
            npcList[i].drawTo(window);
        }

        player.drawTo(window);
        
        window.display();
    }

    //Updates current gamestate
    void logicUpdate()
    {
        player.update();

        detectPlayerCollision();

        float dt = clock.restart().asSeconds();

        if (followerCount < 5)
        {
            Follower entity(window);

            npcList.push_back(entity);
            followerCount++;
        }

        for (int i = 0; i < npcList.size(); i++)
        {
            if (npcList[i].hasCollided())
            {
                npcList[i].followPlayer(player.getPosition(), dt);
                followerCount--;
            }
        }

    }

    //Handles events and sends them to appropriate function
    void eventHandler(Event event)
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
                window.close();

            if (event.type == Event::KeyPressed)
                player.processEvents(event.key.code, true);

            if (event.type == Event::KeyReleased)
                player.processEvents(event.key.code, false);
        }
    }

     //Run *beat drops* ez4ence ence ence
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