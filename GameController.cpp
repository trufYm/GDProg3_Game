#include <GameController.hpp>

GameController::GameController()
{
    //Getting sprites and needed files
    if (!backgroundTexture.loadFromFile("grass-bg.jpg"))
        cout << "Error loading background." << endl;

    if (!music.openFromFile("holoBossaNova.wav"))
        cout << "Error loading music file." << endl;

    if (!followerTexture.loadFromFile("akame(2).png"))
        cout << "Error loading follower texture" << endl;

    music.play();

    background.setTexture(backgroundTexture);

    window.create(VideoMode(1280, 960), "GDPROG3 MCO");
    //window.setFramerateLimit(30);     //used for testing framerate independent gameplay

    view1.setSize(1280, 960);

    mapSize = Vector2f(backgroundTexture.getSize());

    map.setMapSize(mapSize);

    time_interval = 0;
}

//Detect collision between follower object and player
void GameController::detectPlayerCollision()
{
    for (int i = 0; i < npcList.size(); i++)
    {
        if ((*npcList[i]).getGlobalBounds().intersects(player.getGlobalBounds()))
        {
            (*npcList[i]).setPlayerCollided(true);

            Follower* newFollower = npcList[i];

            followerList.push_back(newFollower);

            npcList.erase(npcList.begin() + i);
        }
            
    }
}

//Check if player has won
void GameController::npcCounter() const
{
    if (followerList.size() >= 11 && followerList.size() < 20)
        cout << "Entered ancient era!" << endl;

    else if (followerList.size() >= 21 && followerList.size() < 30)
        cout << "Entered medieval era!" << endl;

    else if (followerList.size() >= 31 && followerList.size() < 40)
        cout << "Entered pre-modern era!" << endl;

    else if (followerList.size() >= 41 && followerList.size() < 50)
        cout << "Entered modern era!" << endl;

    else if (followerList.size() == 50)
        cout << "You've won!" << endl;
}

//Draws all elements and sets window
void GameController::render()
{
    window.clear();
    window.setView(view1);
    window.draw(background);

    logicUpdate();

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

    window.display();
}

//Updates current gamestate
void GameController::logicUpdate()
{
    player.update();

    detectPlayerCollision();

    float dt = clock.restart().asSeconds();
    time_interval += dt;

    //Tell follower objects to follow player once collided
    for (int i = 0; i < followerList.size(); i++)
    {
        if ((*followerList[i]).hasPlayerCollided())
        {
            (*followerList[i]).setBuffer(60.0f + (i * 20));
            (*followerList[i]).followPlayer(player.getPosition(), dt);
        }   
    }

    npcCounter();

    //Spawn new follower object after 0.9 secs
    if (time_interval >= 0.9)
    {
        Follower* newEntity = new Follower(mapSize, &followerTexture);

        npcList.push_back(newEntity);

        time_interval = 0;
    }

    map.detectPlayer(&player, followerList);
}

//Handles events and sends them to appropriate function
void GameController::eventHandler(Event event)
{
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed || event.key.code == Keyboard::Escape)
            window.close();

        if (event.type == Event::KeyPressed)
            player.processEvents(event.key.code, true);

        if (event.type == Event::KeyReleased)
            player.processEvents(event.key.code, false);
    }
}

//Run *beat drops* ez4ence ence ence
void GameController::run()
{
    while (window.isOpen())
    {
        Event event{};
        eventHandler(event);
        render();
    }
}
