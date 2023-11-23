#ifndef MAP_H
#define MAP_H

class Map : protected ResourceManager
{
private:
	Vector2f mapSize;
	Vector2f mapBorder;

public:
	Map()
	{

	};

	void movePlayer(Player* player, vector<Follower*>& npcList, Vector2f playerNewPos)
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

	void detectPlayer(Player* player, vector<Follower *> &npcList)
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
			playerNewPos = { playerOldPos.x, 500};
			movePlayer(player, npcList, playerNewPos);
		}

		if (playerOldPos.y < 500)
		{
			playerNewPos = { playerOldPos.x, mapBorder.y };
			movePlayer(player, npcList, playerNewPos);
		}
	}

	void setMapSize(Vector2f size)
	{
		mapSize = size;
		mapBorder = { mapSize.x - 700, mapSize.y - 500};
		cout << "Map Size: " << mapSize.x << " " << mapSize.y << endl;
		cout << "Map border: " << mapBorder.x << " " << mapBorder.y << endl;
	}

};

#endif