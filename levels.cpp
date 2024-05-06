#include "levels.h"

beginnerGarden::beginnerGarden()
{
	// Set GameGrid
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			gameGrid[i][j] = 1; // Plantable
		}
	}
	//declare allowed plants
	myAllowedPlants = new int[1];
	myAllowedPlants[0] = 0;
	myNumAllowedPlants = 1;

	myTotalZombies = 1;
	myZombieTypes = new int[myTotalZombies] {1};

	myZombieFactory = new ZombieFactory(myTotalZombies, myZombieTypes);

}

levels::~levels()
{
	delete[] myAllowedPlants;
	delete[] myZombieTypes;
	delete myZombieFactory;
}

void beginnerGarden::createPlant(int thisplantCode, int x, int y)
{
	bool plantAllowed = false;

	// check if that plant is allowed (for further levels)
	plantAllowed = myPlantFactory.createPlant(thisplantCode, x, y);
	if (plantAllowed)
	{
		// gameGrid[y][x]=2; //Plant placed
	}
}

void beginnerGarden::drawBackground(sf::RenderWindow& window)
{
	textureBackground.loadFromFile("Images/Backgrounds/level1.png");
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);
	window.draw(spriteBackground);
}

void beginnerGarden::checkCollisions()
{
	// possible collision mechanism
	for (int i = 0; i < myTotalZombies; i++)
	{
		for (int j = 0; j < myNumAllowedPlants; j++)
		{
			if (myPlantFactory.myActivePlants[i]->myPlantCode == 0)
			{

			}
		}
	}
}