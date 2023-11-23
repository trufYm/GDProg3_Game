#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>
#include <Player.hpp>
#include <Follower.hpp>
#include <Map.hpp>

using namespace std;
using namespace sf;

class GameController
{
private:
    RenderWindow window;
    
    Player player;

    Map map;

    Texture backgroundTexture;
    Texture followerTexture;

    ResourceManager resource;

    Sprite background;
    Music music;

    vector<Follower *> npcList;
    Clock clock;

    View view1;
    Vector2f mapSize;
    
    float time_interval;

public:
    GameController();

    void detectPlayerCollision();

    void render();

    void logicUpdate();

    void eventHandler(Event event);

    void run();

};

#endif // !GAMECONTROLLER_H