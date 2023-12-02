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
}

void Wall::movePlayer(Player& player)
{
    FloatRect playerBounds = player.getGlobalBounds();
    FloatRect wallBounds = sprite.getGlobalBounds();

    if (playerBounds.intersects(wallBounds))
    {
        //Bottom Collision
        if (playerBounds.top < wallBounds.top
            && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
            && playerBounds.left < wallBounds.left + wallBounds.width
            && playerBounds.left + playerBounds.width > wallBounds.left)
        {
            player.setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
        }

        //Top Collision
        else if (playerBounds.top > wallBounds.top
            && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
            && playerBounds.left < wallBounds.left + wallBounds.width
            && playerBounds.left + playerBounds.width > wallBounds.left)
        {
            player.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
        }

        //Right Collision
        else if (playerBounds.left < wallBounds.left
            && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
            && playerBounds.top < wallBounds.top + wallBounds.height
            && playerBounds.top + playerBounds.height > wallBounds.top)
        {
            player.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
        }

        //Left Collision
        else if (playerBounds.left > wallBounds.left
            && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
            && playerBounds.top < wallBounds.top + wallBounds.height
            && playerBounds.top + playerBounds.height > wallBounds.top)
        {
            player.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
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
}

FloatRect Wall::getCollisionBounds()
{
	return sprite.getGlobalBounds();
}

void Wall::drawTo(RenderWindow& window) const
{
	window.draw(sprite);
}
