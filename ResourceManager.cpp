#include <ResourceManager.hpp>

ResourceManager::ResourceManager() 
{
	//Player Textures
	if (!playerTexCaveman.loadFromFile("Resources/player_caveman.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexAncient.loadFromFile("Resources/player_ancient.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexMedieval.loadFromFile("Resources/player_medieval.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexPreModern.loadFromFile("Resources/player_premodern.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexModern.loadFromFile("Resources/player_modern.png"))
		cout << "Error loading player texture" << endl;

	//Resource Textures
	if (!resourceTexCaveman.loadFromFile("Resources/resource_caveman.png"))
		cout << "Error loading follower texture" << endl;

	if (!resourceTexAncient.loadFromFile("Resources/resource_ancient.png"))
		cout << "Error loading follower texture" << endl;

	if (!resourceTexMedieval.loadFromFile("Resources/resource_medieval.png"))
		cout << "Error loading follower texture" << endl;

	if (!resourceTexPreModern.loadFromFile("Resources/resource_premodern.png"))
		cout << "Error loading follower texture" << endl;

	if (!resourceTexModern.loadFromFile("Resources/resource_modern.png"))
		cout << "Error loading follower texture" << endl;

	//Follower Textures
	if (!followerTexCaveman.loadFromFile("Resources/follower_caveman.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexAncient.loadFromFile("Resources/follower_ancient.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexMedieval.loadFromFile("Resources/follower_medieval.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexPreModern.loadFromFile("Resources/follower_premodern.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexModern.loadFromFile("Resources/follower_modern.png"))
		cout << "Error loading follower texture" << endl;

	

	//Font file
	if (!font.loadFromFile("Resources/Caveman.ttf"))
		cout << "Error loading font." << endl;

	//Music files
	if (!music.openFromFile("Resources/holoBossaNova.wav"))
		cout << "Error loading music." << endl;
}

Texture ResourceManager::loadPlayerTexture(int currentEra)
{
	switch (currentEra)
	{
	case 1:
		return playerTexCaveman;
		break;
	case 2:
		return playerTexAncient;
		break;
	case 3:
		return playerTexMedieval;
		break;
	case 4:
		return playerTexPreModern;
		break;
	case 5:
		return playerTexModern;
		break;
	}

	return playerTexCaveman;
}

Texture ResourceManager::loadResourceTexture(int currentEra)
{
	switch (currentEra)
	{
		case 1:
			return resourceTexCaveman;
			break;
		case 2:
			return resourceTexAncient;
			break;
		case 3:
			return resourceTexMedieval;
			break;
		case 4:
			return resourceTexPreModern;
			break;
		case 5:
			return resourceTexModern;
			break;
	}

	return resourceTexCaveman;
}

Texture ResourceManager::loadFollowerTexture(int currentEra)
{
	switch (currentEra)
	{
	case 1:
		return followerTexCaveman;
		break;
	case 2:
		return followerTexAncient;
		break;
	case 3:
		return followerTexMedieval;
		break;
	case 4:
		return followerTexPreModern;
		break;
	case 5:
		return followerTexModern;
		break;
	}

	return followerTexCaveman;
}

Texture ResourceManager::loadBackgroundTexture()
{
	//Putting this in constructor crashes game. Maybe size issue?
	if (!backgroundTex.loadFromFile("Resources/grass-bg.jpg"))
		cout << "Error loading background." << endl;

	return backgroundTex;
}

Font ResourceManager::loadFont()
{
	return font;
}

void ResourceManager::playMusic()
{
	music.play();
}