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
#include <Menu.hpp>

using namespace std;
using namespace sf;

class GameController
{
private:
    RenderWindow window;
    
    Player player;

    Map map;

    ResourceManager resource;

    Menu menu;

    vector<Follower*> npcList, followerList;

    Clock clock;

    View view1;

    float time_interval;
    
    int currentEra;

public:
    GameController();

    void detectPlayerCollision();

    void checkFollowerCount();

    void updateGameState();

    void drawElementsToWindow();

    void eventHandler(Event event);

    void gameLoop();

};

#endif // !GAMECONTROLLER_H