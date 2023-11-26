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
    string playerName;
    Texture texture;
    Sprite sprite;
    Clock clock;

    float speed;

    bool up;
    bool down;
    bool left;
    bool right;

public:
    Player();

    void processEvents(Keyboard::Key key, bool isPressed);

    void update();

    void drawTo(RenderWindow& window) const;

    Vector2f getPosition();

    FloatRect getGlobalBounds();

    float getSpeed() const;

    void setPosition(Vector2f pos);
};

#endif // !PLAYER_H