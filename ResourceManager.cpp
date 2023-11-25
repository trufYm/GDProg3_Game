#include <ResourceManager.hpp>


ResourceManager::ResourceManager()
{}

Texture ResourceManager::loadPlayerTexture()
{
	if (!playerTex.loadFromFile("donpersimmon.png"))
		cout << "Error loading player texture." << endl;

	return playerTex;
}

Texture ResourceManager::loadFollowerTexture()
{
	if (!followerTex.loadFromFile("akame(2).png"))
		cout << "Error loading follower texture" << endl;

	return followerTex;
}

Texture ResourceManager::loadBackgroundTexture()
{
	if (!backgroundTex.loadFromFile("grass-bg.jpg"))
		cout << "Error loading background." << endl;

	return backgroundTex;
}

/*Music ResourceManager::loadMusic()
{
	if (!music.openFromFile("holoBossaNova.wav"))
		cout << "Error loading music." << endl;

	return music;
}*/