#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ResourceManager.hpp>
#include <Player.hpp>
#include <Follower.hpp>
#include <Map.hpp>
#include <Wall.hpp>
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

    vector<Wall*> wallList, obstList;

    Clock clock;

    View view1;

    Sprite rocket;

    Texture rocketTex;

    RectangleShape rect;

    float time_interval;
    
    int currentEra, oldEra;

public:
    GameController();

    void detectPlayerCollision();

    void checkFollowerCount();

    void updateGameState();

    void drawWinTransition();

    void drawElementsToWindow();

    void eventHandler(Event event);

    void gameLoop();
};

#endif // !GAMECONTROLLER_H