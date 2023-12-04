#include <ResourceManager.hpp>

Texture ResourceManager::bgTexCaveman, ResourceManager::bgTexAncient, ResourceManager::bgTexMedieval,
		ResourceManager::bgTexPreModern, ResourceManager::bgTexModern, ResourceManager::bgTexEnd,
		ResourceManager::followerTexCaveman, ResourceManager::followerTexAncient, ResourceManager::followerTexMedieval,
		ResourceManager::followerTexPreModern,ResourceManager::followerTexModern,
		ResourceManager::playerTexCaveman, ResourceManager::playerTexAncient, ResourceManager::playerTexMedieval,
		ResourceManager::playerTexPreModern, ResourceManager::playerTexModern,
		ResourceManager::resourceTexCaveman, ResourceManager::resourceTexAncient, ResourceManager::resourceTexMedieval,
		ResourceManager::resourceTexPreModern, ResourceManager::resourceTexModern,
		ResourceManager::wallTexCaveman, ResourceManager::wallTexAncient, ResourceManager::wallTexMedieval,
		ResourceManager::wallTexPreModern, ResourceManager::wallTexModern,
		ResourceManager::obstTexCaveman, ResourceManager::obstTexAncient, ResourceManager::obstTexMedieval,
		ResourceManager::obstTexPreModern, ResourceManager::obstTexModern,
		ResourceManager::rocketTex;

Music ResourceManager::musicMenu, ResourceManager::musicCaveman,
		ResourceManager::musicAncient, ResourceManager::musicMedieval,
		ResourceManager::musicPreModern, ResourceManager::musicModern;

Music* ResourceManager::current;

Font ResourceManager::font;

SoundBuffer ResourceManager::bufferEraChange, ResourceManager::bufferCaveman,
			ResourceManager::bufferAncient, ResourceManager::bufferMedieval,
			ResourceManager::bufferPreModern, ResourceManager::bufferModern,
			ResourceManager::bufferEnd, ResourceManager::bufferFollower1,
			ResourceManager::bufferFollower2, ResourceManager::bufferFollower3,
			ResourceManager::bufferFollower4, ResourceManager::bufferFollower5,
			ResourceManager::bufferFollower6, ResourceManager::bufferFollower7;

Sound ResourceManager::sound1, ResourceManager::sound2, ResourceManager::sound3;

ResourceManager::ResourceManager() {}

