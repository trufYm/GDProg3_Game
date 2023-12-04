#include <GameController.hpp>

GameController::GameController() : menu(window)
{
    window.create(VideoMode(1280, 960), "EPOCH");
    //window.setFramerateLimit(60);     //used for testing framerate independent gameplay

    view1.setSize(1280, 960);

    time_interval = 0;

    resource.playMusic(1);

    oldEra = 0;

    currentEra = 1;

    for (int i = 0; i < 60; i++)
    {
        Wall* newWall = new Wall(map.getMapSize(), 0);

        wallList.push_back(newWall);
    }

    for (int i = 0; i < 90; i++)
    {
        Wall* newObst = new Wall(map.getMapSize(), 1);

       obstList.push_back(newObst);
    }

    rect.setFillColor(Color::Transparent);
    rect.setSize(Vector2f(1280.f, 960.f));
    rect.setScale(2, 2);
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

    for (int i = 0; i < obstList.size(); i++)
    {
        (*obstList[i]).movePlayer(player);
    }
}

//Check how many followers player has and change era accordingly
void GameController::checkFollowerCount()
{
    oldEra = currentEra;

    if (followerList.size() >= 11 && followerList.size() < 20)
        currentEra = 2;
        
    else if (followerList.size() >= 21 && followerList.size() < 30)
        currentEra = 3;
        
    else if (followerList.size() >= 31 && followerList.size() < 40)
        currentEra = 4;

    else if (followerList.size() >= 41 && followerList.size() < 50)
        currentEra = 5;

    if (currentEra != oldEra)
    {
        player.changeCurrentEra(currentEra);

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

        for (int i = 0; i < obstList.size(); i++)
        {
            (*obstList[i]).changeCurrentEra(currentEra);
        }

        map.changeCurrentEra(currentEra);

        resource.playEraChange(currentEra);
        resource.playMusic(currentEra + 1);
    }
   
    if (followerList.size() == 50)
        drawWinTransition();
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

    for (int i = 0; i < npcList.size(); i++)
    {
        (*npcList[i]).moveAsResource(dt);
    }

    //Check if player has gone past map bounds
    map.detectPlayer(&player, followerList);
}

void GameController::drawWinTransition()
{
    rocketTex = resource.loadRocket();

    rocket.setTexture(rocketTex);
    rocket.setScale(3, 3);
    rocket.setPosition(player.getPosition().x + 500.f, player.getPosition().y);

    resource.pauseMusic();
    resource.playEraChange(6);

    FloatRect rocketBounds = rocket.getGlobalBounds();
    rocketBounds.left = rocketBounds.left + 50;

    while (window.isOpen())
    {
        window.clear();
        window.setView(view1);

        view1.setCenter(player.getPosition());

        float dt = 0;

        dt = clock.restart().asSeconds();

        if (!player.getGlobalBounds().intersects(rocketBounds))
            player.autoMove();

        if (player.getGlobalBounds().intersects(rocketBounds))
        {
            player.changeSpriteColor();
            rocket.move(0, -5.f * dt * 60.f);
        }

        map.drawTo(window);
        player.drawTo(window);
        window.draw(rocket);

        window.display();

        if (rocket.getPosition().y < player.getPosition().y - float(window.getSize().y / 2) - 100.f)
        {
            menu.drawWinScreen();
        }

    }
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

    for (int i = 0; i < obstList.size(); i++)
    {
        (*obstList[i]).drawTo(window);
    }

    if (currentEra != oldEra)
    {
        rect.setPosition(player.getPosition().x - 800, player.getPosition().y - 600);
        rect.setFillColor(Color(255, 255, 51, 160));
        window.draw(rect);
        window.display();
        sleep(milliseconds(150));
        rect.setFillColor(Color::Transparent);
    }

    else
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
    menu.drawMainMenu();

    resource.playMusic(2);
    resource.playEraChange(1);

    while (window.isOpen())
    {
        Event event{};
        eventHandler(event);

        drawElementsToWindow();
    }
}