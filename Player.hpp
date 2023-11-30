#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>

using namespace std;
using namespace sf;

class Player : protected ResourceManager
{
private:
    Texture texture;
    Sprite sprite;
    Clock clock;

    float speed;

    bool up,
        down,
        left,
        right;

public:
    Player();

    void processInput(Keyboard::Key key, bool isPressed);

    void movePlayer();

    void drawTo(RenderWindow& window) const;

    Vector2f getPosition();

    FloatRect getGlobalBounds();

    float getSpeed() const;

    void setPosition(Vector2f pos);

    void changeSpriteTexture(int currentEra);
};

#endif // !PLAYER_H