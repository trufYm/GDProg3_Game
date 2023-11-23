#include <ResourceManager.hpp>
#include <Player.hpp>
#include <Follower.hpp>
#include <Map.hpp>
#include <GameController.hpp>

int main()
{
    GameController game;

    game.run();

    return 0;
}



//THE FOLLOWING CODE BLOCKS ARE KEPT FOR SYNTAX INCASE NEEDED IN FUTURE

/*THIS BLOCK DETECTS PLAYER AND FOLLOWER COLLISION ON 4 SIDES (FROM GAMECONTROLLER.HPP)
//Bottom Collision
if (playerBounds.top < npcBounds.top
    && playerBounds.top + playerBounds.height < npcBounds.top + npcBounds.height
    && playerBounds.left < npcBounds.left + npcBounds.width
    && playerBounds.left + playerBounds.width > npcBounds.left)
{
    npc.setCollided(true);
    player.setPosition(playerBounds.left, npcBounds.top - playerBounds.height);
}

//Top Collision
else if (playerBounds.top > npcBounds.top
    && playerBounds.top + playerBounds.height > npcBounds.top + npcBounds.height
    && playerBounds.left < npcBounds.left + npcBounds.width
    && playerBounds.left + playerBounds.width > npcBounds.left)
{
    npc.setCollided(true);
    player.setPosition(playerBounds.left, npcBounds.top + npcBounds.height);
}

//Right Collision
else if (playerBounds.left < npcBounds.left
    && playerBounds.left + playerBounds.width < npcBounds.left + npcBounds.width
    && playerBounds.top < npcBounds.top + npcBounds.height
    && playerBounds.top + playerBounds.height > npcBounds.top)
{
    npc.setCollided(true);
    player.setPosition(npcBounds.left - playerBounds.width, playerBounds.top);
}

//Left Collision
else if (playerBounds.left > npcBounds.left
    && playerBounds.left + playerBounds.width > npcBounds.left + npcBounds.width
    && playerBounds.top < npcBounds.top + npcBounds.height
    && playerBounds.top + playerBounds.height > npcBounds.top)
{
    npc.setCollided(true);
    player.setPosition(npcBounds.left + npcBounds.width, playerBounds.top);
}


//THIS BLOCK MOVES THE FOLLOWER SPRITE TOWARDS THE PLAYER SPRITE WHILE IMPLEMENTING FPS INDEPENDENT MOVEMENT
			//Player is to the left, same y level
			if (playerPos.x < currentPos.x && playerPos.y == currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * mult;
				movement.y = 0;

				rect.move(movement);
			}

			//Player is to the right, same y level
			else if (playerPos.x > currentPos.x && playerPos.y == currentPos.y)
			{
				movement.x += (player.getSpeed() * 0.60f) * dt * mult;
				movement.y = 0;

				rect.move(movement);
			}

			//Player is below, same x level
			else if (playerPos.x == currentPos.x && playerPos.y > currentPos.y)
			{
				movement.x = 0;
				movement.y += (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			//Player is above, same x level
			else if (playerPos.x == currentPos.x && playerPos.y < currentPos.y)
			{
				movement.x = 0;
				movement.y -= (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			//Player is to the top left
			else if (playerPos.x < currentPos.x && playerPos.y < currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * mult;
				movement.y -= (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			//Player is to the top right
			else if (playerPos.x > currentPos.x && playerPos.y < currentPos.y)
			{
				movement.x += (player.getSpeed() * 0.60f) * dt * mult;
				movement.y -= (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			//Player is to the bottom left
			else if (playerPos.x < currentPos.x && playerPos.y > currentPos.y)
			{
				movement.x -= (player.getSpeed() * 0.60f) * dt * mult;
				movement.y += (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			//Player is to the bottom right
			else if (playerPos.x > currentPos.x && playerPos.y > currentPos.y)
			{
				movement.x += (player.getSpeed() * 0.60f) * dt * mult;
				movement.y += (player.getSpeed() * 0.60f) * dt * mult;

				rect.move(movement);
			}

			else
				rect.move(0,0);
				break;
*/