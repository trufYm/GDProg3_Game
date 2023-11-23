#ifndef FOLLOWER_H
#define FOLLOWER_H

class Follower : protected ResourceManager
{
private:
	Sprite rect;
	Texture texture;
	Vector2f pos;
	Player player;

	bool playerCollided = false;
	bool npcCollided = false;

	float buffer = 60.0f;

public:
	Follower()
	{
		pos.x = 300;
		pos.y = 300;

		rect.setTexture(texture);
		rect.setPosition(pos);
	}

	Follower(Vector2f size, Texture* texture)
	{
		random_device random;

		Vector2u mapSize = Vector2u(size);

		pos.x = random() % mapSize.x;
		pos.y = random() % mapSize.y;

		rect.setTexture(*texture);
		rect.setPosition(pos);
	}

	/*Take player's current position and move towards it.
	Uses same frame independent movement as player.
	Buffer value is to separate follower from player sprite*/
	void followPlayer(Vector2f playerPos, float dt)
	{
		Vector2f currentPos = rect.getPosition();
		Vector2f movement(0,0);

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

	FloatRect getGlobalBounds()
	{
		return rect.getGlobalBounds();
	}

	void setPlayerCollided(bool state)
	{
		playerCollided = state;
	}

	bool hasPlayerCollided() const
	{
		return playerCollided;
	}

	void drawTo(RenderWindow& window) const
	{
		window.draw(rect);
	}

	void setPosition(Vector2f pos)
	{
		rect.setPosition(pos.x, pos.y);
	}

	void setPosition(float x, float y)
	{
		rect.setPosition(x, y);
	}

	void setBuffer(float num)
	{
		buffer = num;
	}

};

#endif