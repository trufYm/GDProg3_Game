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

        Vector2u size = backgroundTexture.getSize(); //Should change this to make background size depend on window size

        background.setTexture(backgroundTexture);

        window.create(VideoMode(size.x, size.y), "GDPROG3 MCO1 PROTOTYPE");
        //window.setFramerateLimit(20);     //used for testing framerate independent gameplay
    }

    //Detect collision between follower object and player
    void detectCollision()
    {
        if (npc.getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            npc.setCollided(true);
        }
    }

    //Does everything as of the moment. Draws all elements and updates current gamestate.
    void render()
    {
        window.clear();
        window.draw(background);
        
        player.update();

        detectCollision();
       
        if (npc.hasCollided())
        {
            npc.followPlayer(player.getPosition());
        }

        player.drawTo(window);
        npc.drawTo(window);

        window.display();
    }

    /*void logicUpdate()
    {
        
        Might be needed in the future???
        Idk a logicUpdate function sounds like a good thing to have to
        separate draw and update/logic methods
        
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

    //Run *beat drops*
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