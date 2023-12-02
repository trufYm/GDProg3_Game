#include <Follower.hpp>

Follower::Follower(Vector2f mapSize, int era)
{
	random_device random;

	pos.x = random() % int(mapSize.x - 500);
	pos.y = random() % int(mapSize.y - 500);

	currentEra = era;

	texture = loadResourceTexture(currentEra);

	rect.setTexture(texture);
	rect.setScale(1.5, 1.5);
	rect.setPosition(pos);

	playerCollided = false;

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

/*Change follower texture to new era texture.
Texture is different depending on if object is resource or follower*/
void Follower::changeCurrentEra(int era)
{
	//Don't change texture
	if (currentEra == era)
		return;

	currentEra = era;

	if (playerCollided)
		texture = loadFollowerTexture(currentEra);

	else
		texture = loadResourceTexture(currentEra);

	rect.setTexture(texture);
}

//Change resource to follower
void Follower::changeToFollower()
{
	playerCollided = true;

	texture = loadFollowerTexture(currentEra);

	rect.setTexture(texture);
}

//HELPER FUNCTIONS

FloatRect Follower::getGlobalBounds()
{
	return rect.getGlobalBounds();
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

void Follower::setBuffer(float num)
{
	buffer = num;
}
