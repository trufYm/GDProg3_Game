#include <GameController.hpp>

GameController::GameController()
{
    window.create(VideoMode(1280, 960), "GDPROG3 MCO");
    window.setFramerateLimit(60);     //used for testing framerate independent gameplay

    view1.setSize(1280, 960);

    time_interval = 0;

    //resource.playMusic();

    currentEra = 1;

    for (int i = 0; i < 80; i++)
    {
        Wall* newWall = new Wall(map.getMapBorder());

        wallList.push_back(newWall);
    }
}

/*Detect collision between npc (follower) object and player.
If collided, copy npc instance to follower vector and delete the instance*/
void GameController::detectPlayerCollision()
{
    for (int i = 0; i < npcList.size(); i++)
    {
        if ((*npcList[i]).getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            (*npcList[i]).changeToFollower();

            followerList.push_back(npcList[i]);

            npcList.erase(npcList.begin() + i);
        }
            
    }

    for (int i = 0; i < wallList.size(); i++)
    {
        (*wallList[i]).movePlayer(player);
    }
}

//Check how many followers player has and change era accordingly
void GameController::checkFollowerCount()
{
    if (followerList.size() >= 11 && followerList.size() < 20)
    {
        currentEra = 2;
        player.changeCurrentEra(currentEra);
    }
        
    else if (followerList.size() >= 21 && followerList.size() < 30)
    {
        currentEra = 3;
        player.changeCurrentEra(currentEra);
    }
        
    else if (followerList.size() >= 31 && followerList.size() < 40)
    {
        currentEra = 4;
        player.changeCurrentEra(currentEra);
    }

    else if (followerList.size() >= 41 && followerList.size() < 50)
    {
        currentEra = 5;
        player.changeCurrentEra(currentEra);
    }

    //Probably (definitely) inefficient but :D
    for (int i = 0; i < followerList.size(); i++)
    {
        (*followerList[i]).changeCurrentEra(currentEra);
    }

    for (int i = 0; i < npcList.size(); i++)
    {
        (*npcList[i]).changeCurrentEra(currentEra);
    }

    for (int i = 0; i < wallList.size(); i++)
    {
        (*wallList[i]).changeCurrentEra(currentEra);
    }

    if (followerList.size() == 50)
        menu.drawWinScreen(window);
}

//Updates current gamestate
void GameController::updateGameState()
{
    //Update player's position based on movement
    player.movePlayer();

    detectPlayerCollision();

    //Gets time in between frames
    float dt = clock.restart().asSeconds();
    time_interval += dt;

    //Tell follower objects to follow player once collided
    for (int i = 0; i < followerList.size(); i++)
    {
        (*followerList[i]).setBuffer(60.0f + (i * 20));
        (*followerList[i]).followPlayer(player.getPosition(), dt);
    }

    checkFollowerCount();

    //Spawn new follower object after 0.9 secs
    if (time_interval >= 0.9)
    {
        Follower* newEntity = new Follower(map.getMapBorder(), currentEra);

        npcList.push_back(newEntity);

        time_interval = 0;
    }

    //Check if player has gone past map bounds
    map.detectPlayer(&player, followerList);
}

//Draws all elements and sets window view
void GameController::drawElementsToWindow()
{
    window.clear();
    window.setView(view1);
    
    map.drawTo(window);

    updateGameState();

    view1.setCenter(player.getPosition());

    for (int i = 0; i < npcList.size(); i++)
    {
        (*npcList[i]).drawTo(window);
    }

    for (int i = 0; i < followerList.size(); i++)
    {
        (*followerList[i]).drawTo(window);
    }

    player.drawTo(window);

    for (int i = 0; i < wallList.size(); i++)
    {
        (*wallList[i]).drawTo(window);
    }

    window.display();
}

//Handles events and sends them to appropriate function
void GameController::eventHandler(Event event)
{
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
            window.close();

        if (event.type == Event::KeyPressed)
            player.processInput(event.key.code, true);

        if (event.type == Event::KeyReleased)
            player.processInput(event.key.code, false);
    }
}

//Run *beat drops* ez4ence ence ence
void GameController::gameLoop()
{
    menu.drawMainMenu(window);

    while (window.isOpen())
    {
        Event event{};
        eventHandler(event);

        drawElementsToWindow();
    }
}