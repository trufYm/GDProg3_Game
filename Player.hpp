#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Player
{
private:
    string playerName;
    Texture texture;
    Sprite sprite;
    Clock clock;
    Follower npc;
    float xPos = 200, yPos = 200;

    //will be adjusted with buffs, will need setSpeed function later
    int speed = 10;

    //for movement
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    //for framerate independent movement
    float dt = 0;
    float mult = 60.f;

public:
    Player()
    {
        //Default constructor
        if (!texture.loadFromFile("donpersimmon.png"))
            cout << "Error loading player texture." << endl;

        sprite.setTexture(texture);
        sprite.setPosition(xPos, yPos);
    }

    Player(string name)
    {
        playerName = name;
        if (!texture.loadFromFile("donpersimmon.png"))
            cout << "Error loading player texture." << endl;

        sprite.setTexture(texture);
        sprite.setPosition(xPos, yPos);
    }

    void processEvents(Keyboard::Key key, bool isPressed)
    {
        if (isPressed)
        {
            if (key == Keyboard::W)
                up = true;
            if (key == Keyboard::A)
                left = true;
            if (key == Keyboard::S)
                down = true;
            if (key == Keyboard::D)
                right = true;
        }
        else
        {
            up = false;
            down = false;
            left = false;
            right = false;
        }
    }

    void detectCollision()
    {
        FloatRect playerBounds = sprite.getGlobalBounds();
        FloatRect npcBounds = npc.getGlobalBounds();

        if (npcBounds.intersects(playerBounds))
        {
            cout << "Collision!" << endl;

            //Bottom Collision
            if (playerBounds.top < npcBounds.top
                && playerBounds.top + playerBounds.height < npcBounds.top + npcBounds.height
                && playerBounds.left < npcBounds.left + npcBounds.width
                && playerBounds.left + playerBounds.width > npcBounds.left)
            {
                sprite.setPosition(playerBounds.left, npcBounds.top - playerBounds.height);
            }

            //Top Collision
            else if (playerBounds.top > npcBounds.top
                && playerBounds.top + playerBounds.height > npcBounds.top + npcBounds.height
                && playerBounds.left < npcBounds.left + npcBounds.width
                && playerBounds.left + playerBounds.width > npcBounds.left)
            {
                sprite.setPosition(playerBounds.left, npcBounds.top + npcBounds.height);
            }

            //Right Collision
            else if (playerBounds.left < npcBounds.left
                && playerBounds.left + playerBounds.width < npcBounds.left + npcBounds.width
                && playerBounds.top < npcBounds.top + npcBounds.height
                && playerBounds.top + playerBounds.height > npcBounds.top)
            {
                sprite.setPosition(npcBounds.left - playerBounds.width, playerBounds.top);
            }

            //Left Collision
            else if (playerBounds.left > npcBounds.left
                && playerBounds.left + playerBounds.width > npcBounds.left + npcBounds.width
                && playerBounds.top < npcBounds.top + npcBounds.height
                && playerBounds.top + playerBounds.height > npcBounds.top)
            {
                sprite.setPosition(npcBounds.left + npcBounds.width, playerBounds.top);
            }
        }
    }

    void update()
    {
        Vector2f movement;
        dt = clock.restart().asSeconds();
        if (up)
            movement.y -= speed * dt * mult;
        if (down)
            movement.y += speed * dt * mult;
        if (left)
            movement.x -= speed * dt * mult;
        if (right)
            movement.x += speed * dt * mult;

        sprite.move(movement);
    }

    void drawTo(RenderWindow &window)
    {
        window.draw(sprite);
    }

    Sprite getSprite()
    {
        return sprite;
    }
};