void ResourceManager::loadAssets()
{
	//Player Textures
	if (!playerTexCaveman.loadFromFile("Resources/Sprites/player_caveman.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexAncient.loadFromFile("Resources/Sprites/player_ancient.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexMedieval.loadFromFile("Resources/Sprites/player_medieval.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexPreModern.loadFromFile("Resources/Sprites/player_premodern.png"))
		cout << "Error loading player texture" << endl;

	if (!playerTexModern.loadFromFile("Resources/Sprites/player_modern.png"))
		cout << "Error loading player texture" << endl;

	//Resource Textures
	if (!resourceTexCaveman.loadFromFile("Resources/Sprites/resource_caveman.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexAncient.loadFromFile("Resources/Sprites/resource_ancient.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexMedieval.loadFromFile("Resources/Sprites/resource_medieval.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexPreModern.loadFromFile("Resources/Sprites/resource_premodern.png"))
		cout << "Error loading resource texture" << endl;

	if (!resourceTexModern.loadFromFile("Resources/Sprites/resource_modern.png"))
		cout << "Error loading resource texture" << endl;

	//Follower Textures
	if (!followerTexCaveman.loadFromFile("Resources/Sprites/follower_caveman.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexAncient.loadFromFile("Resources/Sprites/follower_ancient.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexMedieval.loadFromFile("Resources/Sprites/follower_medieval.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexPreModern.loadFromFile("Resources/Sprites/follower_premodern.png"))
		cout << "Error loading follower texture" << endl;

	if (!followerTexModern.loadFromFile("Resources/Sprites/follower_modern.png"))
		cout << "Error loading follower texture" << endl;

	//Wall Textures
	if (!wallTexCaveman.loadFromFile("Resources/Sprites/wall_caveman.png"))
		cout << "Error loading wall texture" << endl;

	if (!wallTexAncient.loadFromFile("Resources/Sprites/wall_ancient.png"))
		cout << "Error loading wall texture" << endl;

	if (!wallTexMedieval.loadFromFile("Resources/Sprites/wall_medieval.png"))
		cout << "Error loading wall texture" << endl;

	if (!wallTexPreModern.loadFromFile("Resources/Sprites/wall_premodern.png"))
		cout << "Error loading wall texture" << endl;

	if (!wallTexModern.loadFromFile("Resources/Sprites/wall_modern.png"))
		cout << "Error loading wall texture" << endl;

	//Obstacle Textures
	if (!obstTexCaveman.loadFromFile("Resources/Sprites/obst_caveman.png"))
		cout << "Error loading obst texture" << endl;

	if (!obstTexAncient.loadFromFile("Resources/Sprites/obst_ancient.png"))
		cout << "Error loading obst texture" << endl;

	if (!obstTexMedieval.loadFromFile("Resources/Sprites/obst_medieval.png"))
		cout << "Error loading obst texture" << endl;

	if (!obstTexPreModern.loadFromFile("Resources/Sprites/obst_premodern.png"))
		cout << "Error loading obst texture" << endl;

	if (!obstTexModern.loadFromFile("Resources/Sprites/obst_modern.png"))
		cout << "Error loading obst texture" << endl;

	//Font file
	if (!font.loadFromFile("Resources/Caveman.ttf"))
		cout << "Error loading font." << endl;

	//Music files
	if (!musicMenu.openFromFile("Resources/.wav/music_menu.wav"))
		cout << "Error loading music." << endl;

	if (!musicCaveman.openFromFile("Resources/.wav/music_caveman.wav"))
		cout << "Error loading music." << endl;

	if (!musicAncient.openFromFile("Resources/.wav/music_ancient.wav"))
		cout << "Error loading music." << endl;

	if (!musicMedieval.openFromFile("Resources/.wav/music_medieval.wav"))
		cout << "Error loading music." << endl;

	if (!musicPreModern.openFromFile("Resources/.wav/music_premodern.wav"))
		cout << "Error loading music." << endl;

	if (!musicModern.openFromFile("Resources/.wav/music_modern.wav"))
		cout << "Error loading music." << endl;

	//Background file
	if (!bgTexCaveman.loadFromFile("Resources/Backgrounds/bg_caveman.png"))
		cout << "Error loading background." << endl;

	if (!bgTexAncient.loadFromFile("Resources/Backgrounds/bg_ancient.png"))
		cout << "Error loading background." << endl;

	if (!bgTexMedieval.loadFromFile("Resources/Backgrounds/bg_medieval.png"))
		cout << "Error loading background." << endl;

	if (!bgTexPreModern.loadFromFile("Resources/Backgrounds/bg_premodern.png"))
		cout << "Error loading background." << endl;

	if (!bgTexModern.loadFromFile("Resources/Backgrounds/bg_modern.png"))
		cout << "Error loading background." << endl;

	if (!bgTexEnd.loadFromFile("Resources/Backgrounds/bg_end.png"))
		cout << "Error loading background." << endl;

	//Sound files
	if (!bufferEraChange.loadFromFile("Resources/.wav/sfx_eraChange.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferCaveman.loadFromFile("Resources/.wav/Dramatic_Caveman.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferAncient.loadFromFile("Resources/.wav/Dramatic_Ancient.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferMedieval.loadFromFile("Resources/.wav/Dramatic_Medieval.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferPreModern.loadFromFile("Resources/.wav/Dramatic_Premodern.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferModern.loadFromFile("Resources/.wav/Dramatic_Modern.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferEnd.loadFromFile("Resources/.wav/Dramatic_End.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferFollower1.loadFromFile("Resources/.wav/follower1.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferFollower2.loadFromFile("Resources/.wav/follower2.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferFollower3.loadFromFile("Resources/.wav/follower3.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferFollower4.loadFromFile("Resources/.wav/follower4.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferFollower5.loadFromFile("Resources/.wav/follower5.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferFollower6.loadFromFile("Resources/.wav/follower6.wav"))
		cout << "Error loading sound." << endl;

	if (!bufferFollower7.loadFromFile("Resources/.wav/follower7.wav"))
		cout << "Error loading sound." << endl;

	//Rocket
	if (!rocketTex.loadFromFile("Resources/Sprites/rocket.png"))
		cout << "Error loading rocket." << endl;
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

Texture ResourceManager::loadBackgroundTexture(int currentEra)
{
	switch (currentEra)
	{
	case 1:
		return bgTexCaveman;
		break;
	case 2:
		return bgTexAncient;
		break;
	case 3:
		return bgTexMedieval;
		break;
	case 4:
		return bgTexPreModern;
		break;
	case 5:
		return bgTexModern;
		break;
	case 6:
		return bgTexEnd;
		break;
	}

	return bgTexCaveman;
}

Texture ResourceManager::loadRocket()
{
	return rocketTex;
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

void ResourceManager::pauseMusic()
{
	current->pause();
}

void ResourceManager::playFollowerNoise()
{
	int count = rand() % 7;

	switch (count)
	{
	case 0:
		sound3.setBuffer(bufferFollower1);
		break;
	case 1:
		sound3.setBuffer(bufferFollower2);
		break;
	case 2:
		sound3.setBuffer(bufferFollower3);
		break;
	case 3:
		sound3.setBuffer(bufferFollower4);
		break;
	case 4:
		sound3.setBuffer(bufferFollower5);
		break;
	case 5:
		sound3.setBuffer(bufferFollower6);
		break;
	case 6:
		sound3.setBuffer(bufferFollower7);
		break;
	}

	sound3.play();
}