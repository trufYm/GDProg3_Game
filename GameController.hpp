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

    ResourceManager resource;

    Music music;

    vector<Follower *> npcList;
    vector<Follower*> followerList;
    Clock clock;

    View view1;
    
    float time_interval;

public:
    GameController();

    void detectPlayerCollision();

    void npcCounter() const;

    void render();

    void logicUpdate();

    void eventHandler(Event event);

    void run();

};

#endif // !GAMECONTROLLER_H