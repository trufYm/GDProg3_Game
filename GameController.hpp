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
    Follower npc;
    //Clock clock;  might be needed in future for real-time updating

public:
    GameController()
    {
        //Default constructor
        if (!backgroundTexture.loadFromFile("grass-bg.jpg"))
            cout << "Error loading background." << endl;

        if (!music.openFromFile("holoBossaNova.wav"))
            cout << "Error loading music file." << endl;

        music.play();

        Vector2u size = backgroundTexture.getSize();

        background.setTexture(backgroundTexture);

        window.create(VideoMode(size.x, size.y), "GDPROG3 MCO1 PROTOTYPE");
        //window.setFramerateLimit(60);     used for testing framerate independent gameplay
    }

    //Put here because i thought problem was with different instance of Follower class in Player and GameController was fucking up collided bool
    void detectCollision()
    {
        FloatRect playerBounds = player.getGlobalBounds();
        FloatRect npcBounds = npc.getGlobalBounds();

        Follower npc;

        if (npcBounds.intersects(playerBounds))
        {
            cout << "Collision!" << endl;

            //Bottom Collision
            if (playerBounds.top < npcBounds.top
                && playerBounds.top + playerBounds.height < npcBounds.top + npcBounds.height
                && playerBounds.left < npcBounds.left + npcBounds.width
                && playerBounds.left + playerBounds.width > npcBounds.left)
            {
                npc.setCollided(true);
                player.setPosition(playerBounds.left, npcBounds.top - playerBounds.height);
            }

            //Top Collision
            else if (playerBounds.top > npcBounds.top
                && playerBounds.top + playerBounds.height > npcBounds.top + npcBounds.height
                && playerBounds.left < npcBounds.left + npcBounds.width
                && playerBounds.left + playerBounds.width > npcBounds.left)
            {
                npc.setCollided(true);
                player.setPosition(playerBounds.left, npcBounds.top + npcBounds.height);
            }

            //Right Collision
            else if (playerBounds.left < npcBounds.left
                && playerBounds.left + playerBounds.width < npcBounds.left + npcBounds.width
                && playerBounds.top < npcBounds.top + npcBounds.height
                && playerBounds.top + playerBounds.height > npcBounds.top)
            {
                npc.setCollided(true);
                player.setPosition(npcBounds.left - playerBounds.width, playerBounds.top);
            }

            //Left Collision
            else if (playerBounds.left > npcBounds.left
                && playerBounds.left + playerBounds.width > npcBounds.left + npcBounds.width
                && playerBounds.top < npcBounds.top + npcBounds.height
                && playerBounds.top + playerBounds.height > npcBounds.top)
            {
                npc.setCollided(true);
                player.setPosition(npcBounds.left + npcBounds.width, playerBounds.top);
            }
        }
    }

    void render()
    {
        window.clear();
        window.draw(background);
        
        player.update();

        detectCollision();
       
        if (npc.hasCollided())
        {
            cout << "Has collided!" << endl;
            npc.followPlayer(player.getPosition());
        }

        player.drawTo(window);
        npc.drawTo(window);

        window.display();
    }

    /*void logicUpdate()
    {
        

        
    }*/

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

    void run()
    {
        while (window.isOpen())
        {
            Event event{};
            eventHandler(event);
            render();
            //logicUpdate();
        }
    }

};