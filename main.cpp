#include <Follower.hpp>
#include <Player.hpp>
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
    //player.setPosition(playerBounds.left, npcBounds.top - playerBounds.height);
}

//Top Collision
else if (playerBounds.top > npcBounds.top
    && playerBounds.top + playerBounds.height > npcBounds.top + npcBounds.height
    && playerBounds.left < npcBounds.left + npcBounds.width
    && playerBounds.left + playerBounds.width > npcBounds.left)
{
    npc.setCollided(true);
    //player.setPosition(playerBounds.left, npcBounds.top + npcBounds.height);
}

//Right Collision
else if (playerBounds.left < npcBounds.left
    && playerBounds.left + playerBounds.width < npcBounds.left + npcBounds.width
    && playerBounds.top < npcBounds.top + npcBounds.height
    && playerBounds.top + playerBounds.height > npcBounds.top)
{
    npc.setCollided(true);
    //player.setPosition(npcBounds.left - playerBounds.width, playerBounds.top);
}

//Left Collision
else if (playerBounds.left > npcBounds.left
    && playerBounds.left + playerBounds.width > npcBounds.left + npcBounds.width
    && playerBounds.top < npcBounds.top + npcBounds.height
    && playerBounds.top + playerBounds.height > npcBounds.top)
{
    npc.setCollided(true);
    //player.setPosition(npcBounds.left + npcBounds.width, playerBounds.top);
}
*/