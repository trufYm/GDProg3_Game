#include <ResourceManager.hpp>

ResourceManager::ResourceManager() {}

Texture ResourceManager::loadPlayerTexture(int currentEra)
{
	if (!playerTexCaveman.loadFromFile("player_caveman.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexAncient.loadFromFile("player_ancient.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexMedieval.loadFromFile("player_medieval.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexPreModern.loadFromFile("player_premodern.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexModern.loadFromFile("player_modern.png"))
		cout << "Error loading player texture" << endl;

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
	if (!resourceTexCaveman.loadFromFile("resource_caveman.png"))
		cout << "Error loading follower texture" << endl;

	if (!resourceTexAncient.loadFromFile("resource_ancient.png"))
		cout << "Error loading follower texture" << endl;

	if (!resourceTexMedieval.loadFromFile("resource_medieval.png"))
		cout << "Error loading follower texture" << endl;

	if (!resourceTexPreModern.loadFromFile("resource_premodern.png"))
		cout << "Error loading follower texture" << endl;

	if (!resourceTexModern.loadFromFile("resource_modern.png"))
		cout << "Error loading follower texture" << endl;

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
	if (!followerTexCaveman.loadFromFile("follower_caveman.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexAncient.loadFromFile("follower_ancient.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexMedieval.loadFromFile("follower_medieval.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexPreModern.loadFromFile("follower_premodern.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexModern.loadFromFile("follower_modern.png"))
		cout << "Error loading follower texture" << endl;

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
	if (!backgroundTex.loadFromFile("grass-bg.jpg"))
		cout << "Error loading background." << endl;

	return backgroundTex;
}

Font ResourceManager::loadFont()
{
	if (!font.loadFromFile("Caveman.ttf"))
		cout << "Error loading font." << endl;

	return font;
}

void ResourceManager::playMusic()
{
	if (!music.openFromFile("holoBossaNova.wav"))
		cout << "Error loading music." << endl;

	music.play();
}