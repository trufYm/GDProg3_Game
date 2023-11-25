#include <Follower.hpp>

Follower::Follower()
{
	pos.x = 300;
	pos.y = 300;

	rect.setTexture(texture);
	rect.setPosition(pos);

	playerCollided = false;
	npcCollided = false;

	buffer = 60.0f;
}

Follower::Follower(Vector2f size)
{
	random_device random;

	Vector2u mapSize = Vector2u(size);

	pos.x = random() % mapSize.x;
	pos.y = random() % mapSize.y;

	texture = loadFollowerTexture();

	rect.setTexture(texture);
	rect.setPosition(pos);

	playerCollided = false;
	npcCollided = false;

	buffer = 60.0f;
}

/*Take player's current position and move towards it.
Uses same frame independent movement as player.
Buffer value is to separate follower from player sprite*/
void Follower::followPlayer(Vector2f playerPos, float dt)
{
	Vector2f currentPos = rect.getPosition();
	Vector2f movement(0, 0);

	float mult = 60.f;

	if (playerCollided)
	{
		float step = (player.getSpeed() * 0.95f) * dt * mult;

		if (playerPos.x > currentPos.x + buffer)
			movement.x += step;
		else if (playerPos.x < currentPos.x - buffer)
			movement.x -= step;

		if (playerPos.y > currentPos.y + buffer)
			movement.y += step;
		else if (playerPos.y < currentPos.y - buffer)
			movement.y -= step;

		if (movement.x != 0 || movement.y != 0)
			rect.move(movement);
	}
}

//HELPER FUNCTIONS

FloatRect Follower::getGlobalBounds()
{
	return rect.getGlobalBounds();
}

void Follower::setPlayerCollided(bool state)
{
	playerCollided = state;
}

	bool Follower::hasPlayerCollided() const
{
	return playerCollided;
}

void Follower::drawTo(RenderWindow& window) const
{
	window.draw(rect);
}

void Follower::setPosition(Vector2f pos)
{
	rect.setPosition(pos.x, pos.y);
}

void Follower::setPosition(float x, float y)
{
	rect.setPosition(x, y);
}

void Follower::setBuffer(float num)
{
	buffer = num;
}
