#include <ResourceManager.hpp>


ResourceManager::ResourceManager()
{}

Texture ResourceManager::loadPlayerTexture()
{
	if (!playerTex.loadFromFile("donpersimmon.png"))
		cout << "Error loading player texture." << endl;

	return playerTex;
}

Texture ResourceManager::loadFollowerTexture(int currentEra)
{
	if (!followerTexCaveman.loadFromFile("resource_caveman.jpg"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexAncient.loadFromFile("resource_ancient.jpg"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexMedieval.loadFromFile("resource_medieval.jpg"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexPreModern.loadFromFile("resource_premodern.jpg"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexModern.loadFromFile("resource_modern.jpg"))
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

void ResourceManager::playMusic()
{
	if (!music.openFromFile("holoBossaNova.wav"))
		cout << "Error loading music." << endl;

	music.play();
}