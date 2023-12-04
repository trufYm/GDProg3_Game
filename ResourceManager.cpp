#include <ResourceManager.hpp>

Texture ResourceManager::backgroundTex,
		ResourceManager::followerTexCaveman, ResourceManager::followerTexAncient, ResourceManager::followerTexMedieval,
		ResourceManager::followerTexPreModern,ResourceManager::followerTexModern,
		ResourceManager::playerTexCaveman, ResourceManager::playerTexAncient, ResourceManager::playerTexMedieval,
		ResourceManager::playerTexPreModern, ResourceManager::playerTexModern,
		ResourceManager::resourceTexCaveman, ResourceManager::resourceTexAncient, ResourceManager::resourceTexMedieval,
		ResourceManager::resourceTexPreModern, ResourceManager::resourceTexModern,
		ResourceManager::wallTexCaveman, ResourceManager::wallTexAncient, ResourceManager::wallTexMedieval,
		ResourceManager::wallTexPreModern, ResourceManager::wallTexModern,
		ResourceManager::obstTexCaveman, ResourceManager::obstTexAncient, ResourceManager::obstTexMedieval,
		ResourceManager::obstTexPreModern, ResourceManager::obstTexModern;

Music ResourceManager::musicMenu, ResourceManager::musicCaveman,
		ResourceManager::musicAncient, ResourceManager::musicMedieval,
		ResourceManager::musicPreModern, ResourceManager::musicModern;

Music* ResourceManager::current;

Font ResourceManager::font;

SoundBuffer ResourceManager::bufferEraChange, ResourceManager::bufferCaveman,
			ResourceManager::bufferAncient, ResourceManager::bufferMedieval,
			ResourceManager::bufferPreModern, ResourceManager::bufferModern,
			ResourceManager::bufferEnd;

Sound ResourceManager::sound1, ResourceManager::sound2;

ResourceManager::ResourceManager() {}

void ResourceManager::loadAssets()
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
		cout << "Error loading resource texture" << endl;

	if (!resourceTexAncient.loadFromFile("Resources/resource_ancient.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexMedieval.loadFromFile("Resources/resource_medieval.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexPreModern.loadFromFile("Resources/resource_premodern.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexModern.loadFromFile("Resources/resource_modern.png"))
		cout << "Error loading resource texture" << endl;

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

	//Font file
	if (!font.loadFromFile("Resources/Caveman.ttf"))
		cout << "Error loading font." << endl;

	//Music files
	if (!musicMenu.openFromFile("Resources/music_menu.wav"))
		cout << "Error loading music." << endl;

	if (!musicCaveman.openFromFile("Resources/music_caveman.wav"))
		cout << "Error loading music." << endl;

	if (!musicAncient.openFromFile("Resources/music_ancient.wav"))
		cout << "Error loading music." << endl;

	if (!musicMedieval.openFromFile("Resources/music_medieval.wav"))
		cout << "Error loading music." << endl;

	if (!musicPreModern.openFromFile("Resources/music_premodern.wav"))
		cout << "Error loading music." << endl;

	if (!musicModern.openFromFile("Resources/music_modern.wav"))
		cout << "Error loading music." << endl;

	//Background file
	if (!backgroundTex.loadFromFile("Resources/grass-bg.jpg"))
		cout << "Error loading background." << endl;

	//Sound files
	if (!bufferEraChange.loadFromFile("Resources/sfx_eraChange.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferCaveman.loadFromFile("Resources/Dramatic_Caveman.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferAncient.loadFromFile("Resources/Dramatic_Ancient.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferMedieval.loadFromFile("Resources/Dramatic_Medieval.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferPreModern.loadFromFile("Resources/Dramatic_Premodern.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferModern.loadFromFile("Resources/Dramatic_Modern.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferEnd.loadFromFile("Resources/Dramatic_End.wav"))
		cout << "Error loading sound." << endl;
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

Texture ResourceManager::loadWallTexture(int currentEra)
{
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
	return backgroundTex;
}

Font ResourceManager::loadFont()
{
	return font;
}

void ResourceManager::playMusic(int choice)
{
	switch (choice)
	{
	case 1:
		current = &musicMenu;
		current->play();
		break;
	case 2:
		current->stop();
		current = &musicCaveman;
		current->play();
		break;
	case 3:
		current->stop();
		current = &musicAncient;
		current->play();
		break;
	case 4:
		current->stop();
		current = &musicMedieval;
		current->play();
		break;
	case 5:
		current->stop();
		current = &musicPreModern;
		current->setVolume(25.f);
		current->play();
		break;
	case 6:
		current->stop();
		current = &musicModern;
		current->setVolume(25.f);
		current->play();
	}
}

void ResourceManager::playEraChange(int choice)
{
	sound1.setBuffer(bufferEraChange);

	switch (choice)
	{
	case 1:
		sound2.setBuffer(bufferCaveman);
		sound2.play();
		break;
	case 2:
		sound2.setBuffer(bufferAncient);
		sound1.play();
		sound2.play();
		break;
	case 3:
		sound2.setBuffer(bufferMedieval);
		sound1.play();
		sound2.play();
		break;
	case 4:
		sound2.setBuffer(bufferPreModern);
		sound1.play();
		sound2.play();
		break;
	case 5:
		sound2.setBuffer(bufferModern);
		sound1.play();
		sound2.play();
		break;
	case 6:
		sound2.setBuffer(bufferEnd);
		sound2.play();
		break;
	}
}