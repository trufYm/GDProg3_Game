#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

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
    
    float time_interval = 0; //used to get time between npc spawns

public:
    GameController()
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
    }

    //Detect collision between follower object and player
    void detectPlayerCollision()
    {
        for (int i = 0; i < npcList.size(); i++)
        {
            if ((*npcList[i]).getGlobalBounds().intersects(player.getGlobalBounds()))
            {
                (*npcList[i]).setBuffer(60.0f + (i * 20));
                (*npcList[i]).setPlayerCollided(true);
            }
        }
    }

    //Draws all elements and sets window
    void render()
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

        player.drawTo(window);

        window.display();
    }

    //Updates current gamestate
    void logicUpdate()
    {
        player.update();

        detectPlayerCollision();

        float dt = clock.restart().asSeconds();
        time_interval += dt;

        //Tell follower objects to follower player once collided
        for (int i = 0; i < npcList.size(); i++)
        {
            if ((*npcList[i]).hasPlayerCollided())
            {
                (*npcList[i]).followPlayer(player.getPosition(), dt);
            }
        }

        //Spawn new follower object after 0.9 secs
        if (time_interval >= 0.9)
        {
            //Follower newEntity(size, &followerTexture);

            Follower* newEntity = new Follower(mapSize, &followerTexture);

            npcList.push_back(newEntity);
           
            time_interval = 0;
        }

        map.detectPlayer(&player, npcList);
    }

    //Handles events and sends them to appropriate function
    void eventHandler(Event event)
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
    void run()
    {
        while (window.isOpen())
        {
            Event event{};
            eventHandler(event);
            render();
            
        }
    }

};

#endif // !GAMECONTROLLER_H