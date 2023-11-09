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
    //Vector2f pos;

    //will be adjusted with buffs, will need setSpeed function later
    float speed = 10;

    //for movement
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    //for framerate independent movement
    float dt = 0;
    float mult = 60.f;

public:
    Player() //Default constructor
    {
        if (!texture.loadFromFile("donpersimmon.png"))
            cout << "Error loading player texture." << endl;

        //pos.x = 200;
        //pos.y = 200;

        sprite.setTexture(texture);
        sprite.setPosition(200, 200);
    }

    Player(string name)
    {
        playerName = name;
        if (!texture.loadFromFile("donpersimmon.png"))
            cout << "Error loading player texture." << endl;

        //pos.x = 200;
        //pos.y = 200;

        sprite.setTexture(texture);
        sprite.setPosition(200, 200);
    }

    //Process keyboard input
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

    /*Main movement function, takes current speed value and multiplies by delta time
    and a multiplier (depending on desired FPS) to be independent from framerate*/
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

    //Helper functions

    void drawTo(RenderWindow& window)
    {
        window.draw(sprite);
    }

    Sprite getSprite()
    {
        return sprite;
    }

    Vector2f getPosition()
    {
        return sprite.getPosition();
    }

    FloatRect getGlobalBounds()
    {
        return sprite.getGlobalBounds();
    }

    void setPosition(float x, float y)
    {
        sprite.setPosition(x, y);
    }

    float getSpeed()
    {
        return speed;
    }
};