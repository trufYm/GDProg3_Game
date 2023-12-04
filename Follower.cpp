#include <Follower.hpp>

//Note for future: maybe new class resource inherits from follower

Follower::Follower(Vector2f mapSize, int era)
{
	pos.x = float(random() % int(mapSize.x + 300));
	pos.y = float(random() % int(mapSize.y - 300));

	currentEra = era;

	texture = loadResourceTexture(currentEra);

	rect.setTexture(texture);
	rect.setScale(1.5, 1.5);
	rect.setPosition(pos);

	playerCollided = false;
	buffer = 60.0f;
	mult = 60.f;
	time_interval = 0;
	noiseTime = 0;
}


//Move randomly while still a resource, can move in any of the 8 directions
void Follower::moveAsResource(float dt)
{
	time_interval += dt;

	int speed = random() % 6;

	float step = speed * dt * mult;

	if (int(time_interval) % 8 == 0)
		rect.move(0, step);
	else if (int(time_interval) % 8 == 1)
		rect.move(0, -step);
	else if (int(time_interval) % 8 == 2)
		rect.move(step, 0);
	else if (int(time_interval) % 8 == 3)
		rect.move(-step, 0);
	else if (int(time_interval) % 8 == 4)
		rect.move(step, step);
	else if (int(time_interval) % 8 == 5)
		rect.move(-step, -step);
	else if (int(time_interval) % 8 == 6)
		rect.move(step, -step);
	else if (int(time_interval) % 8 == 7)
		rect.move(-step, step);
}

/*Take player's current position and move towards it.
Uses same frame independent movement as player.
Buffer value is to separate follower from player sprite*/
void Follower::followPlayer(Vector2f playerPos, float dt)
{
	Vector2f currentPos = rect.getPosition();
	Vector2f movement(0, 0);
	
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


		//Check every 5 seconds for 1/50 chance to play follower noise
		noiseTime += dt;

		if (noiseTime >= 5)
		{
			int rng = random() % 40;

			if (rng == 6)
				playFollowerNoise();

			noiseTime = 0;
		}
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

	playFollowerNoise();
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
