#include <Wall.hpp>

Wall::Wall(Vector2f mapSize)
{
	/*texture = loadWallTexture*/

	random_device random;

    pos.x = float(int(random()) % int(mapSize.x - 300));
    pos.y = float(int(random()) % int(mapSize.y - 300));

	currentEra = 1;

	sprite.setColor(Color::Red);
	sprite.setPosition(pos);
}

void Wall::movePlayer()
{
    FloatRect playerBounds = player.getGlobalBounds();
    FloatRect wallBounds = sprite.getGlobalBounds();

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

FloatRect Wall::getCollisionBounds()
{
	return sprite.getGlobalBounds();
}

void Wall::drawTo(RenderWindow& window) const
{
	window.draw(sprite);
}
