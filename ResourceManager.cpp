#include <ResourceManager.hpp>


ResourceManager::ResourceManager()
{
	if (!backgroundTex.loadFromFile("grass-bg.jpg"))
		cout << "Error loading background." << endl;

	if (!music.openFromFile("holoBossaNova.wav"))
		cout << "Error loading music file." << endl;

	if (!followerTex.loadFromFile("akame(2).png"))
		cout << "Error loading follower texture" << endl;

	if (!playerTex.loadFromFile("donpersimmon.png"))
		cout << "Error loading player texture." << endl;
}
