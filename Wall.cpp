#include <Wall.hpp>

Wall::Wall(Vector2f mapSize)
{
    currentEra = 1;

    texture = loadWallTexture(currentEra);

	random_device random;

    pos.x = random() % int(mapSize.x - 500);
    pos.y = random() % int(mapSize.y - 500);

    sprite.setTexture(texture);
    sprite.setScale(2, 2);
	sprite.setPosition(pos);

    collisionRect.top = sprite.getGlobalBounds().top + 50;
    collisionRect.left = sprite.getGlobalBounds().left + 45;
    collisionRect.height = sprite.getGlobalBounds().height - 50;
    collisionRect.width = sprite.getGlobalBounds().width - 80;
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

    case 5:
        collisionRect.top = sprite.getGlobalBounds().top + 30;
        collisionRect.left = sprite.getGlobalBounds().left + 45;
        collisionRect.height = sprite.getGlobalBounds().height - 50;
        collisionRect.width = sprite.getGlobalBounds().width - 75;
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
            && playerBounds.left < collisionRect.left + collisionRect.width
            && playerBounds.left + playerBounds.width > collisionRect.left)
        {
            player.setPosition(playerBounds.left, collisionRect.top - playerBounds.height);
        }

        //Top Collision
        else if (playerBounds.top > collisionRect.top
            && playerBounds.top + playerBounds.height > collisionRect.top + collisionRect.height
            && playerBounds.left < collisionRect.left + collisionRect.width
            && playerBounds.left + playerBounds.width > collisionRect.left)
        {
            player.setPosition(playerBounds.left, collisionRect.top + collisionRect.height);
        }

        //Right Collision
        else if (playerBounds.left < collisionRect.left
            && playerBounds.left + playerBounds.width < collisionRect.left + collisionRect.width
            && playerBounds.top < collisionRect.top + collisionRect.height
            && playerBounds.top + playerBounds.height > collisionRect.top)
        {
            player.setPosition(collisionRect.left - playerBounds.width, playerBounds.top);
        }

        //Left Collision
        else if (playerBounds.left > collisionRect.left
            && playerBounds.left + playerBounds.width > collisionRect.left + collisionRect.width
            && playerBounds.top < collisionRect.top + collisionRect.height
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

    texture = loadWallTexture(currentEra);

    sprite.setTexture(texture);

    changeCollisionBounds();
}

void Wall::drawTo(RenderWindow& window) const
{
	window.draw(sprite);
}
