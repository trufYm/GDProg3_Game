#include <Map.hpp>

Map::Map()
{
	bgTexture = loadBackgroundTexture();

	background.setTexture(bgTexture);

	mapSize = Vector2f(bgTexture.getSize());
	mapBorder = { mapSize.x - 700, mapSize.y - 500 };
};

//Move player and followers to other side of map
void Map::movePlayer(Player* player, vector<Follower*>& npcList, Vector2f playerNewPos)
{
	player->setPosition(playerNewPos);

	for (int i = 0; i < (npcList).size(); i++)
	{
		if ((*npcList[i]).hasPlayerCollided())
		{
			(*npcList[i]).setPosition(playerNewPos);
		}
	}
}

//Check if player has passed the map border
void Map::detectPlayer(Player* player, vector<Follower*>& npcList)
{
	Vector2f playerOldPos = player->getPosition();
	Vector2f playerNewPos;

	if (playerOldPos.x > mapBorder.x)
	{
		playerNewPos = { 700, playerOldPos.y };
		movePlayer(player, npcList, playerNewPos);
	}

	if (playerOldPos.x < 700)
	{
		playerNewPos = { mapBorder.x, playerOldPos.y };
		movePlayer(player, npcList, playerNewPos);
	}

	if (playerOldPos.y > mapBorder.y)
	{
		playerNewPos = { playerOldPos.x, 500 };
		movePlayer(player, npcList, playerNewPos);
	}

	if (playerOldPos.y < 500)
	{
		playerNewPos = { playerOldPos.x, mapBorder.y };
		movePlayer(player, npcList, playerNewPos);
	}
}

//HELPER FUNCTIONS

void Map::drawTo(RenderWindow& window) const
{
	window.draw(background);
}

Vector2f Map::getMapBorder() const
{
	return mapBorder;
}