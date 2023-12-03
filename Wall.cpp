#include <Wall.hpp>

//Note for future: maybe new class obstacle inherits from wall

Wall::Wall(Vector2f mapSize, int ver)
{
    currentEra = 1;

    random_device random;

    version = ver;

    pos.x = float(random() % int(mapSize.x));
    pos.y = float(random() % int(mapSize.y));

    if (version == 0)
    {
        texture = loadWallTexture(currentEra);

        sprite.setTexture(texture);
        sprite.setScale(3, 3);
        sprite.setPosition(pos);

        collisionRect.top = sprite.getGlobalBounds().top + 50;
        collisionRect.left = sprite.getGlobalBounds().left + 45;
        collisionRect.height = sprite.getGlobalBounds().height - 50;
        collisionRect.width = sprite.getGlobalBounds().width - 80;
    }

    else if (version == 1)
    {
        texture = loadObstTexture(currentEra);

        sprite.setTexture(texture);
        sprite.setScale(2, 2);
        sprite.setPosition(pos);

        collisionRect.top = sprite.getGlobalBounds().top;
        collisionRect.left = sprite.getGlobalBounds().left;
        collisionRect.height = sprite.getGlobalBounds().height;
        collisionRect.width = sprite.getGlobalBounds().width;
    }
}

void Wall::changeCollisionBounds()
{
    switch (currentEra)
    {
    case 1:
        collisionRect.top = sprite.getGlobalBounds().top + 50;
        collisionRect.left = sprite.getGlobalBounds().left + 45;
        collisionRect.height = sprite.getGlobalBounds().height - 40;
        collisionRect.width = sprite.getGlobalBounds().width - 80;
        break;

    case 2:
        collisionRect.top = sprite.getGlobalBounds().top + 40;
        collisionRect.left = sprite.getGlobalBounds().left + 40;
        collisionRect.height = sprite.getGlobalBounds().height - 90;
        collisionRect.width = sprite.getGlobalBounds().width - 70;
        break;
       
    case 3:
        collisionRect.top = sprite.getGlobalBounds().top + 30;
        collisionRect.left = sprite.getGlobalBounds().left + 45;
        collisionRect.height = sprite.getGlobalBounds().height - 40;
        collisionRect.width = sprite.getGlobalBounds().width - 80;
        break;

    case 4:
        collisionRect.top = sprite.getGlobalBounds().top + 60;
        collisionRect.left = sprite.getGlobalBounds().left + 45;
        collisionRect.height = sprite.getGlobalBounds().height - 80;
        collisionRect.width = sprite.getGlobalBounds().width - 80;
        break;

    case 5:
        collisionRect.top = sprite.getGlobalBounds().top + 30;
        collisionRect.left = sprite.getGlobalBounds().left + 45;
        collisionRect.height = sprite.getGlobalBounds().height - 50;
        collisionRect.width = sprite.getGlobalBounds().width - 75;
        break;
    }
}

void Wall::movePlayer(Player& player) const
{
    FloatRect playerBounds = player.getGlobalBounds();

    if (playerBounds.intersects(collisionRect))
    {
        //Bottom Collision
        if (playerBounds.top < collisionRect.top
            && playerBounds.top + playerBounds.height < collisionRect.top + collisionRect.height
            && playerBounds.left                      < collisionRect.left + collisionRect.width
            && playerBounds.left + playerBounds.width > collisionRect.left)
        {
            player.setPosition(playerBounds.left, collisionRect.top - playerBounds.height);
        }

        //Top Collision
        else if (playerBounds.top > collisionRect.top
            && playerBounds.top + playerBounds.height > collisionRect.top + collisionRect.height
            && playerBounds.left                      < collisionRect.left + collisionRect.width
            && playerBounds.left + playerBounds.width > collisionRect.left)
        {
            player.setPosition(playerBounds.left, collisionRect.top + collisionRect.height);
        }

        //Right Collision
        else if (playerBounds.left < collisionRect.left
            && playerBounds.left + playerBounds.width < collisionRect.left + collisionRect.width
            && playerBounds.top                       < collisionRect.top + collisionRect.height
            && playerBounds.top + playerBounds.height > collisionRect.top)
        {
            player.setPosition(collisionRect.left - playerBounds.width, playerBounds.top);
        }

        //Left Collision
        else if (playerBounds.left > collisionRect.left
            && playerBounds.left + playerBounds.width > collisionRect.left + collisionRect.width
            && playerBounds.top                       < collisionRect.top + collisionRect.height
            && playerBounds.top + playerBounds.height > collisionRect.top)
        {
            player.setPosition(collisionRect.left + collisionRect.width, playerBounds.top);
        }
    }
}

void Wall::changeCurrentEra(int era)
{
    //Don't change texture
    if (currentEra == era)
        return;

    currentEra = era;

    if (version == 0)
        texture = loadWallTexture(currentEra);

    if (version == 1)
        texture = loadObstTexture(currentEra);

    sprite.setTexture(texture);
    
    if (version == 0)
        changeCollisionBounds();
}

void Wall::drawTo(RenderWindow& window) const
{
	window.draw(sprite);
}
