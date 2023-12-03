#include <ResourceManager.hpp>

ResourceManager::ResourceManager() {}

Texture ResourceManager::loadPlayerTexture(int currentEra)
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
	//Resource Textures
	if (!resourceTexCaveman.loadFromFile("Resources/resource_caveman.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexAncient.loadFromFile("Resources/resource_ancient.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexMedieval.loadFromFile("Resources/resource_medieval.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexPreModern.loadFromFile("Resources/resource_premodern.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexModern.loadFromFile("Resources/resource_modern.png"))
		cout << "Error loading resource texture" << endl;

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

Texture ResourceManager::loadWallTexture(int currentEra)
{
	//Wall Textures
	if (!wallTexCaveman.loadFromFile("Resources/wall_caveman.png"))
		cout << "Error loading wall texture" << endl;

	if (!wallTexAncient.loadFromFile("Resources/wall_ancient.png"))
		cout << "Error loading wall texture" << endl;

	if (!wallTexMedieval.loadFromFile("Resources/wall_medieval.png"))
		cout << "Error loading wall texture" << endl;

	if (!wallTexPreModern.loadFromFile("Resources/wall_premodern.png"))
		cout << "Error loading wall texture" << endl;

	if (!wallTexModern.loadFromFile("Resources/wall_modern.png"))
		cout << "Error loading wall texture" << endl;

	switch (currentEra)
	{
	case 1:
		return wallTexCaveman;
		break;
	case 2:
		return wallTexAncient;
		break;
	case 3:
		return wallTexMedieval;
		break;
	case 4:
		return wallTexPreModern;
		break;
	case 5:
		return wallTexModern;
		break;
	}

	return wallTexCaveman;
}

Texture ResourceManager::loadObstTexture(int currentEra)
{
	//Obstacle Textures
	if (!obstTexCaveman.loadFromFile("Resources/obst_caveman.png"))
		cout << "Error loading obst texture" << endl;

	if (!obstTexAncient.loadFromFile("Resources/obst_ancient.png"))
		cout << "Error loading obst texture" << endl;

	if (!obstTexMedieval.loadFromFile("Resources/obst_medieval.png"))
		cout << "Error loading obst texture" << endl;

	if (!obstTexPreModern.loadFromFile("Resources/obst_premodern.png"))
		cout << "Error loading obst texture" << endl;

	if (!obstTexModern.loadFromFile("Resources/obst_modern.png"))
		cout << "Error loading obst texture" << endl;

	switch (currentEra)
	{
	case 1:
		return obstTexCaveman;
		break;
	case 2:
		return obstTexAncient;
		break;
	case 3:
		return obstTexMedieval;
		break;
	case 4:
		return obstTexPreModern;
		break;
	case 5:
		return obstTexModern;
		break;
	}

	return obstTexCaveman;
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
	//Font file
	if (!font.loadFromFile("Resources/Caveman.ttf"))
		cout << "Error loading font." << endl;

	return font;
}

void ResourceManager::playMusic()
{
	//Music files
	if (!music.openFromFile("Resources/holoBossaNova.wav"))
		cout << "Error loading music." << endl;

	music.setVolume(25.f);
	music.play();
}

void ResourceManager::playEraChangeSound()
{
	//Putting this in constructor also crashes
	if (!buffer.loadFromFile("Resources/sfx_eraChange.wav"))
		cout << "Error loading sound." << endl;

	sound.setBuffer(buffer);

	sound.play();
}